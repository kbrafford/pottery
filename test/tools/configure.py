#!/usr/bin/env python3

# MIT License
#
# Copyright (c) 2020 Nicholas Fraser
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# This is the buildsystem configuration tool for the Pottery test suite. It
# tests the compiler for support for various flags and features and generates a
#
# It can be run with a GCC-style compiler or with MSVC. To run it with MSVC,
# you must first have the Visual Studio build tools on your path. This means
# you need to either open a Visual Studio Build Tools command prompt, or source
# vsvarsall.bat for some version of the Visual Studio Build Tools.
# ninja build file to build the unit test suite in a variety of configurations.

import shutil, os, sys, subprocess
from os import path

globalbuild = path.join("test", "build")
os.makedirs(globalbuild, exist_ok=True)



###################################################
# Determine Compiler
###################################################

# The following compilers currently work with Pottery's unit test suite and are
# detected by this script:
#
# GCC
# Clang
# MSVC
# TinyCC
# cproc
# chibicc
#
# The following compilers don't currently work but we have some code to detect
# them and try to make them work anyway
#
# 8cc
# cparser

cc = None
compiler = "unknown"

if os.getenv("CC"):
    cc = os.getenv("CC")
elif shutil.which("cl.exe"):
    cc = "cl"
else:
    cc = "cc"

if not shutil.which(cc):
    raise Exception("Compiler cannot be found!")

if cc.lower() == "cl" or cc.lower() == "cl.exe":
    compiler = "MSVC"
elif cc.endswith("cproc"):
    compiler = "cproc"
elif cc.endswith("chibicc"):
    compiler = "chibicc"
elif cc.endswith("8cc"):
    compiler = "8cc"
else:
    # try --version
    ret = subprocess.run([cc, "--version"], universal_newlines=True,
            capture_output=True)
    if ret.returncode == 0:
        if ret.stdout.startswith("clang "):
            compiler = "Clang"
        elif ret.stdout.startswith("cparser "):
            compiler = "cparser"
        elif "(GCC)" in ret.stdout:
            compiler = "GCC"
    else:
        # try -v
        ret = subprocess.run([cc, "-v"], universal_newlines=True,
                capture_output=True)
        if ret.returncode == 0:
            if ret.stdout.startswith("tcc "):
                compiler = "TinyCC"

print("Using " + compiler + " compiler with executable: " + cc)

if compiler == "MSVC":
    obj_extension = ".obj"
    exe_extension = ".exe"
else:
    obj_extension = ".o"
    exe_extension = ""

ccache = shutil.which("ccache") and os.getenv("CCACHE_DISABLE") != "true" and os.getenv("CI") is None



###################################################
# Compiler Probing
###################################################

config = {
    "flags": {},
}

flagtest_src = path.join(globalbuild, "flagtest.c")
flagtest_exe = path.join(globalbuild, "flagtest" + exe_extension)
with open(flagtest_src, "w") as out:
    out.write("""
// disable C++ on versions of GCC < 5 since they don't have full C++11 support
// (e.g. std::is_trivially_copyable<>).
#ifdef __GNUC__
    #if __GNUC__ < 6
        #error
    #endif
#endif

int main(int argc, char** argv) {
    // array dereference to test for the existence of
    // sanitizer libs when using -fsanitize (libubsan)
    return argv[argc - 1] == 0;
}
""")

def checkFlags(flags):
    if isinstance(flags, str):
        flags = [flags,]

    configArg = "|".join(flags)
    if configArg in config["flags"]:
        return config["flags"][configArg]
    print("Testing flag(s): " + " ".join(flags) + " ... ", end="")
    sys.stdout.flush()

    if compiler == "MSVC":
        cmd = [cc, "/W4", "/WX"] + flags + [flagtest_src, "/Fe" + flagtest_exe]
    else:
        cmd = [cc, "-Wall", "-Wextra", "-Wpedantic", "-Werror"] + flags + [flagtest_src, "-o", flagtest_exe]
    #print(" ".join(cmd))
    ret = subprocess.run(cmd, universal_newlines=True,
            capture_output=True)

    if ret.returncode == 0:
        print("Supported.")
        supported = True
    else:
        print("Not supported.")
        supported = False
    config["flags"][configArg] = supported
    return supported

