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

#ifndef POTTERY_HEAP_SORT_IMPL
#error "This is header internal to Pottery. Do not include it."
#endif

#include "pottery/pottery_dependencies.h"

#define POTTERY_HEAP_PREFIX POTTERY_CONCAT(POTTERY_HEAP_SORT_PREFIX, _heap)

#ifdef POTTERY_HEAP_SORT_EXTERNAL_LIFECYCLE
    #define POTTERY_HEAP_EXTERNAL_LIFECYCLE POTTERY_HEAP_SORT_EXTERNAL_LIFECYCLE
#endif
#ifdef POTTERY_HEAP_SORT_EXTERNAL_COMPARE
    #define POTTERY_HEAP_EXTERNAL_COMPARE POTTERY_HEAP_SORT_EXTERNAL_COMPARE
#endif

// See if we should accept a separate compare context parameter
#if defined(POTTERY_HEAP_SORT_COMPARE_CONTEXT_TYPE) && !POTTERY_HEAP_SORT_CONTEXT_IS_COMPARE_CONTEXT
    #define POTTERY_HEAP_SORT_SEPARATE_COMPARE_CONTEXT 1
#else
    #define POTTERY_HEAP_SORT_SEPARATE_COMPARE_CONTEXT 0
#endif

// See if we should accept a separate compare context parameter
#if defined(POTTERY_HEAP_SORT_COMPARE_CONTEXT_TYPE) && !POTTERY_HEAP_SORT_CONTEXT_IS_COMPARE_CONTEXT
    #define POTTERY_HEAP_SORT_SEPARATE_COMPARE_CONTEXT 1
#else
    #define POTTERY_HEAP_SORT_SEPARATE_COMPARE_CONTEXT 0
#endif


// Forward base configuration to heap
// (heap is not really a sort algorithm but this contains most of what we need.)
//!!! AUTOGENERATED:sort/forward.t SRC:POTTERY_HEAP_SORT DEST:POTTERY_HEAP
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Forwards common sort configuration from POTTERY_HEAP_SORT to POTTERY_HEAP

    #if (defined(POTTERY_HEAP_SORT_REF_TYPE) && defined(POTTERY_HEAP_SORT_VALUE_TYPE)) || \
            !defined(POTTERY_HEAP_SORT_REF_TYPE) && !defined(POTTERY_HEAP_SORT_VALUE_TYPE)
        #error "Exactly one of POTTERY_HEAP_SORT_REF_TYPE and POTTERY_HEAP_SORT_VALUE_TYPE must be defined."
    #endif

    #ifdef POTTERY_HEAP_SORT_REF_TYPE
        #define POTTERY_HEAP_REF_TYPE POTTERY_HEAP_SORT_REF_TYPE
    #endif
    #ifdef POTTERY_HEAP_SORT_VALUE_TYPE
        #define POTTERY_HEAP_VALUE_TYPE POTTERY_HEAP_SORT_VALUE_TYPE
    #endif
    #ifdef POTTERY_HEAP_SORT_CONTEXT_TYPE
        #define POTTERY_HEAP_CONTEXT_TYPE POTTERY_HEAP_SORT_CONTEXT_TYPE
    #endif
    #ifdef POTTERY_HEAP_SORT_ACCESS
        #define POTTERY_HEAP_ACCESS POTTERY_HEAP_SORT_ACCESS
    #endif
    #ifdef POTTERY_HEAP_SORT_BY_VALUE
        #define POTTERY_HEAP_BY_VALUE POTTERY_HEAP_SORT_BY_VALUE
    #endif
//!!! END_AUTOGENERATED



// Forward compare configuration

#if defined(POTTERY_HEAP_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT)
    #define POTTERY_HEAP_CONTEXT_IS_LIFECYCLE_CONTEXT POTTERY_HEAP_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT
#endif

