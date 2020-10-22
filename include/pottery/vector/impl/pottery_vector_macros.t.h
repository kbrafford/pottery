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

#ifndef POTTERY_VECTOR_IMPL
#error "This is an internal header. Do not include it."
#endif

#include "pottery/pottery_dependencies.h"
#include "pottery/platform/pottery_platform_pragma_push.t.h"

#ifndef POTTERY_VECTOR_PREFIX
#error "POTTERY_VECTOR_PREFIX is not defined."
#endif

#ifndef POTTERY_VECTOR_ELEMENT_TYPE
#error "POTTERY_VECTOR_ELEMENT_TYPE is not defined."
#endif

#ifndef POTTERY_VECTOR_EXTERN
#define POTTERY_VECTOR_EXTERN /*nothing*/
#endif

// Context forwarding
#ifdef POTTERY_VECTOR_CONTEXT_TYPE
    #define POTTERY_VECTOR_CONTEXT_VAL(vector) vector->context,
#else
    #define POTTERY_VECTOR_CONTEXT_VAL(vector) /*nothing*/
#endif



/*
 * Renaming
 */

#define POTTERY_VECTOR_NAME(name) \
    POTTERY_CONCAT(POTTERY_VECTOR_PREFIX, name)

#define pottery_vector_data POTTERY_VECTOR_NAME(_data)
#define pottery_vector_const_data POTTERY_VECTOR_NAME(_const_data)
#define pottery_vector_capacity POTTERY_VECTOR_NAME(_capacity)
#define pottery_vector_minimum_capacity POTTERY_VECTOR_NAME(_minimum_capacity)

#define pottery_vector_insert_vector POTTERY_VECTOR_NAME(_insert_vector)
#define pottery_vector_insert_last_vector POTTERY_VECTOR_NAME(_insert_last_vector) // TODO rename to insert_last

#define pottery_vector_alloc_context POTTERY_VECTOR_NAME(_alloc_context)
#define pottery_vector_set_alloc_context POTTERY_VECTOR_NAME(_set_alloc_context)

#define pottery_vector_impl_alloc POTTERY_VECTOR_NAME(_impl_alloc)
#define pottery_vector_impl_free POTTERY_VECTOR_NAME(_impl_free)
#define pottery_vector_impl_create_space POTTERY_VECTOR_NAME(_impl_create_space)
#define pottery_vector_impl_remove_space POTTERY_VECTOR_NAME(_impl_remove_space)
#define pottery_vector_impl_clear POTTERY_VECTOR_NAME(_impl_clear)
#define pottery_vector_impl_destroy_destruct_all POTTERY_VECTOR_NAME(_impl_destroy_destruct_all)
#define pottery_vector_impl_copy POTTERY_VECTOR_NAME(_impl_copy)



