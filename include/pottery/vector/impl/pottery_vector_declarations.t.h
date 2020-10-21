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

typedef POTTERY_VECTOR_ELEMENT_TYPE pottery_vector_element_t;

typedef pottery_vector_element_t* pottery_vector_entry_t;

typedef struct pottery_vector_t {
    pottery_vector_element_t* values;
    size_t count;

    union {
        size_t capacity;
        #if POTTERY_VECTOR_INTERNAL_CAPACITY > 0
        pottery_vector_element_t internal[POTTERY_VECTOR_INTERNAL_CAPACITY];
        #endif
    } u;

    #ifdef POTTERY_DEBUG
    struct pottery_vector_t* self_check;
    void* leak_check;
    #endif

    #if defined(POTTERY_VECTOR_ALLOC_CONTEXT_TYPE) && !defined(POTTERY_VECTOR_ALLOC_CONTEXT)
    pottery_vector_alloc_context_t alloc_context;
    #endif
} pottery_vector_t;



/*
 * Forward Declarations
 */

#if POTTERY_FORWARD_DECLARATIONS
POTTERY_VECTOR_EXTERN
pottery_error_t pottery_vector_impl_create_space(pottery_vector_t* vector, size_t index,
        size_t count, pottery_vector_element_t** elements);

POTTERY_VECTOR_EXTERN
void pottery_vector_impl_remove_space(pottery_vector_t* vector, size_t index, size_t count);

static inline
pottery_vector_entry_t pottery_vector_end(pottery_vector_t* vector);

static inline
pottery_vector_entry_t pottery_vector_begin(pottery_vector_t* vector);
#endif


/*
 * Lifecycle Operations
 */

static inline
pottery_error_t pottery_vector_init(pottery_vector_t* vector) {
    vector->count = 0;

    #if POTTERY_VECTOR_INTERNAL_CAPACITY > 0
    vector->values = vector->u.internal;
    #else
    vector->values = pottery_null;
    vector->u.capacity = 0;
    #endif

    return POTTERY_OK;
}

#if POTTERY_FORWARD_DECLARATIONS
POTTERY_VECTOR_EXTERN
void pottery_vector_destroy(pottery_vector_t* vector);

POTTERY_VECTOR_EXTERN
void pottery_vector_move(pottery_vector_t* to, pottery_vector_t* from);
#endif

#ifdef POTTERY_VECTOR_ALLOC_CONTEXT_TYPE
static inline pottery_vector_alloc_context(pottery_vector_t* vector) {
    #if defined(POTTERY_VECTOR_ALLOC_CONTEXT)
    return POTTERY_VECTOR_ALLOC_CONTEXT(vector);
    #else
    return vector->alloc_context;
    #endif
}

#if !defined(POTTERY_VECTOR_ALLOC_CONTEXT)
static inline
void pottery_vector_set_alloc_context(pottery_vector_t* vector, pottery_vector_alloc_context_t* context) {
    vector->alloc_context = context;
}
#endif
#endif

static inline
size_t pottery_vector_count(const pottery_vector_t* vector) {
    return vector->count;
}

static inline
bool pottery_vector_is_empty(const pottery_vector_t* vector) {
    return vector->count == 0;
}

static inline
size_t pottery_vector_capacity(const pottery_vector_t* vector) {
    #if POTTERY_VECTOR_INTERNAL_CAPACITY > 0
    if (vector->values == vector->u.internal)
        return POTTERY_VECTOR_INTERNAL_CAPACITY;
    #endif
    return vector->u.capacity;
}

// TODO implement this
//void pottery_vector_shrink(pottery_vector_t* vector);

static inline
pottery_vector_entry_t pottery_vector_at(const pottery_vector_t* vector, size_t index) {
    pottery_assert(index < vector->count);
    return vector->values + index;
}

// TODO should rename this so that const_data is just data and data is
// mutable_data. const should be default. and maybe instead of data, it should
// be values or elements or something

static inline
pottery_vector_element_t* pottery_vector_data(pottery_vector_t* vector) {
    return vector->values;
}