//!!! AUTOGENERATED:compare/forward.t SRC:POTTERY_HEAP_SORT_COMPARE DEST:POTTERY_HEAP_COMPARE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Forwards compare configuration from POTTERY_HEAP_SORT_COMPARE to POTTERY_HEAP_COMPARE

    // Note that ref/value types are not forwarded because templates may define
    // either REF_TYPE or VALUE_TYPE, and dynamic containers usually define
    // VALUE_TYPE as their ELEMENT_TYPE.

    #ifdef POTTERY_HEAP_SORT_COMPARE_CONTEXT_TYPE
        #define POTTERY_HEAP_COMPARE_CONTEXT_TYPE POTTERY_HEAP_SORT_COMPARE_CONTEXT_TYPE
    #endif
    #ifdef POTTERY_HEAP_SORT_COMPARE_BY_VALUE
        #define POTTERY_HEAP_COMPARE_BY_VALUE POTTERY_HEAP_SORT_COMPARE_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_COMPARE_EQUAL
        #define POTTERY_HEAP_COMPARE_EQUAL POTTERY_HEAP_SORT_COMPARE_EQUAL
    #endif
    #ifdef POTTERY_HEAP_SORT_COMPARE_NOT_EQUAL
        #define POTTERY_HEAP_COMPARE_NOT_EQUAL POTTERY_HEAP_SORT_COMPARE_NOT_EQUAL
    #endif
    #ifdef POTTERY_HEAP_SORT_COMPARE_LESS
        #define POTTERY_HEAP_COMPARE_LESS POTTERY_HEAP_SORT_COMPARE_LESS
    #endif
    #ifdef POTTERY_HEAP_SORT_COMPARE_LESS_OR_EQUAL
        #define POTTERY_HEAP_COMPARE_LESS_OR_EQUAL POTTERY_HEAP_SORT_COMPARE_LESS_OR_EQUAL
    #endif
    #ifdef POTTERY_HEAP_SORT_COMPARE_GREATER
        #define POTTERY_HEAP_COMPARE_GREATER POTTERY_HEAP_SORT_COMPARE_GREATER
    #endif
    #ifdef POTTERY_HEAP_SORT_COMPARE_GREATER_OR_EQUAL
        #define POTTERY_HEAP_COMPARE_GREATER_OR_EQUAL POTTERY_HEAP_SORT_COMPARE_GREATER_OR_EQUAL
    #endif
    #ifdef POTTERY_HEAP_SORT_COMPARE_THREE_WAY
        #define POTTERY_HEAP_COMPARE_THREE_WAY POTTERY_HEAP_SORT_COMPARE_THREE_WAY
    #endif
//!!! END_AUTOGENERATED



// Forward lifecycle configuration

#if defined(POTTERY_HEAP_SORT_LIFECYCLE_CONTEXT_TYPE)
    #define POTTERY_HEAP_LIFECYCLE_CONTEXT_TYPE POTTERY_HEAP_SORT_LIFECYCLE_CONTEXT_TYPE
#endif
#if defined(POTTERY_HEAP_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT)
    #define POTTERY_HEAP_CONTEXT_IS_LIFECYCLE_CONTEXT POTTERY_HEAP_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT
#endif

//!!! AUTOGENERATED:lifecycle/forward.t SRC:POTTERY_HEAP_SORT_LIFECYCLE DEST:POTTERY_HEAP_LIFECYCLE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    // Forwards lifecycle configuration from POTTERY_HEAP_SORT_LIFECYCLE to POTTERY_HEAP_LIFECYCLE

    // Note that types are not forwarded because algorithms usually define REF_TYPE
    // (as the user-defined type) while dynamic containers usually define
    // VALUE_TYPE (e.g. as a pointer to their ELEMENT_TYPE.)

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_DESTROY
        #define POTTERY_HEAP_LIFECYCLE_DESTROY POTTERY_HEAP_SORT_LIFECYCLE_DESTROY
    #endif
    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_DESTROY_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_DESTROY_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_DESTROY_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_INIT
        #define POTTERY_HEAP_LIFECYCLE_INIT POTTERY_HEAP_SORT_LIFECYCLE_INIT
    #endif
    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_INIT_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_INIT_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_INIT_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_INIT_COPY
        #define POTTERY_HEAP_LIFECYCLE_INIT_COPY POTTERY_HEAP_SORT_LIFECYCLE_INIT_COPY
    #endif
    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_INIT_COPY_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_INIT_COPY_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_INIT_COPY_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_INIT_STEAL
        #define POTTERY_HEAP_LIFECYCLE_INIT_STEAL POTTERY_HEAP_SORT_LIFECYCLE_INIT_STEAL
    #endif
    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_INIT_STEAL_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_INIT_STEAL_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_INIT_STEAL_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_MOVE
        #define POTTERY_HEAP_LIFECYCLE_MOVE POTTERY_HEAP_SORT_LIFECYCLE_MOVE
    #endif
    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_MOVE_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_MOVE_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_MOVE_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_COPY
        #define POTTERY_HEAP_LIFECYCLE_COPY POTTERY_HEAP_SORT_LIFECYCLE_COPY
    #endif
    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_COPY_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_COPY_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_COPY_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_STEAL
        #define POTTERY_HEAP_LIFECYCLE_STEAL POTTERY_HEAP_SORT_LIFECYCLE_STEAL
    #endif
    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_STEAL_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_STEAL_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_STEAL_BY_VALUE
    #endif

    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_SWAP
        #define POTTERY_HEAP_LIFECYCLE_SWAP POTTERY_HEAP_SORT_LIFECYCLE_SWAP
    #endif
    #ifdef POTTERY_HEAP_SORT_LIFECYCLE_SWAP_BY_VALUE
        #define POTTERY_HEAP_LIFECYCLE_SWAP_BY_VALUE POTTERY_HEAP_SORT_LIFECYCLE_SWAP_BY_VALUE
    #endif
//!!! END_AUTOGENERATED