// dynamic array functions
//!!! AUTOGENERATED:array/rename.t PREFIX:pottery_vector MACRO:POTTERY_VECTOR_NAME
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    // Renames array identifiers with prefix "pottery_vector" using macro POTTERY_VECTOR_NAME()

    // types
    #define pottery_vector_t POTTERY_VECTOR_NAME(_t)
    #define pottery_vector_element_t POTTERY_VECTOR_NAME(_element_t)
    #define pottery_vector_ref_t POTTERY_VECTOR_NAME(_ref_t)
    #define pottery_vector_entry_t POTTERY_VECTOR_NAME(_entry_t)

    // lifecycle operations
    #define pottery_vector_copy POTTERY_VECTOR_NAME(_copy)
    #define pottery_vector_destroy POTTERY_VECTOR_NAME(_destroy)
    #define pottery_vector_init POTTERY_VECTOR_NAME(_init)
    #define pottery_vector_init_copy POTTERY_VECTOR_NAME(_init_copy)
    #define pottery_vector_init_steal POTTERY_VECTOR_NAME(_init_steal)
    #define pottery_vector_move POTTERY_VECTOR_NAME(_move)
    #define pottery_vector_steal POTTERY_VECTOR_NAME(_steal)
    #define pottery_vector_swap POTTERY_VECTOR_NAME(_swap)

    // entry operations
    #define pottery_vector_entry_index POTTERY_VECTOR_NAME(_entry_index)
    #define pottery_vector_entry_exists POTTERY_VECTOR_NAME(_entry_exists)
    #define pottery_vector_entry_equal POTTERY_VECTOR_NAME(_entry_equal)
    #define pottery_vector_entry_element POTTERY_VECTOR_NAME(_entry_element)

    // lookup
    #define pottery_vector_count POTTERY_VECTOR_NAME(_count)
    #define pottery_vector_is_empty POTTERY_VECTOR_NAME(_is_empty)
    #define pottery_vector_at POTTERY_VECTOR_NAME(_at)
    #define pottery_vector_index POTTERY_VECTOR_NAME(_index)
    #define pottery_vector_first POTTERY_VECTOR_NAME(_first)
    #define pottery_vector_last POTTERY_VECTOR_NAME(_last)
    #define pottery_vector_any POTTERY_VECTOR_NAME(_any)

    // iteration
    #define pottery_vector_begin POTTERY_VECTOR_NAME(_begin)
    #define pottery_vector_end POTTERY_VECTOR_NAME(_end)
    #define pottery_vector_next POTTERY_VECTOR_NAME(_next)
    #define pottery_vector_previous POTTERY_VECTOR_NAME(_previous)

    // misc
    #define pottery_vector_reserve POTTERY_VECTOR_NAME(_reserve)
    #define pottery_vector_shrink POTTERY_VECTOR_NAME(_shrink)

    // insert
    #define pottery_vector_insert_at POTTERY_VECTOR_NAME(_insert_at)
    #define pottery_vector_insert_first POTTERY_VECTOR_NAME(_insert_first)
    #define pottery_vector_insert_last POTTERY_VECTOR_NAME(_insert_last)
    #define pottery_vector_insert_before POTTERY_VECTOR_NAME(_insert_before)
    #define pottery_vector_insert_after POTTERY_VECTOR_NAME(_insert_after)
    #define pottery_vector_insert_at_bulk POTTERY_VECTOR_NAME(_insert_at_bulk)
    #define pottery_vector_insert_first_bulk POTTERY_VECTOR_NAME(_insert_first_bulk)
    #define pottery_vector_insert_last_bulk POTTERY_VECTOR_NAME(_insert_last_bulk)
    #define pottery_vector_insert_before_bulk POTTERY_VECTOR_NAME(_insert_before_bulk)
    #define pottery_vector_insert_after_bulk POTTERY_VECTOR_NAME(_insert_after_bulk)

    // emplace
    #define pottery_vector_emplace_at POTTERY_VECTOR_NAME(_emplace_at)
    #define pottery_vector_emplace_first POTTERY_VECTOR_NAME(_emplace_first)
    #define pottery_vector_emplace_last POTTERY_VECTOR_NAME(_emplace_last)
    #define pottery_vector_emplace_before POTTERY_VECTOR_NAME(_emplace_before)
    #define pottery_vector_emplace_after POTTERY_VECTOR_NAME(_emplace_after)
    #define pottery_vector_emplace_at_bulk POTTERY_VECTOR_NAME(_emplace_at_bulk)
    #define pottery_vector_emplace_first_bulk POTTERY_VECTOR_NAME(_emplace_first_bulk)
    #define pottery_vector_emplace_last_bulk POTTERY_VECTOR_NAME(_emplace_last_bulk)
    #define pottery_vector_emplace_before_bulk POTTERY_VECTOR_NAME(_emplace_before_bulk)
    #define pottery_vector_emplace_after_bulk POTTERY_VECTOR_NAME(_emplace_after_bulk)

    // construct
    #define pottery_vector_construct_at POTTERY_VECTOR_NAME(_construct_at)
    #define pottery_vector_construct_first POTTERY_VECTOR_NAME(_construct_first)
    #define pottery_vector_construct_last POTTERY_VECTOR_NAME(_construct_last)
    #define pottery_vector_construct_before POTTERY_VECTOR_NAME(_construct_before)
    #define pottery_vector_construct_after POTTERY_VECTOR_NAME(_construct_after)

    // extract
    #define pottery_vector_extract POTTERY_VECTOR_NAME(_extract)
    #define pottery_vector_extract_at POTTERY_VECTOR_NAME(_extract_at)
    #define pottery_vector_extract_first POTTERY_VECTOR_NAME(_extract_first)
    #define pottery_vector_extract_last POTTERY_VECTOR_NAME(_extract_last)
    #define pottery_vector_extract_and_next POTTERY_VECTOR_NAME(_extract_and_next)
    #define pottery_vector_extract_and_previous POTTERY_VECTOR_NAME(_extract_and_previous)

    // remove
    #define pottery_vector_remove POTTERY_VECTOR_NAME(_remove)
    #define pottery_vector_remove_at POTTERY_VECTOR_NAME(_remove_at)
    #define pottery_vector_remove_first POTTERY_VECTOR_NAME(_remove_first)
    #define pottery_vector_remove_last POTTERY_VECTOR_NAME(_remove_last)
    #define pottery_vector_remove_and_next POTTERY_VECTOR_NAME(_remove_and_next)
    #define pottery_vector_remove_and_previous POTTERY_VECTOR_NAME(_remove_and_previous)
    #define pottery_vector_remove_all POTTERY_VECTOR_NAME(_remove_all)
    #define pottery_vector_remove_at_bulk POTTERY_VECTOR_NAME(_remove_at_bulk)
    #define pottery_vector_remove_first_bulk POTTERY_VECTOR_NAME(_remove_first_bulk)
    #define pottery_vector_remove_last_bulk POTTERY_VECTOR_NAME(_remove_last_bulk)
    #define pottery_vector_remove_at_bulk POTTERY_VECTOR_NAME(_remove_at_bulk)

    // displace
    #define pottery_vector_displace POTTERY_VECTOR_NAME(_displace)
    #define pottery_vector_displace_at POTTERY_VECTOR_NAME(_displace_at)
    #define pottery_vector_displace_first POTTERY_VECTOR_NAME(_displace_first)
    #define pottery_vector_displace_last POTTERY_VECTOR_NAME(_displace_last)
    #define pottery_vector_displace_and_next POTTERY_VECTOR_NAME(_displace_and_next)
    #define pottery_vector_displace_and_previous POTTERY_VECTOR_NAME(_displace_and_previous)
    #define pottery_vector_displace_all POTTERY_VECTOR_NAME(_displace_all)
    #define pottery_vector_displace_at_bulk POTTERY_VECTOR_NAME(_displace_at_bulk)
    #define pottery_vector_displace_first_bulk POTTERY_VECTOR_NAME(_displace_first_bulk)
    #define pottery_vector_displace_last_bulk POTTERY_VECTOR_NAME(_displace_last_bulk)
