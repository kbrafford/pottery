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

#ifndef POTTERY_HEAP_IMPL
#error "This is an internal header. Do not include it."
#endif

/*
 * types
 */

#ifdef POTTERY_HEAP_VALUE_TYPE
typedef POTTERY_HEAP_VALUE_TYPE pottery_heap_value_t;
#endif

#ifdef POTTERY_HEAP_REF_TYPE
typedef POTTERY_HEAP_REF_TYPE pottery_heap_ref_t;
#else
typedef pottery_heap_value_t* pottery_heap_ref_t;
#endif

#ifdef POTTERY_HEAP_CONTEXT_TYPE
typedef POTTERY_HEAP_CONTEXT_TYPE pottery_heap_context_t;
#endif

typedef struct pottery_state_t {
    #ifdef POTTERY_HEAP_CONTEXT_TYPE
    pottery_heap_context_t context;
    #endif
    pottery_heap_ref_t first;
} pottery_state_t;



#if POTTERY_FORWARD_DECLARATIONS
POTTERY_HEAP_EXTERN
void pottery_heap_build_impl(pottery_state_t state, size_t count);

POTTERY_HEAP_EXTERN
void pottery_heap_push_impl(pottery_state_t state, size_t current_count, size_t push_count);

POTTERY_HEAP_EXTERN
void pottery_heap_pop_impl(pottery_state_t state, size_t current_count, size_t pop_count);

POTTERY_HEAP_EXTERN
void pottery_heap_remove_impl(pottery_state_t state, size_t current_count, size_t index_to_remove);

POTTERY_HEAP_EXTERN
size_t pottery_heap_valid_count_impl(pottery_state_t state, size_t count);
#endif



static inline
void pottery_heap_build(
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        pottery_heap_context_t context,
        #endif
        pottery_heap_ref_t first,
        size_t count
) {
    pottery_state_t state = {
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        context,
        #endif
        first,
    };
    pottery_heap_build_impl(state, count);
}

// TODO should rename the below to push_bulk and pop_bulk, provide single
// push/pop. I think I didn't do this originally because of the confusion of
// what size should be if there's no push/pop count argument

/**
 * Adds `push_count` elements to a heap of size `current_count`.
 *
 * The resulting size of the heap will be (current_count + push_count).
 *
 * Note that this API is different from the C++ std::push_heap. std::push_heap
 * takes as arguments the bounds you want the heap to be after pushing the
 * last element. This is somewhat inconsistent from std::pop_heap which takes
 * the current bounds of the heap before popping the largest element. Pottery
 * avoids this ambiguity by always taking the current count as the argument.
 */
static inline
void pottery_heap_push(
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        pottery_heap_context_t context,
        #endif
        pottery_heap_ref_t first,
        size_t current_count,
        size_t push_count
) {
    pottery_state_t state = {
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        context,
        #endif
        first,
    };
    pottery_heap_push_impl(state, current_count, push_count);
}

/**
 * Removes `pop_count` elements from a heap of current size `current_count`,
 * moving them to the end of the array.
 *
 * The resulting size of the heap will be (current_count - pop_count).
 */
static inline
void pottery_heap_pop(
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        pottery_heap_context_t context,
        #endif
        pottery_heap_ref_t first,
        size_t current_count,
        size_t pop_count
) {
    pottery_state_t state = {
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        context,
        #endif
        first,
    };
    pottery_heap_pop_impl(state, current_count, pop_count);
}

/**
 * Removes a single element from a heap of current size `current_count`, moving
 * it to the end of the array.
 *
 * The resulting size of the heap will be (current_count - 1).
 */
static inline
void pottery_heap_remove(
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        pottery_heap_context_t context,
        #endif
        pottery_heap_ref_t first,
        size_t current_count,
        size_t index_to_remove
) {
    pottery_state_t state = {
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        context,
        #endif
        first,
    };
    pottery_heap_remove_impl(state, current_count, index_to_remove);
}

/**
 * Returns the number of elements in the given range that form a valid heap.
 */
static inline
size_t pottery_heap_valid_count(
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        pottery_heap_context_t context,
        #endif
        pottery_heap_ref_t first,
        size_t count
) {
    pottery_state_t state = {
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        context,
        #endif
        first,
    };
    return pottery_heap_valid_count_impl(state, count);
}

/**
 * Returns true if the heap is valid (i.e. every parent node is not less than
 * its children.)
 */
static inline
bool pottery_heap_valid(
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        pottery_heap_context_t context,
        #endif
        pottery_heap_ref_t first,
        size_t count
) {
    return count == pottery_heap_valid_count(
        #ifdef POTTERY_HEAP_CONTEXT_TYPE
        context,
        #endif
        first,
        count);
}