def flagsIfSupported(flags):
    if checkFlags(flags):
        if isinstance(flags, str):
            return [flags]
        return flags
    return []

# We use -Og for all debug builds if we have it, but ONLY under GCC. It can
# sometimes improve warnings, and things run a lot faster especially under
# Valgrind, but Clang stupidly maps it to -O1 which has some optimizations
# that break debugging!
hasOg = False
print("Testing flag(s): -Og ... ", end="")
sys.stdout.flush()
if compiler == "MSVC":
    print("Not supported.")
elif compiler == "GCC":
    hasOg = True
    print("Supported.")
else:
    print("May be supported but we won't use it.")



###################################################
# Common Flags
###################################################

defaultCPPFlags = []
defaultLDFlags = []

if compiler == "MSVC":
    pdb = path.join(globalbuild, "pottery_unit.pdb")
    defaultCPPFlags += [
        "/W4", "/WX",
        # debug to PDB with synchronous writes since we're doing parallel builds
        # TODO currently not working properly, linker doesn't support this
        # option so it tries to read while it's still being written in parallel
        # builds and throws "PDB not found" warnings
        "/Zi", "/FS", "/Fd" + pdb
    ]
    defaultLDFlags += [
        "/DEBUG"
    ]
else:
    defaultCPPFlags += [
        "-Wall",
        "-g",
    ]

    # We don't treat warnings as errors with cparser because it warns about
    # lots of stuff that is silenced by other compilers, especially when
    # expanded from macros
    if compiler != "cparser":
        defaultCPPFlags.append("-Werror")

defaultCPPFlags += [
    "-Iinclude", "-Iexamples", "-Itest/src",
    "-DPOTTERY_UNIT_TEST",
    "-Dassert=pottery_assert", # TODO get rid of this hack
]

# optimization
if compiler == "MSVC":
    debugFlags = ["/Od", "/MDd"]
    releaseFlags = ["/O2", "/MD"]
else:
    debugFlags = [hasOg and "-Og" or "-O0"]
    releaseFlags = ["-O2"]
debugFlags.append("-DDEBUG")
releaseFlags.append("-DNDEBUG")

# flags for specifying source language
if compiler == "MSVC":
    defaultCFlags = ["/TC"]
    defaultCXXFlags = ["/TP", "/EHsc"]
else:
    defaultCFlags = []
    defaultCXXFlags = [
        "-x", "c++", "-std=c++11",
        "-Wmissing-declarations",
    ]

defaultCXXFlags += ["-Ibindings/cxx/include"]



###################################################
# Variable Flags and other supported features
###################################################

# Always stop on the first error, since it's usually large and usually causes a
# wall of text of other errors
defaultCPPFlags += flagsIfSupported("-Wfatal-errors")

compilerSupportsCXX = False

if compiler == "MSVC":
    compilerSupportsCXX = True

if compiler != "MSVC":

    # TinyCC silently ignores this
    if compiler != "TinyCC":
        # A bit of duplication here: with Clang we prefer libc++ instead of
        # libstdc++, but we'll use either if they work
        if compiler == "Clang":
            if checkFlags(["-x", "c++", "-Wl,-lc++"]):
                compilerSupportsCXX = True
                defaultLDFlags.append("-lc++")
            elif checkFlags(["-x", "c++", "-Wl,-lstdc++"]):
                compilerSupportsCXX = True
                defaultLDFlags.append("-lstdc++")
        else:
            if checkFlags(["-x", "c++", "-Wl,-lstdc++"]):
                compilerSupportsCXX = True
                defaultLDFlags.append("-lstdc++")
            elif checkFlags(["-x", "c++", "-Wl,-lc++"]):
                compilerSupportsCXX = True
                defaultLDFlags.append("-lc++")

    if not os.getenv("CI"):
        # we have to force color diagnostics to get color output from ninja
        # (ninja will strip the colors if it's being piped)
        if checkFlags("-fdiagnostics-color=always"):
            defaultCPPFlags.append("-fdiagnostics-color=always")
        elif checkFlags("-fcolor-diagnostics=always"):
            defaultCPPFlags.append("-color-diagnostics=always")

    if checkFlags("-Wstrict-aliasing=3"):
        defaultCPPFlags.append("-Wstrict-aliasing=3")
    elif checkFlags("-Wstrict-aliasing=2"):
        defaultCPPFlags.append("-Wstrict-aliasing=2")
    elif checkFlags("-Wstrict-aliasing"):
        defaultCPPFlags.append("-Wstrict-aliasing")

    extraFlags = [
        "-Wextra",
        "-Wpedantic",
        "-Wmissing-variable-declarations",
        "-Wfloat-conversion",
        "-Wconversion",
        "-Wundef",
        "-Wshadow",
        "-Wcast-qual",
        "-fPIC",
        "-fstrict-aliasing",
    ]
    for flag in extraFlags:
        defaultCPPFlags += flagsIfSupported(flag)

    if checkFlags(["-x", "c++", "-Wzero-as-null-pointer-constant"]):
        # TODO this isn't working in GCC or Clang
        defaultCXXFlags.append("-Wzero-as-null-pointer-constant")

    # TODO we need a build without this, partly for valgrind and partly because
    # this breaks malloc_usable_size