//!!! END_AUTOGENERATED



// lifecycle functions
#define POTTERY_VECTOR_LIFECYCLE_NAME(x) POTTERY_VECTOR_NAME(POTTERY_CONCAT(_lifecycle, x))
//!!! AUTOGENERATED:lifecycle/rename.t PREFIX:pottery_vector_lifecycle MACRO:POTTERY_VECTOR_LIFECYCLE_NAME
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    // Renames lifecycle identifiers with prefix "pottery_vector_lifecycle" using macro POTTERY_VECTOR_LIFECYCLE_NAME()

    // types
    #define pottery_vector_lifecycle_value_t POTTERY_VECTOR_LIFECYCLE_NAME(_value_t)
    #define pottery_vector_lifecycle_ref_t POTTERY_VECTOR_LIFECYCLE_NAME(_ref_t)
    #define pottery_vector_lifecycle_const_ref_t POTTERY_VECTOR_LIFECYCLE_NAME(_const_ref_t)
    #define pottery_vector_lifecycle_context_t POTTERY_VECTOR_LIFECYCLE_NAME(_context_t)

    // fundamental operations
    #define pottery_vector_lifecycle_init_steal POTTERY_VECTOR_LIFECYCLE_NAME(_init_steal)
    #define pottery_vector_lifecycle_init_copy POTTERY_VECTOR_LIFECYCLE_NAME(_init_copy)
    #define pottery_vector_lifecycle_init POTTERY_VECTOR_LIFECYCLE_NAME(_init)
    #define pottery_vector_lifecycle_destroy POTTERY_VECTOR_LIFECYCLE_NAME(_destroy)
    #define pottery_vector_lifecycle_swap POTTERY_VECTOR_LIFECYCLE_NAME(_swap)
    #define pottery_vector_lifecycle_move POTTERY_VECTOR_LIFECYCLE_NAME(_move)
    #define pottery_vector_lifecycle_steal POTTERY_VECTOR_LIFECYCLE_NAME(_steal)
    #define pottery_vector_lifecycle_copy POTTERY_VECTOR_LIFECYCLE_NAME(_copy)

    // bulk operations
    #define pottery_vector_lifecycle_destroy_bulk POTTERY_VECTOR_LIFECYCLE_NAME(_destroy_bulk)
    #define pottery_vector_lifecycle_move_bulk POTTERY_VECTOR_LIFECYCLE_NAME(_move_bulk)
    #define pottery_vector_lifecycle_move_bulk_restrict POTTERY_VECTOR_LIFECYCLE_NAME(_move_bulk_restrict)
    #define pottery_vector_lifecycle_move_bulk_restrict_impl POTTERY_VECTOR_LIFECYCLE_NAME(_move_bulk_restrict_impl)
    #define pottery_vector_lifecycle_move_bulk_up POTTERY_VECTOR_LIFECYCLE_NAME(_move_bulk_up)
    #define pottery_vector_lifecycle_move_bulk_up_impl POTTERY_VECTOR_LIFECYCLE_NAME(_move_bulk_up_impl)
    #define pottery_vector_lifecycle_move_bulk_down POTTERY_VECTOR_LIFECYCLE_NAME(_move_bulk_down)
    #define pottery_vector_lifecycle_move_bulk_down_impl POTTERY_VECTOR_LIFECYCLE_NAME(_move_bulk_down_impl)

    // C++
    #define pottery_vector_lifecycle_construct POTTERY_VECTOR_LIFECYCLE_NAME(_construct)
    #define pottery_vector_lifecycle_assign POTTERY_VECTOR_LIFECYCLE_NAME(_assign)
