This is the Pottery test suite.

You don't need to build or run the tests to use Pottery. It's a header-only library. Just put it on your include path.

## Scripts

Scripts should be run from the root of the repository. The tools under `test/tools/` are not meant to be run directly; they are used by the scripts below.

The following scripts are available for UNIX systems:

- `test/unit.sh` - Build and run unit tests.
- `test/fuzz.sh` - Build a fuzz testing harness for a particular algorithm or container and run it under american fuzzy lop.
- `test/scan-build.sh` - Run Clang Static Analyzer on the unit test suite.
- `test/clean.sh` - Clean the build folder.

The following scripts are available for Windows:

- `test\unit.bat` - Build and run a particular configuration of unit tests with the Visual Studio C compiler. Pass a configuration to run or pass "all" to run all configurations.
- `test\clean.bat` - Clean the build folder.

## Unit Tests

The unit test suite requires [**Python 3**](https://www.python.org/) and [**Ninja**](https://ninja-build.org/) on your `PATH`. On Windows, Ninja comes with the latest Visual Studio Build Tools but you'll need to [install Python 3](https://www.python.org/downloads/windows/). Make sure to check the box to add it to your PATH during installation. On Linux, Python 3 is probably already installed and you can find Ninja in your distribution's package manager.

The unit test suite is run with `test/unit.sh` or `test\unit.bat`. Set "CC" to choose a compiler or leave it unset to use `cc`. Pass a configuration to run or pass "all" to run all configurations. For example:

```sh
CC=clang test/unit.sh all
```

The unit test suite supports various configurations. For example "c++17" compiles all source files as C++17 and "gnu89" compiles all source files as gnu89. Prefix the configuration with "run-" to run the tests, and suffix it with "-debug" or "-release" to choose debug or release builds. Pass multiple commands to run all of them. For example:

```sh
test/unit.sh run-{c++17,gnu89}-{debug,release}
```

The unit test suite also includes all examples in the `examples/` folder as well as all fuzz tests in the `test/src/fuzz/` folder. When building the examples, Pottery converts the `main()` function into a unit test, disables `printf()`, and disables a number of warnings. This keeps the examples simple and runnable as standalone binaries.

The unit test suite is itself made up of a bunch of test templates. For example the template [`test_pottery_array_ufo.t.h`](test/src/pottery/unit/test_pottery_array_ufo.t.h) tests a generalized array of `ufo_t`, a common test object. This template is instantiated to test vector, deque, etc.

## Fuzz Tests

Pottery's algorithms and containers are fuzz tested. These can be run with [american fuzzy lop](https://lcamtuf.coredump.cx/afl/) to find bugs. They are also run as part of the unit test suite.

A fuzz test takes a byte stream as input and interprets it as a series of commands to perform on a data structure. This results in a random series of insertions and deletions that can find bugs. The test also builds up a shadow data structure that repeats the commands performed on the real one. After each command, it checks the invariants of the data structure (such as tree balance) and checks that the data matches the shadow. The general idea is described by this article: [How to Fuzz an ADT Implementation](https://blog.regehr.org/archives/896).

When run as part of the unit test suite, the fuzz testers test a random chunk of bytes over a number of rounds. This means a unit test failure might be sporadic. The random seed (and glibc version if applicable) is printed to the command line when it starts so you can reproduce such failures. If you get a fuzz failure when running unit tests, record the seed and commit hash and file a bug report!

To fuzz test with american fuzzy lop, use `test/fuzz.sh` and choose a container or algorithm to test. Run it without arguments to get a list. You'll also need to do a bit of system configuration to make AFL happy on your system. The below assumes your system is Linux:

```sh
echo core | sudo tee /proc/sys/kernel/core_pattern"
cd /sys/devices/system/cpu
echo performance | sudo tee cpu*/cpufreq/scaling_governor # echo ondemand to undo this later
test/fuzz.sh test/build/afl/test_pottery_fuzz_vector
```

The test script prints out the afl command it uses so you can run it yourself if you want to configure it more (for example if you want to parallelize it.)

It can take days to sufficiently test a data structure so only do this if you really want to double check it (or if you just want to help me out in testing.) If you find anything please file a bug report!