#    if checkFlags("-fsanitize=address"):
#        defaultCPPFlags.append("-fsanitize=address");
#        defaultLDFlags.append("-fsanitize=address");

    hasDeps = checkFlags("-MD")

    defaultCFlags += flagsIfSupported("-Wmissing-prototypes")
    defaultCFlags += flagsIfSupported("-Wc++-compat")

# Many C compilers don't support something like __attribute__((constructor)) so
# we need to register unit tests manually. This adds a build step that pulls
# unit test registration functions out of all the compiled object files.
generateUnitTestRegistrations = not compiler == "Clang" and not compiler == "GCC" and not compiler == "MSVC"
if generateUnitTestRegistrations:
    defaultCPPFlags.append("-DPOTTERY_MANUAL_UNIT_TEST_REGISTRATION")



###################################################
# Build configuration
###################################################

builds = {}

class Build:
    def __init__(self, name, cppflags, cflags, cxxflags, ldflags):
        self.name = name
        self.cppflags = cppflags
        self.cflags = cflags
        self.cxxflags = cxxflags
        self.ldflags = ldflags
        self.run_wrapper = None
        self.exclude = False

def addBuild(name, cppflags = defaultCPPFlags, cflags = defaultCFlags, cxxflags = defaultCXXFlags, ldflags = defaultLDFlags):
    builds[name] = Build(name, cppflags, cflags, cxxflags, ldflags)

def addDebugReleaseBuilds(name, cppflags = defaultCPPFlags, cflags = defaultCFlags, cxxflags = defaultCXXFlags, ldflags = defaultLDFlags):
    addBuild(name + "-debug", cppflags + debugFlags, cflags, cxxflags, ldflags)
    addBuild(name + "-release", cppflags + releaseFlags, cflags, cxxflags, ldflags)

addDebugReleaseBuilds('default')

# MSVC variants
if compiler == "MSVC":

    # Link-time optimization
    addDebugReleaseBuilds('lto', defaultCPPFlags + ["/GL"], defaultCFlags, defaultCXXFlags, defaultLDFlags + ["/LTCG"])

    # All files as C++
    addDebugReleaseBuilds('c++', defaultCPPFlags + defaultCXXFlags, [], [])
    if checkFlags(defaultCXXFlags + ["/std:c++17"]):
        addDebugReleaseBuilds('c++17', defaultCPPFlags + defaultCXXFlags + ["/std:c++17"], [], [])
    cxxFlagsNoExcept = [x for x in defaultCXXFlags if x != "/EHsc"]
    addDebugReleaseBuilds('c++-nounwind', defaultCPPFlags + cxxFlagsNoExcept, [], [])

    # Managed C++
    if checkFlags(cxxFlagsNoExcept + ["/clr"]):
        addDebugReleaseBuilds('c++-clr', defaultCPPFlags + cxxFlagsNoExcept + ["/clr"], [], []) # implies /EHa

