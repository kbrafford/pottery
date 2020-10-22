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
#error "This is an internal header. Do not include it."
#endif



/*
 * Configuration
 */

#undef POTTERY_SHELL_SORT_PREFIX
#undef POTTERY_SHELL_SORT_EXTERN
#undef POTTERY_SHELL_SORT_USE_MOVE
#undef POTTERY_SHELL_SORT_EXTERNAL_LIFECYCLE
#undef POTTERY_SHELL_SORT_EXTERNAL_COMPARE
#undef POTTERY_SHELL_SORT_CONTEXT_VAL

//!!! AUTOGENERATED:sort/unconfigure.t PREFIX:POTTERY_SHELL_SORT
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Undefines (forwardable/forwarded) common sort configuration on POTTERY_SHELL_SORT
    #undef POTTERY_SHELL_SORT_REF_TYPE
    #undef POTTERY_SHELL_SORT_VALUE_TYPE
    #undef POTTERY_SHELL_SORT_CONTEXT_TYPE
    #undef POTTERY_SHELL_SORT_ACCESS
    #undef POTTERY_SHELL_SORT_BY_VALUE
//!!! END_AUTOGENERATED



/*
 * Renaming
 */

#undef POTTERY_SHELL_SORT_NAME

#undef pottery_shell_sort_ref_t
#undef pottery_shell_sort_value_t
#undef pottery_shell_sort_context_t
#undef pottery_shell_sort_lifecycle_context_t
#undef pottery_shell_sort_compare_context_t
#undef pottery_shell_sort
#undef pottery_shell_sort_insertion_sort
#undef pottery_shell_sort_access
#undef pottery_shell_sort_state_t



// lifecycle functions
#undef POTTERY_SHELL_SORT_LIFECYCLE_NAME
//!!! AUTOGENERATED:lifecycle/unrename.t PREFIX:pottery_shell_sort_lifecycle
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    // Un-renames lifecycle identifiers with prefix "pottery_shell_sort_lifecycle"

    // types
    #undef pottery_shell_sort_lifecycle_ref_t
    #undef pottery_shell_sort_lifecycle_const_ref_t
    #undef pottery_shell_sort_lifecycle_value_t
    #undef pottery_shell_sort_lifecycle_context_t

    // fundamental operations
    #undef pottery_shell_sort_lifecycle_init_steal
    #undef pottery_shell_sort_lifecycle_init_copy
    #undef pottery_shell_sort_lifecycle_init
    #undef pottery_shell_sort_lifecycle_destroy
    #undef pottery_shell_sort_lifecycle_swap
    #undef pottery_shell_sort_lifecycle_move
    #undef pottery_shell_sort_lifecycle_steal
    #undef pottery_shell_sort_lifecycle_copy

    // bulk operations
    #undef pottery_shell_sort_lifecycle_move_bulk
    #undef pottery_shell_sort_lifecycle_move_bulk_restrict
    #undef pottery_shell_sort_lifecycle_move_bulk_restrict_impl
    #undef pottery_shell_sort_lifecycle_move_bulk_up
    #undef pottery_shell_sort_lifecycle_move_bulk_up_impl
    #undef pottery_shell_sort_lifecycle_move_bulk_down
    #undef pottery_shell_sort_lifecycle_move_bulk_down_impl
    #undef pottery_shell_sort_lifecycle_destroy_bulk

    // C++
    #undef pottery_shell_sort_lifecycle_construct
    #undef pottery_shell_sort_lifecycle_assign
//!!! END_AUTOGENERATED

//!!! AUTOGENERATED:lifecycle/unconfigure.t PREFIX:POTTERY_SHELL_SORT_LIFECYCLE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    // Undefines (forwardable/forwarded) lifecycle configuration on POTTERY_SHELL_SORT_LIFECYCLE

    #undef POTTERY_SHELL_SORT_LIFECYCLE_TYPE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_BY_VALUE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_DESTROY
    #undef POTTERY_SHELL_SORT_LIFECYCLE_DESTROY_BY_VALUE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_INIT
    #undef POTTERY_SHELL_SORT_LIFECYCLE_INIT_BY_VALUE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_INIT_COPY
    #undef POTTERY_SHELL_SORT_LIFECYCLE_INIT_COPY_BY_VALUE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_INIT_STEAL
    #undef POTTERY_SHELL_SORT_LIFECYCLE_INIT_STEAL_BY_VALUE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_MOVE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_MOVE_BY_VALUE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_COPY
    #undef POTTERY_SHELL_SORT_LIFECYCLE_COPY_BY_VALUE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_STEAL
    #undef POTTERY_SHELL_SORT_LIFECYCLE_STEAL_BY_VALUE
    #undef POTTERY_SHELL_SORT_LIFECYCLE_SWAP
    #undef POTTERY_SHELL_SORT_LIFECYCLE_SWAP_BY_VALUE
//!!! END_AUTOGENERATED



// compare functions
#undef POTTERY_SHELL_SORT_COMPARE_NAME
//!!! AUTOGENERATED:compare/unrename.t PREFIX:pottery_shell_sort_compare
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Un-renames compare identifiers with prefix "pottery_shell_sort_compare"
    #undef pottery_shell_sort_compare_ref_t
    #undef pottery_shell_sort_compare_value_t
    #undef pottery_shell_sort_compare_context_t

    #undef pottery_shell_sort_compare_three_way
    #undef pottery_shell_sort_compare_equal
    #undef pottery_shell_sort_compare_not_equal
    #undef pottery_shell_sort_compare_less
    #undef pottery_shell_sort_compare_less_or_equal
    #undef pottery_shell_sort_compare_greater
    #undef pottery_shell_sort_compare_greater_or_equal

    #undef pottery_shell_sort_compare_min
    #undef pottery_shell_sort_compare_max
    #undef pottery_shell_sort_compare_clamp
    #undef pottery_shell_sort_compare_median
//!!! END_AUTOGENERATED

//!!! AUTOGENERATED:compare/unconfigure.t PREFIX:POTTERY_SHELL_SORT_COMPARE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Undefines (forwardable/forwarded) compare configuration on POTTERY_SHELL_SORT_COMPARE

    #undef POTTERY_SHELL_SORT_COMPARE_REF_TYPE
    #undef POTTERY_SHELL_SORT_COMPARE_VALUE_TYPE
    #undef POTTERY_SHELL_SORT_COMPARE_CONTEXT_TYPE
    #undef POTTERY_SHELL_SORT_COMPARE_STATE_TYPE
    #undef POTTERY_SHELL_SORT_COMPARE_STATE_CONTEXT
    #undef POTTERY_SHELL_SORT_COMPARE_BY_VALUE

    #undef POTTERY_SHELL_SORT_COMPARE_EQUAL
    #undef POTTERY_SHELL_SORT_COMPARE_NOT_EQUAL
    #undef POTTERY_SHELL_SORT_COMPARE_LESS
    #undef POTTERY_SHELL_SORT_COMPARE_LESS_OR_EQUAL
    #undef POTTERY_SHELL_SORT_COMPARE_GREATER
    #undef POTTERY_SHELL_SORT_COMPARE_GREATER_OR_EQUAL
    #undef POTTERY_SHELL_SORT_COMPARE_THREE_WAY
//!!! END_AUTOGENERATED
