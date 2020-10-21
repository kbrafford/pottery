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

#ifndef POTTERY_CXX_HEAP_SORT_HXX
#define POTTERY_CXX_HEAP_SORT_HXX

/*
 * Wraps Pottery's heap_sort in a C++ template.
 *
 * Use pottery::heap_sort() as a mostly drop-in replacement for std::sort()
 * with a few caveats:
 *
 * - Heap sort has safe worst case behaviour and relatively small code size but
 *   is generally much slower than algorithms like quick sort or intro sort.
 *   Your std::sort() is probably much faster with the same worst case time.
 *
 * - Throwing move and throwing swap are not supported. If a move constructor
 *   or swap throws, the program aborts. It is strongly recommended that your
 *   move constructor be marked noexcept.
 */

//!!! AUTOGENERATED:cxx/sort.t lower_name:heap_sort UPPER_NAME:HEAP_SORT
    // This block is auto-generated. Do not modify until END_AUTOGENERATED.

    #include "pottery_cxx/pottery_cxx_dependencies.hxx"

    namespace pottery {

    namespace detail {

    #undef POTTERY_FORWARD_DECLARATIONS
    #define POTTERY_FORWARD_DECLARATIONS 0

    template <typename RandomAccessIterator, typename Less>
    struct heap_sort_wrapper {
        typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

        #define POTTERY_HEAP_SORT_PREFIX heap_sort
        #define POTTERY_HEAP_SORT_VALUE_TYPE value_type
        #define POTTERY_HEAP_SORT_CONTEXT_TYPE RandomAccessIterator
        #define POTTERY_HEAP_SORT_LIFECYCLE_MOVE_BY_VALUE 1
        #define POTTERY_HEAP_SORT_COMPARE_CONTEXT_TYPE Less
        #define POTTERY_HEAP_SORT_COMPARE_LESS(less, left, right) less(*left, *right)
        #include "pottery/heap_sort/pottery_heap_sort_static.t.h"
    };

    #undef POTTERY_FORWARD_DECLARATIONS
    #define POTTERY_FORWARD_DECLARATIONS 1

    } // namespace detail

    template <typename RandomAccessIterator>
    inline void heap_sort(RandomAccessIterator first, RandomAccessIterator last) {
        typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
        typedef typename std::less<value_type> Less;
        size_t count = pottery_cast(size_t, last - first);
        detail::heap_sort_wrapper<RandomAccessIterator, Less>::heap_sort(first, count, Less());
    }

    template <typename RandomAccessIterator, typename Less>
    inline void heap_sort(RandomAccessIterator first, RandomAccessIterator last, Less less) {
        size_t count = pottery_cast(size_t, last - first);
        detail::heap_sort_wrapper<RandomAccessIterator, Less>::heap_sort(first, count, less);
    }

    } // namespace pottery
//!!! END_AUTOGENERATED

#endif