# TinyCC variants
if compiler == "TinyCC":
    # TinyCC has a bounds-checking feature but it appears quite buggy:
    #
    #     https://bellard.org/tcc/tcc-doc.html#Bounds
    #
    # I've tried debugging this and it's getting confused on some basic code
    # so I don't think there's anything wrong with Pottery (and besides,
    # Pottery works fine under ASAN and Valgrind.) Still, I'd like to get this
    # working at some point.
    #
    #addDebugReleaseBuilds('bounds', defaultCPPFlags + ['-b'], defaultCFlags, defaultCXXFlags, defaultLDFlags + ['-b'])
    pass

# GNU-style variants
#
# We have to disable variant builds under some compilers:
#
# - TinyCC silently ignores most of these compiler options which leads to all
#   sorts of build failures
#
# - cproc supports _Alignof/_Alignas even in C99 mode but it doesn't provide us
#   a way to detect it so we fail under -std=c99 and can't work around it
#
if compiler != "TinyCC" and compiler != "cproc" and compiler != "MSVC":

    # C builds

    # Pottery is really C11 code with C++ support. We need lots of compiler
    # extensions to build as ANSI C. We technically only support gnu89 so we
    # need to disable pedantic C89 warnings.
    gnu89flags = ["-std=gnu89", "-Wno-pedantic"]
    if checkFlags(gnu89flags):
        addDebugReleaseBuilds('gnu89', defaultCPPFlags, defaultCFlags + gnu89flags)

    if checkFlags("-std=c11"):
        addDebugReleaseBuilds('c11', defaultCPPFlags, defaultCFlags + ["-std=c11"])

    # We support -std=c99 on GNUC-style compilers because they have
    # platform-specific alignment specifiers (e.g. __attribute__((__aligned__()))).
    addDebugReleaseBuilds('c99', defaultCPPFlags, defaultCFlags + ["-std=c99"])

    # Link-time optimization
    if checkFlags("-flto"):
        ltoFlags = defaultCPPFlags + ["-flto"]
        ltoDebugFlags = ltoFlags + debugFlags
        ltoReleaseFlags = ltoFlags + [x.replace("-O2", "-O3") for x in releaseFlags]
        addBuild('lto-debug', defaultCPPFlags + ltoDebugFlags, defaultCFlags, defaultCXXFlags,
                defaultCPPFlags + ltoDebugFlags + defaultLDFlags)
        addBuild('lto-release', defaultCPPFlags + ltoReleaseFlags, defaultCFlags, defaultCXXFlags,
                defaultCPPFlags + ltoReleaseFlags + defaultLDFlags)

    # C++ builds

    if compilerSupportsCXX:
        cxxFlagsNoVersion = [x for x in defaultCXXFlags if x != "-std=c++11"]

        # C11, with C++ files as C++17
        if checkFlags(["-x", "c++", "-std=c++17"]) and checkFlags("-std=c11"):
            addDebugReleaseBuilds('c11-c++17', defaultCPPFlags, defaultCFlags + ["-std=c11"], cxxFlagsNoVersion + ["-std=gnu++11"])

        # All files as C++
        addDebugReleaseBuilds('gnu++11', defaultCPPFlags + cxxFlagsNoVersion + ["-std=gnu++11"], [], [])
        if checkFlags(["-x", "c++", "-std=c++17"]):
            addDebugReleaseBuilds('c++17', defaultCPPFlags + cxxFlagsNoVersion + ["-std=c++17"], [], [])
        if checkFlags(["-x", "c++", "-std=c++17", "-fno-exceptions"]):
            addDebugReleaseBuilds('c++17-noexcept', defaultCPPFlags + cxxFlagsNoVersion + ["-std=c++17", "-fno-exceptions"], [], [])



###################################################
# Ninja generation
###################################################

srcs = []

for root, dirs, files in os.walk("test/src"):
    for name in files:
        # skip any benchmark files
        if "benchmark" in name:
            continue
        if name.endswith(".c") or name.endswith(".cxx"):
            srcs.append(os.path.join(root, name))