static inline
const pottery_vector_element_t* pottery_vector_const_data(const pottery_vector_t* vector) {
    return vector->values;
}



/*
 * Miscellaneous
 */

#if POTTERY_FORWARD_DECLARATIONS
POTTERY_VECTOR_EXTERN
pottery_error_t pottery_vector_reserve(pottery_vector_t* vector, size_t count);
#endif



/*
 * Entry Operations
 */

/**
 * Returns the index of the entry in the vector.
 */
static inline
size_t pottery_vector_entry_index(pottery_vector_t* vector, pottery_vector_entry_t* entry) {
    return pottery_cast(size_t, *entry - pottery_vector_begin(vector));
}

/**
 * Returns true if the entry exists, false otherwise.
 */
static inline
bool pottery_vector_entry_exists(pottery_vector_t* vector, pottery_vector_entry_t* entry) {
    return *entry != pottery_vector_end(vector);
}

/**
 * Returns true if the entries are equal, false otherwise.
 */
static inline
bool pottery_vector_entry_equal(pottery_vector_t* vector, pottery_vector_entry_t* left,
        pottery_vector_entry_t* right)
{
    (void)vector;
    return *left == *right;
}

/**
 * Returns the element pointed to by this entry.
 */
static inline
pottery_vector_element_t* pottery_vector_entry_element(pottery_vector_t* vector, pottery_vector_entry_t* entry) {
    (void)vector;
    pottery_assert(pottery_vector_entry_exists(vector, entry));
    return *entry;
}



#if POTTERY_FORWARD_DECLARATIONS

POTTERY_VECTOR_EXTERN
pottery_error_t pottery_vector_emplace_at(pottery_vector_t* vector, size_t index, pottery_vector_entry_t* entry);

POTTERY_VECTOR_EXTERN
void pottery_vector_displace_all(pottery_vector_t* vector);

POTTERY_VECTOR_EXTERN
pottery_error_t pottery_vector_emplace_at_bulk(pottery_vector_t* vector, size_t index, size_t count, pottery_vector_entry_t* entry);

#if POTTERY_LIFECYCLE_CAN_PASS
POTTERY_VECTOR_EXTERN
pottery_error_t pottery_vector_insert_at_bulk(pottery_vector_t* vector, size_t index, const pottery_vector_element_t* values, size_t count);

static inline
pottery_error_t pottery_vector_insert_first_bulk(pottery_vector_t* vector, const pottery_vector_element_t* values, size_t count) {
    return pottery_vector_insert_at_bulk(vector, 0, values, count);
}

static inline
pottery_error_t pottery_vector_insert_last_bulk(pottery_vector_t* vector, const pottery_vector_element_t* values, size_t count) {
    return pottery_vector_insert_at_bulk(vector, pottery_vector_count(vector), values, count);
}
#endif

POTTERY_VECTOR_EXTERN
void pottery_vector_displace_at_bulk(pottery_vector_t* vector, size_t index, size_t count);

POTTERY_VECTOR_EXTERN
void pottery_vector_swap(pottery_vector_t* left, pottery_vector_t* right);

POTTERY_VECTOR_EXTERN
void pottery_vector_init_steal(pottery_vector_t* vector, pottery_vector_t* other);

POTTERY_VECTOR_EXTERN
void pottery_vector_steal(pottery_vector_t* vector, pottery_vector_t* other);

#if POTTERY_LIFECYCLE_CAN_INIT_COPY
POTTERY_VECTOR_EXTERN
pottery_error_t pottery_vector_init_copy(pottery_vector_t* vector, const pottery_vector_t* other);
#endif

#if POTTERY_LIFECYCLE_CAN_INIT_COPY && POTTERY_LIFECYCLE_CAN_DESTROY
POTTERY_VECTOR_EXTERN
pottery_error_t pottery_vector_copy(pottery_vector_t* vector, const pottery_vector_t* other);
#endif

#endif // POTTERY_FORWARD_DECLARATIONS

