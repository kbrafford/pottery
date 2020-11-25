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

#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#include "../string/string.h"



/*
 * Platform stuff
 */

#define clayfish_always_inline __attribute__((__always_inline__)) inline

#define clayfish_array_count(x) (sizeof(x)/sizeof(*(x)))

#if defined(DEBUG) && defined(__SANITIZE_ADDRESS__)
    __attribute__((__noreturn__))
    static inline void clayfish_abort() {
        // crash instead of abort to get an ASAN stack trace
        *((int*)0)=1;
        abort();
    }
#else
    #define clayfish_abort() abort()
#endif

#ifdef DEBUG
    #define clayfish_assert(x) ((x) ? clayfish_abort() : (void)0)
#else
    #define clayfish_assert(x) /*nothing*/
#endif



/*
 * Score
 */

typedef int32_t score_t;

// Zero-ply mates. Add/subtract 1 per ply.
static const int32_t score_mate_by_white = 1000000;
static const int32_t score_mate_by_black = -score_mate_by_white;

static inline bool score_is_mate_by_white(score_t score) {
    return score > score_mate_by_white - 100000;
}

static inline bool score_is_mate_by_black(score_t score) {
    return score < score_mate_by_black + 100000;
}

#endif
