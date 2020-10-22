/*
 * MIT License
 *
 * Copyright (c) 2020 Nicholas Fraser
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef POTTERY_SHELL_SORT_IMPL
#error "This is header internal to Pottery. Do not include it."
#endif

#include "pottery/pottery_dependencies.h"

#define POTTERY_INSERTION_SORT_PREFIX POTTERY_CONCAT(POTTERY_SHELL_SORT_PREFIX, _insertion_sort)

#ifdef POTTERY_SHELL_SORT_EXTERNAL_LIFECYCLE
    #define POTTERY_INSERTION_SORT_EXTERNAL_LIFECYCLE POTTERY_SHELL_SORT_EXTERNAL_LIFECYCLE
#endif
#ifdef POTTERY_SHELL_SORT_EXTERNAL_COMPARE
    #define POTTERY_INSERTION_SORT_EXTERNAL_COMPARE POTTERY_SHELL_SORT_EXTERNAL_COMPARE
#endif

// Forward base configuration to insertion_sort
//!!! AUTOGENERATED:sort/forward.t SRC:POTTERY_SHELL_SORT DEST:POTTERY_INSERTION_SORT
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Forwards common sort configuration from POTTERY_SHELL_SORT to POTTERY_INSERTION_SORT

    #if (defined(POTTERY_SHELL_SORT_REF_TYPE) && defined(POTTERY_SHELL_SORT_VALUE_TYPE)) || \
            !defined(POTTERY_SHELL_SORT_REF_TYPE) && !defined(POTTERY_SHELL_SORT_VALUE_TYPE)
        #error "Exactly one of POTTERY_SHELL_SORT_REF_TYPE and POTTERY_SHELL_SORT_VALUE_TYPE must be defined."
    #endif

    #ifdef POTTERY_SHELL_SORT_REF_TYPE
        #define POTTERY_INSERTION_SORT_REF_TYPE POTTERY_SHELL_SORT_REF_TYPE
    #endif
    #ifdef POTTERY_SHELL_SORT_VALUE_TYPE
        #define POTTERY_INSERTION_SORT_VALUE_TYPE POTTERY_SHELL_SORT_VALUE_TYPE
    #endif
    #ifdef POTTERY_SHELL_SORT_CONTEXT_TYPE
        #define POTTERY_INSERTION_SORT_CONTEXT_TYPE POTTERY_SHELL_SORT_CONTEXT_TYPE
    #endif
    #ifdef POTTERY_SHELL_SORT_ACCESS
        #define POTTERY_INSERTION_SORT_ACCESS POTTERY_SHELL_SORT_ACCESS
    #endif

    // TODO this is obsolete, it's been renamed to LIFECYCLE_BY_VALUE. probably
    // this template shouldn't be used anymore, e.g. intro_sort doesn't use it
    #ifdef POTTERY_SHELL_SORT_BY_VALUE
        #define POTTERY_INSERTION_SORT_BY_VALUE POTTERY_SHELL_SORT_BY_VALUE
    #endif
//!!! END_AUTOGENERATED

// The above forwarded context and accessor as-is, but we need to replace them
// with those of shell sort since it needs to offset element indices based on
// the gap sequence.
#undef POTTERY_INSERTION_SORT_CONTEXT_TYPE
#define POTTERY_INSERTION_SORT_CONTEXT_TYPE pottery_shell_sort_state_t
#undef POTTERY_INSERTION_SORT_ACCESS
#define POTTERY_INSERTION_SORT_ACCESS pottery_shell_sort_access



// Forward compare configuration

#if defined(POTTERY_SHELL_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT)
    // TODO this doesn't work, we've changed the context so we can't forward it
    #define POTTERY_INSERTION_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT POTTERY_SHELL_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT
#endif

//!!! AUTOGENERATED:compare/forward.t SRC:POTTERY_SHELL_SORT_COMPARE DEST:POTTERY_INSERTION_SORT_COMPARE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Forwards compare configuration from POTTERY_SHELL_SORT_COMPARE to POTTERY_INSERTION_SORT_COMPARE

    // Note that ref/value types are not forwarded because templates may define
    // either REF_TYPE or VALUE_TYPE, and dynamic containers usually define
    // VALUE_TYPE as their ELEMENT_TYPE.

    #ifdef POTTERY_SHELL_SORT_COMPARE_CONTEXT_TYPE
        #define POTTERY_INSERTION_SORT_COMPARE_CONTEXT_TYPE POTTERY_SHELL_SORT_COMPARE_CONTEXT_TYPE
    #endif
    #ifdef POTTERY_SHELL_SORT_COMPARE_BY_VALUE
        #define POTTERY_INSERTION_SORT_COMPARE_BY_VALUE POTTERY_SHELL_SORT_COMPARE_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_COMPARE_EQUAL
        #define POTTERY_INSERTION_SORT_COMPARE_EQUAL POTTERY_SHELL_SORT_COMPARE_EQUAL
    #endif
    #ifdef POTTERY_SHELL_SORT_COMPARE_NOT_EQUAL
        #define POTTERY_INSERTION_SORT_COMPARE_NOT_EQUAL POTTERY_SHELL_SORT_COMPARE_NOT_EQUAL
    #endif
    #ifdef POTTERY_SHELL_SORT_COMPARE_LESS
        #define POTTERY_INSERTION_SORT_COMPARE_LESS POTTERY_SHELL_SORT_COMPARE_LESS
    #endif
    #ifdef POTTERY_SHELL_SORT_COMPARE_LESS_OR_EQUAL
        #define POTTERY_INSERTION_SORT_COMPARE_LESS_OR_EQUAL POTTERY_SHELL_SORT_COMPARE_LESS_OR_EQUAL
    #endif
    #ifdef POTTERY_SHELL_SORT_COMPARE_GREATER
        #define POTTERY_INSERTION_SORT_COMPARE_GREATER POTTERY_SHELL_SORT_COMPARE_GREATER
    #endif
    #ifdef POTTERY_SHELL_SORT_COMPARE_GREATER_OR_EQUAL
        #define POTTERY_INSERTION_SORT_COMPARE_GREATER_OR_EQUAL POTTERY_SHELL_SORT_COMPARE_GREATER_OR_EQUAL
    #endif
    #ifdef POTTERY_SHELL_SORT_COMPARE_THREE_WAY
        #define POTTERY_INSERTION_SORT_COMPARE_THREE_WAY POTTERY_SHELL_SORT_COMPARE_THREE_WAY
    #endif
//!!! END_AUTOGENERATED



// Forward lifecycle configuration

#if defined(POTTERY_SHELL_SORT_LIFECYCLE_CONTEXT_TYPE)
    #define POTTERY_INSERTION_SORT_LIFECYCLE_CONTEXT_TYPE POTTERY_SHELL_SORT_LIFECYCLE_CONTEXT_TYPE
#endif
#if defined(POTTERY_SHELL_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT)
    #define POTTERY_INSERTION_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT POTTERY_SHELL_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT
#endif

//!!! AUTOGENERATED:lifecycle/forward.t SRC:POTTERY_SHELL_SORT_LIFECYCLE DEST:POTTERY_INSERTION_SORT_LIFECYCLE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    // Forwards lifecycle configuration from POTTERY_SHELL_SORT_LIFECYCLE to POTTERY_INSERTION_SORT_LIFECYCLE

    // Note that types are not forwarded because algorithms usually define REF_TYPE
    // (as the user-defined type) while dynamic containers usually define
    // VALUE_TYPE (e.g. as a pointer to their ELEMENT_TYPE.)

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_DESTROY
        #define POTTERY_INSERTION_SORT_LIFECYCLE_DESTROY POTTERY_SHELL_SORT_LIFECYCLE_DESTROY
    #endif
    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_DESTROY_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_DESTROY_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_DESTROY_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_INIT
        #define POTTERY_INSERTION_SORT_LIFECYCLE_INIT POTTERY_SHELL_SORT_LIFECYCLE_INIT
    #endif
    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_INIT_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_INIT_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_INIT_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_INIT_COPY
        #define POTTERY_INSERTION_SORT_LIFECYCLE_INIT_COPY POTTERY_SHELL_SORT_LIFECYCLE_INIT_COPY
    #endif
    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_INIT_COPY_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_INIT_COPY_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_INIT_COPY_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_INIT_STEAL
        #define POTTERY_INSERTION_SORT_LIFECYCLE_INIT_STEAL POTTERY_SHELL_SORT_LIFECYCLE_INIT_STEAL
    #endif
    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_INIT_STEAL_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_INIT_STEAL_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_INIT_STEAL_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_MOVE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_MOVE POTTERY_SHELL_SORT_LIFECYCLE_MOVE
    #endif
    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_MOVE_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_MOVE_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_MOVE_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_COPY
        #define POTTERY_INSERTION_SORT_LIFECYCLE_COPY POTTERY_SHELL_SORT_LIFECYCLE_COPY
    #endif
    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_COPY_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_COPY_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_COPY_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_STEAL
        #define POTTERY_INSERTION_SORT_LIFECYCLE_STEAL POTTERY_SHELL_SORT_LIFECYCLE_STEAL
    #endif
    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_STEAL_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_STEAL_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_STEAL_BY_VALUE
    #endif

    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_SWAP
        #define POTTERY_INSERTION_SORT_LIFECYCLE_SWAP POTTERY_SHELL_SORT_LIFECYCLE_SWAP
    #endif
    #ifdef POTTERY_SHELL_SORT_LIFECYCLE_SWAP_BY_VALUE
        #define POTTERY_INSERTION_SORT_LIFECYCLE_SWAP_BY_VALUE POTTERY_SHELL_SORT_LIFECYCLE_SWAP_BY_VALUE
    #endif
//!!! END_AUTOGENERATED