#ifdef __cplusplus
template<class... Args> static inline
pottery_error_t pottery_vector_construct_at(pottery_vector_t* vector, size_t index, pottery_vector_entry_t* entry, Args&&... args) {
    pottery_error_t error = pottery_vector_impl_create_space(vector, index, 1, entry);
    if (error != POTTERY_OK)
        return error;

    error = pottery_vector_element_construct(*entry, std::forward<Args>(args)...);
    if (error != POTTERY_OK)
        pottery_vector_impl_remove_space(vector, index, 1);
    return error;
}

template<class... Args> static inline
pottery_error_t pottery_vector_construct_first(pottery_vector_t* vector, pottery_vector_entry_t* entry, Args&&... args) {
    return pottery_vector_construct_at(vector, 0, entry, std::forward<Args>(args)...);
}

template<class... Args> static inline
pottery_error_t pottery_vector_construct_last(pottery_vector_t* vector, pottery_vector_entry_t* entry, Args&&... args) {
    return pottery_vector_construct_at(vector, vector->count, entry, std::forward<Args>(args)...);
}
#endif



/*
 * Insert
 */

#if POTTERY_LIFECYCLE_CAN_PASS

#ifdef __cplusplus

// C++ non-const reference
// (Not a const reference, this is not a copy. See container API documentation on Insert.)

static inline
pottery_error_t pottery_vector_insert_at(pottery_vector_t* vector, size_t index, pottery_vector_element_t& value) {
    pottery_vector_entry_t entry;
    pottery_error_t error = pottery_vector_impl_create_space(vector, index, 1, &entry);
    if (error == POTTERY_OK)
        pottery_vector_element_init_steal(entry, &value);
    pottery_vector_element_destroy(&value);
    return error;
}

static inline
pottery_error_t pottery_vector_insert_first(pottery_vector_t* vector, pottery_vector_element_t& value) {
    return pottery_vector_insert_at(vector, 0, value);
}

static inline
pottery_error_t pottery_vector_insert_last(pottery_vector_t* vector, pottery_vector_element_t& value) {
    return pottery_vector_insert_at(vector, vector->count, value);
}

static inline
pottery_error_t pottery_vector_insert_before(pottery_vector_t* vector,
        pottery_vector_entry_t* entry, pottery_vector_element_t& value)
{
    size_t index = pottery_vector_entry_index(vector, entry);
    return pottery_vector_insert_at(vector, index, value);
}

static inline
pottery_error_t pottery_vector_insert_after(pottery_vector_t* vector,
        pottery_vector_entry_t* entry, pottery_vector_element_t& value)
{
    pottery_assert(pottery_vector_entry_exists(vector, entry));
    size_t index = pottery_vector_entry_index(vector, entry);
    return pottery_vector_insert_at(vector, index + 1, value);
}

// C++ rvalue reference

static inline
pottery_error_t pottery_vector_insert_at(pottery_vector_t* vector, size_t index, pottery_vector_element_t&& value) {
    pottery_vector_entry_t entry;
    pottery_error_t error = pottery_vector_impl_create_space(vector, index, 1, &entry);
    if (error == POTTERY_OK)
        pottery_vector_element_init_steal(entry, &value);
    pottery_vector_element_destroy(&value);
    return error;
}

static inline
pottery_error_t pottery_vector_insert_first(pottery_vector_t* vector, pottery_vector_element_t&& value) {
    return pottery_vector_insert_at(vector, 0, std::move(value));
}

static inline
pottery_error_t pottery_vector_insert_last(pottery_vector_t* vector, pottery_vector_element_t&& value) {
    return pottery_vector_insert_at(vector, vector->count, std::move(value));
}

static inline
pottery_error_t pottery_vector_insert_before(pottery_vector_t* vector,
        pottery_vector_entry_t* entry, pottery_vector_element_t&& value)
{
    size_t index = pottery_vector_entry_index(vector, entry);
    return pottery_vector_insert_at(vector, index, std::move(value));
}