//!!! END_AUTOGENERATED

// alloc functions
#define POTTERY_VECTOR_ALLOC_NAME(x) POTTERY_VECTOR_NAME(POTTERY_CONCAT(_alloc, x))
//!!! AUTOGENERATED:alloc/rename.t PREFIX:pottery_vector_alloc MACRO:POTTERY_VECTOR_ALLOC_NAME
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Renames alloc identifiers with prefix "pottery_vector_alloc"
    // using macro POTTERY_VECTOR_ALLOC_NAME()

    #define pottery_vector_alloc_free POTTERY_VECTOR_ALLOC_NAME(_free)
    #define pottery_vector_alloc_impl_free_ea POTTERY_VECTOR_ALLOC_NAME(_impl_free_ea)
    #define pottery_vector_alloc_impl_free_fa POTTERY_VECTOR_ALLOC_NAME(_impl_free_fa)

    #define pottery_vector_alloc_malloc POTTERY_VECTOR_ALLOC_NAME(_malloc)
    #define pottery_vector_alloc_impl_malloc_ea POTTERY_VECTOR_ALLOC_NAME(_impl_malloc_ea)
    #define pottery_vector_alloc_impl_malloc_fa POTTERY_VECTOR_ALLOC_NAME(_impl_malloc_fa)

    #define pottery_vector_alloc_malloc_zero POTTERY_VECTOR_ALLOC_NAME(_malloc_zero)
    #define pottery_vector_alloc_impl_malloc_zero_ea POTTERY_VECTOR_ALLOC_NAME(_impl_malloc_zero_ea)
    #define pottery_vector_alloc_impl_malloc_zero_fa POTTERY_VECTOR_ALLOC_NAME(_impl_malloc_zero_fa)
    #define pottery_vector_alloc_impl_malloc_zero_fa_wrap POTTERY_VECTOR_ALLOC_NAME(_impl_malloc_zero_fa_wrap)

    #define pottery_vector_alloc_malloc_array_at_least POTTERY_VECTOR_ALLOC_NAME(_malloc_array_at_least)
    #define pottery_vector_alloc_impl_malloc_array_at_least_ea POTTERY_VECTOR_ALLOC_NAME(_impl_malloc_array_at_least_ea)
    #define pottery_vector_alloc_impl_malloc_array_at_least_fa POTTERY_VECTOR_ALLOC_NAME(_impl_malloc_array_at_least_fa)

    #define pottery_vector_alloc_malloc_array POTTERY_VECTOR_ALLOC_NAME(_malloc_array)
    #define pottery_vector_alloc_malloc_array_zero POTTERY_VECTOR_ALLOC_NAME(_malloc_array_zero)
//!!! END_AUTOGENERATED
