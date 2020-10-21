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

#ifndef POTTERY_INTRO_SORT_IMPL
#error "This is header internal to Pottery. Do not include it."
#endif

#include "pottery/pottery_dependencies.h"

#define POTTERY_LIFECYCLE_PREFIX POTTERY_CONCAT(POTTERY_INTRO_SORT_PREFIX, _lifecycle)

// Forward the ref or value type
#if defined(POTTERY_INTRO_SORT_REF_TYPE)
    #define POTTERY_LIFECYCLE_REF_TYPE POTTERY_INTRO_SORT_REF_TYPE
#elif defined(POTTERY_INTRO_SORT_VALUE_TYPE)
    #define POTTERY_LIFECYCLE_VALUE_TYPE POTTERY_INTRO_SORT_VALUE_TYPE
#else
    #error "Exactly one of POTTERY_INTRO_SORT_REF_TYPE and POTTERY_INTRO_SORT_VALUE_TYPE must be defined."
#endif

// If POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT is enabled, forward
// the sort context as the lifecycle context
#ifndef POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT
    #define POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT 0
#endif
#if POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT && defined(POTTERY_INTRO_SORT_LIFECYCLE_CONTEXT_TYPE)
    #error "You cannot both enable POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT and define POTTERY_INTRO_SORT_LIFECYCLE_CONTEXT_TYPE."
#endif
#if POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT && !defined(POTTERY_INTRO_SORT_CONTEXT_TYPE)
    #error "POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT requires POTTERY_INTRO_SORT_CONTEXT_TYPE."
#endif
#if POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT
    #define POTTERY_INTRO_SORT_LIFECYCLE_CONTEXT_TYPE POTTERY_INTRO_SORT_CONTEXT_TYPE
#endif

// See if we should accept a separate lifecycle context parameter
#if defined(POTTERY_INTRO_SORT_LIFECYCLE_CONTEXT_TYPE) && !POTTERY_INTRO_SORT_CONTEXT_IS_LIFECYCLE_CONTEXT
    #define POTTERY_INTRO_SORT_SEPARATE_LIFECYCLE_CONTEXT 1
#else
    #define POTTERY_INTRO_SORT_SEPARATE_LIFECYCLE_CONTEXT 0
#endif



// Forward lifecycle configuration
//!!! AUTOGENERATED:lifecycle/forward.t SRC:POTTERY_INTRO_SORT_LIFECYCLE DEST:POTTERY_LIFECYCLE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    // Forwards lifecycle configuration from POTTERY_INTRO_SORT_LIFECYCLE to POTTERY_LIFECYCLE

    // Note that types are not forwarded because algorithms usually define REF_TYPE
    // (as the user-defined type) while dynamic containers usually define
    // VALUE_TYPE (e.g. as a pointer to their ELEMENT_TYPE.)

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_BY_VALUE
        #define POTTERY_LIFECYCLE_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_BY_VALUE
    #endif

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_DESTROY
        #define POTTERY_LIFECYCLE_DESTROY POTTERY_INTRO_SORT_LIFECYCLE_DESTROY
    #endif
    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_DESTROY_BY_VALUE
        #define POTTERY_LIFECYCLE_DESTROY_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_DESTROY_BY_VALUE
    #endif

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_INIT
        #define POTTERY_LIFECYCLE_INIT POTTERY_INTRO_SORT_LIFECYCLE_INIT
    #endif
    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_INIT_BY_VALUE
        #define POTTERY_LIFECYCLE_INIT_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_INIT_BY_VALUE
    #endif

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_INIT_COPY
        #define POTTERY_LIFECYCLE_INIT_COPY POTTERY_INTRO_SORT_LIFECYCLE_INIT_COPY
    #endif
    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_INIT_COPY_BY_VALUE
        #define POTTERY_LIFECYCLE_INIT_COPY_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_INIT_COPY_BY_VALUE
    #endif

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_INIT_STEAL
        #define POTTERY_LIFECYCLE_INIT_STEAL POTTERY_INTRO_SORT_LIFECYCLE_INIT_STEAL
    #endif
    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_INIT_STEAL_BY_VALUE
        #define POTTERY_LIFECYCLE_INIT_STEAL_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_INIT_STEAL_BY_VALUE
    #endif

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_MOVE
        #define POTTERY_LIFECYCLE_MOVE POTTERY_INTRO_SORT_LIFECYCLE_MOVE
    #endif
    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_MOVE_BY_VALUE
        #define POTTERY_LIFECYCLE_MOVE_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_MOVE_BY_VALUE
    #endif

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_COPY
        #define POTTERY_LIFECYCLE_COPY POTTERY_INTRO_SORT_LIFECYCLE_COPY
    #endif
    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_COPY_BY_VALUE
        #define POTTERY_LIFECYCLE_COPY_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_COPY_BY_VALUE
    #endif

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_STEAL
        #define POTTERY_LIFECYCLE_STEAL POTTERY_INTRO_SORT_LIFECYCLE_STEAL
    #endif
    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_STEAL_BY_VALUE
        #define POTTERY_LIFECYCLE_STEAL_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_STEAL_BY_VALUE
    #endif

    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_SWAP
        #define POTTERY_LIFECYCLE_SWAP POTTERY_INTRO_SORT_LIFECYCLE_SWAP
    #endif
    #ifdef POTTERY_INTRO_SORT_LIFECYCLE_SWAP_BY_VALUE
        #define POTTERY_LIFECYCLE_SWAP_BY_VALUE POTTERY_INTRO_SORT_LIFECYCLE_SWAP_BY_VALUE
    #endif
//!!! END_AUTOGENERATED