static inline
pottery_error_t pottery_vector_insert_after(pottery_vector_t* vector,
        pottery_vector_entry_t* entry, pottery_vector_element_t&& value)
{
    pottery_assert(pottery_vector_entry_exists(vector, entry));
    size_t index = pottery_vector_entry_index(vector, entry);
    return pottery_vector_insert_at(vector, index + 1, std::move(value));
}

#else

// C by value

static inline
pottery_error_t pottery_vector_insert_at(pottery_vector_t* vector, size_t index, pottery_vector_element_t value) {
    pottery_vector_entry_t entry;
    pottery_error_t error = pottery_vector_impl_create_space(vector, index, 1, &entry);
    if (error == POTTERY_OK)
        *entry = value;
    else
        pottery_vector_element_destroy(&value);
    return error;
}

static inline
pottery_error_t pottery_vector_insert_first(pottery_vector_t* vector, pottery_vector_element_t value) {
    return pottery_vector_insert_at(vector, 0, value);
}

static inline
pottery_error_t pottery_vector_insert_last(pottery_vector_t* vector, pottery_vector_element_t value) {
    return pottery_vector_insert_at(vector, vector->count, value);
}

static inline
pottery_error_t pottery_vector_insert_before(pottery_vector_t* vector,
        pottery_vector_entry_t* entry, pottery_vector_element_t value)
{
    size_t index = pottery_vector_entry_index(vector, entry);
    return pottery_vector_insert_at(vector, index, value);
}

static inline
pottery_error_t pottery_vector_insert_after(pottery_vector_t* vector,
        pottery_vector_entry_t* entry, pottery_vector_element_t value)
{
    pottery_assert(pottery_vector_entry_exists(vector, entry));
    size_t index = pottery_vector_entry_index(vector, entry);
    return pottery_vector_insert_at(vector, index + 1, value);
}

#endif // C++ overloads

#endif // CAN_PASS



#if POTTERY_LIFECYCLE_CAN_PASS
static inline
pottery_error_t pottery_vector_insert_vector(pottery_vector_t* vector, size_t index, pottery_vector_t* other) {
    return pottery_vector_insert_at_bulk(vector, index, pottery_vector_begin(other), pottery_vector_count(other));
}

static inline
pottery_error_t pottery_vector_insert_last_vector(pottery_vector_t* vector, pottery_vector_t* other) {
    return pottery_vector_insert_vector(vector, pottery_vector_count(vector), other);
}
#endif

/**
 * Returns the first element in the vector.
 *
 * The vector must have at least one element!
 */
static inline
pottery_vector_entry_t pottery_vector_first(pottery_vector_t* vector) {
    pottery_assert(vector->count > 0);
    return vector->values;
}

/**
 * Returns the last element in the vector.
 *
 * The vector must have at least one element!
 */
static inline
pottery_vector_entry_t pottery_vector_last(pottery_vector_t* vector) {
    pottery_assert(vector->count > 0);
    return vector->values + pottery_vector_count(vector) - 1;
}



/*
 * Iteration
 */

/**
 * Returns a pointer to the start of the vector (the first element if it has
 * any elements, or the end of the vector otherwise.)
 *
 * If the vector is empty, the returned entry does not exist, and is equal to
 * pottery_vector_end().
 */
static inline
pottery_vector_entry_t pottery_vector_begin(pottery_vector_t* vector) {
    return vector->values;
}

/**
 * Returns a pointer to the end of the vector (one past the last element in the
 * vector.)
 *
 * If the vector is empty, the returned entry does not exist, and is equal to
 * pottery_vector_end().
 */
static inline
pottery_vector_entry_t pottery_vector_end(pottery_vector_t* vector) {
    return vector->values + pottery_vector_count(vector);
}

/**
 * Returns the next element, or the end of the vector.
 */
static inline
void pottery_vector_next(pottery_vector_t* vector, pottery_vector_entry_t* value) {
    (void)vector;
    // the value is allow to point one past the end.
    pottery_assert((size_t)(*value - pottery_vector_begin(vector)) < pottery_vector_count(vector));
    (*value)++;
}

