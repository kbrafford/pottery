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

#ifndef POTTERY_OPEN_HASH_TABLE_IMPL
#error "This is an internal header. Do not include it."
#endif

// user configuration

#undef POTTERY_OPEN_HASH_TABLE_PREFIX
#undef POTTERY_OPEN_HASH_TABLE_EXTERN
#undef POTTERY_OPEN_HASH_TABLE_USE_MOVE
#undef POTTERY_OPEN_HASH_TABLE_EXTERNAL_LIFECYCLE
#undef POTTERY_OPEN_HASH_TABLE_EXTERNAL_COMPARE
#undef POTTERY_OPEN_HASH_TABLE_CONTEXT_ARG
#undef POTTERY_OPEN_HASH_TABLE_CONTEXT_VAL

#undef POTTERY_OPEN_HASH_TABLE_KEY_TYPE
#undef POTTERY_OPEN_HASH_TABLE_KEY_FOR_VALUE
#undef POTTERY_OPEN_HASH_TABLE_KEY_EQUAL

// TODO not sort
//%%%!!! AUTOGENERATED:sort/unconfigure.t PREFIX:POTTERY_OPEN_HASH_TABLE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Undefines (forwardable/forwarded) common sort configuration on POTTERY_OPEN_HASH_TABLE
    #undef POTTERY_OPEN_HASH_TABLE_REF_TYPE
    #undef POTTERY_OPEN_HASH_TABLE_VALUE_TYPE
    #undef POTTERY_OPEN_HASH_TABLE_CONTEXT_TYPE
    #undef POTTERY_OPEN_HASH_TABLE_ACCESS
    #undef POTTERY_OPEN_HASH_TABLE_BY_VALUE
//%%%!!! END_AUTOGENERATED



// unrename identifiers

#undef POTTERY_OPEN_HASH_TABLE_NAME

//!!! AUTOGENERATED:open_hash_table/unrename.t PREFIX:pottery_oht
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Un-renames open_hash_table identifiers with prefix "pottery_oht"

    #undef pottery_oht_ref_t
    #undef pottery_oht_value_t
    #undef pottery_oht_key_t
    #undef pottery_oht_context_t
    #undef pottery_oht_t

    #undef pottery_oht_configure
    #undef pottery_oht_count
    #undef pottery_oht_emplace
    #undef pottery_oht_find
    #undef pottery_oht_displace
    #undef pottery_oht_remove
    #undef pottery_oht_remove_key

    #undef pottery_oht_begin
    #undef pottery_oht_end
    #undef pottery_oht_first
    #undef pottery_oht_last
    #undef pottery_oht_next
    #undef pottery_oht_previous

    #undef pottery_oht_key
    #undef pottery_oht_access_at
    #undef pottery_oht_access_index
    #undef pottery_oht_key_hash
    #undef pottery_oht_key_equal
    #undef pottery_oht_double_hash_interval
    #undef pottery_oht_is_tombstone
    #undef pottery_oht_set_tombstone
    #undef pottery_oht_is_empty
    #undef pottery_oht_set_empty
    #undef pottery_oht_entry_in_use

    #undef pottery_oht_bucket_for_hash
    #undef pottery_oht_next_probe
    #undef pottery_oht_probe
//!!! END_AUTOGENERATED



// lifecycle functions

#undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_NAME

//!!! AUTOGENERATED:lifecycle/unrename.t PREFIX:pottery_oht_lifecycle
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.
    // Un-renames lifecycle identifiers with prefix "pottery_oht_lifecycle"

    // types
    #undef pottery_oht_lifecycle_ref_t
    #undef pottery_oht_lifecycle_const_ref_t
    #undef pottery_oht_lifecycle_value_t
    #undef pottery_oht_lifecycle_context_t

    // fundamental operations
    #undef pottery_oht_lifecycle_init_steal
    #undef pottery_oht_lifecycle_init_copy
    #undef pottery_oht_lifecycle_init
    #undef pottery_oht_lifecycle_destroy
    #undef pottery_oht_lifecycle_swap
    #undef pottery_oht_lifecycle_move
    #undef pottery_oht_lifecycle_steal
    #undef pottery_oht_lifecycle_copy

    // bulk operations
    #undef pottery_oht_lifecycle_move_bulk
    #undef pottery_oht_lifecycle_move_bulk_restrict
    #undef pottery_oht_lifecycle_move_bulk_restrict_impl
    #undef pottery_oht_lifecycle_move_bulk_up
    #undef pottery_oht_lifecycle_move_bulk_up_impl
    #undef pottery_oht_lifecycle_move_bulk_down
    #undef pottery_oht_lifecycle_move_bulk_down_impl
    #undef pottery_oht_lifecycle_destroy_bulk

    // C++
    #undef pottery_oht_lifecycle_construct
    #undef pottery_oht_lifecycle_assign
//!!! END_AUTOGENERATED

//!!! AUTOGENERATED:lifecycle/unconfigure.t PREFIX:POTTERY_OPEN_HASH_TABLE_LIFECYCLE
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    // Undefines (forwardable/forwarded) lifecycle configuration on POTTERY_OPEN_HASH_TABLE_LIFECYCLE

    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_BY_VALUE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_DESTROY
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_DESTROY_BY_VALUE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_INIT
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_INIT_BY_VALUE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_INIT_COPY
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_INIT_COPY_BY_VALUE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_INIT_STEAL
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_INIT_STEAL_BY_VALUE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_MOVE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_MOVE_BY_VALUE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_COPY
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_COPY_BY_VALUE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_STEAL
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_STEAL_BY_VALUE
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_SWAP
    #undef POTTERY_OPEN_HASH_TABLE_LIFECYCLE_SWAP_BY_VALUE
//!!! END_AUTOGENERATED



#include "pottery/platform/pottery_platform_pragma_pop.t.h"