ninja = path.join(globalbuild, "build.ninja")
with open(ninja, "w") as out:
    out.write("# This file is auto-generated.\n")
    out.write("# Do not edit it; your changes will be erased.\n")
    out.write("\n")

    # 1.3 for GCC deps
    out.write("ninja_required_version = 1.3\n")
    out.write("\n")

    # run
    out.write("run_wrapper =\n")
    out.write("rule run\n")
    out.write(" command = $run_wrapper$in\n")
    out.write("\n")

    out.write("rule compile\n")
    if compiler == "MSVC":
        out.write(" command = " + cc + " /showIncludes $flags /c $in /Fo$out\n")
        out.write(" deps = msvc\n")
    else:
        out.write(" command = ")
        if ccache:
            out.write("ccache ")
        out.write(cc + " ")
        if hasDeps:
            out.write("-MD -MF $out.d ")
        out.write("$flags -c $in -o $out\n")
        out.write(" deps = gcc\n")
        out.write(" depfile = $out.d\n")
    out.write("\n")

    if generateUnitTestRegistrations:
        out.write("rule generate_unit_test_registrations\n")
        out.write(" command = test/tools/generate-unit-test-registrations.sh $out $in\n")

    out.write("rule link\n")
    if compiler == "MSVC":
        out.write(" command = link @$out.rsp /OUT:$out\n")
        out.write(" rspfile = $out.rsp\n")
        out.write(" rspfile_content = $flags $in\n")
    else:
        out.write(" command = " + cc + " $flags $in -o $out\n")
    out.write("\n")

    for buildname in sorted(builds.keys()):
        build = builds[buildname]
        buildfolder = path.join(globalbuild, buildname)
        cppflags = build.cppflags
        cflags = build.cflags
        cxxflags = build.cxxflags
        ldflags = build.ldflags
        objs = []

        for src in srcs:
            if src.endswith(".cxx"):
                if not compilerSupportsCXX:
                    continue
                flags = cppflags + cxxflags
                objname = src[:-4]
            else:
                flags = cppflags + cflags
                objname = src[:-2]

            obj = path.join(buildfolder, "objs", objname + obj_extension)
            objs.append(obj)
            out.write("build " + obj + ": compile " + src + "\n")
            out.write(" flags = " + " ".join(flags) + "\n")

        if generateUnitTestRegistrations:
            src = path.join(buildfolder, "pottery_register_unit_tests.c")
            obj = path.join(buildfolder, "objs", "pottery_register_unit_tests.o")
            out.write("build " + src + ": generate_unit_test_registrations " +
                    " ".join(objs) + "\n");
            out.write("build " + obj + ": compile " + src + "\n")
            out.write(" flags = " + " ".join(cppflags + cflags) + "\n")
            objs.append(obj)

        runner = path.join(buildfolder, "runner") + exe_extension

        out.write("build " + runner + ": link " + " ".join(objs) + "\n")
        out.write(" flags = " + " ".join(ldflags) + "\n")

        # You can omit "run-" in front of any build to just build it without
        # running it. This lets you run it some other way (e.g. under gdb,
        # with/without Valgrind, etc.)
        out.write("build " + buildname + ": phony " + runner + "\n\n")

        out.write("build run-" + buildname + ": run " + runner + "\n")
        if build.run_wrapper:
            run_wrapper = build.run_wrapper
            out.write(" run_wrapper = " + run_wrapper + " ")
            if run_wrapper == "valgrind":
                out.write("--leak-check=full --error-exitcode=1 ")
                out.write("--suppressions=tools/valgrind-suppressions ")
                out.write("--show-leak-kinds=all --errors-for-leak-kinds=all ")
        out.write("\n")

    out.write("default run-default-debug\n")
    out.write("build default: phony run-default-debug\n")
    out.write("\n")

    out.write("build all: phony")
    for build in sorted(builds.keys()):
        if not builds[build].exclude:
            out.write(" run-")
            out.write(build)
    out.write("\n")

print("Generated " + ninja)

with open(path.join(globalbuild, "help"), "w") as out:
    out.write("\n")
    out.write("Available targets:\n")
    out.write("\n")
    out.write("    (default)\n")
    out.write("    more\n")
    out.write("    all\n")
    out.write("    clean\n")
    out.write("    help\n")
    out.write("\n")
    for build in sorted(builds.keys()):
        out.write("    run-" + build + "\n")
    out.close()