/**
 * Returns the previous element, which must exist.
 *
 * It is an error to call this on the first element!
 */
static inline
void pottery_vector_previous(pottery_vector_t* vector, pottery_vector_entry_t* value) {
    (void)vector;
    pottery_assert(*value != pottery_vector_begin(vector));
    (*value)--;
}



/*
 * Emplace
 */

static inline
pottery_error_t pottery_vector_emplace_last(pottery_vector_t* vector, pottery_vector_entry_t* entry) {
    return pottery_vector_emplace_at(vector, pottery_vector_count(vector), entry);
}

static inline
pottery_error_t pottery_vector_emplace_first_bulk(pottery_vector_t* vector,
        size_t count, pottery_vector_entry_t* entry)
{
    return pottery_vector_emplace_at_bulk(vector, 0, count, entry);
}

static inline
pottery_error_t pottery_vector_emplace_last_bulk(pottery_vector_t* vector,
        size_t count, pottery_vector_entry_t* entry)
{
    return pottery_vector_emplace_at_bulk(vector, pottery_vector_count(vector), count, entry);
}



/*
 * Displace
 */

static inline
void pottery_vector_displace_at(pottery_vector_t* vector, size_t index) {
    pottery_vector_displace_at_bulk(vector, index, 1);
}

static inline
void pottery_vector_displace(pottery_vector_t* vector, pottery_vector_entry_t* entry) {
    pottery_vector_displace_at(vector, pottery_vector_entry_index(vector, entry));
}



/*
 * Remove
 */

#if POTTERY_LIFECYCLE_CAN_DESTROY
#if POTTERY_FORWARD_DECLARATIONS
POTTERY_VECTOR_EXTERN
void pottery_vector_remove_at(pottery_vector_t* vector, size_t index);

POTTERY_VECTOR_EXTERN
void pottery_vector_remove_all(pottery_vector_t* vector);

POTTERY_VECTOR_EXTERN
void pottery_vector_remove_at_bulk(pottery_vector_t* vector, size_t index, size_t count);
#endif // forward decls

static inline
void pottery_vector_remove(pottery_vector_t* vector, pottery_vector_entry_t* entry) {
    pottery_vector_remove_at(vector, pottery_vector_entry_index(vector, entry));
}

static inline
void pottery_vector_remove_first(pottery_vector_t* vector) {
    pottery_assert(!pottery_vector_is_empty(vector));
    pottery_vector_remove_at(vector, 0);
}

static inline
void pottery_vector_remove_last(pottery_vector_t* vector) {
    pottery_assert(!pottery_vector_is_empty(vector));
    pottery_vector_remove_at(vector, pottery_vector_count(vector) - 1);
}
#endif // CAN_DESTROY



/*
 * Extract
 */

#if POTTERY_LIFECYCLE_CAN_PASS
static inline
pottery_vector_element_t pottery_vector_extract(pottery_vector_t* vector,
        pottery_vector_entry_t* entry)
{
    pottery_vector_element_t element = *pottery_vector_entry_element(vector, entry);
    //pottery_vector_remove(vector, entry); // TODO use this once implemented
    pottery_vector_remove_at(vector, pottery_vector_entry_index(vector, entry));
    return element;
}

static inline
pottery_vector_element_t pottery_vector_extract_at(pottery_vector_t* vector, size_t index) {
    pottery_vector_entry_t entry = pottery_vector_at(vector, index);
    pottery_vector_element_t element = *pottery_vector_entry_element(vector, &entry);
    pottery_vector_remove_at(vector, index);
    return element;
}

static inline
pottery_vector_element_t pottery_vector_extract_first(pottery_vector_t* vector) {
    pottery_assert(!pottery_vector_is_empty(vector));
    return pottery_vector_extract_at(vector, 0);
}

static inline
pottery_vector_element_t pottery_vector_extract_last(pottery_vector_t* vector) {
    pottery_assert(!pottery_vector_is_empty(vector));
    return pottery_vector_extract_at(vector, pottery_vector_count(vector) - 1);
}
#endif