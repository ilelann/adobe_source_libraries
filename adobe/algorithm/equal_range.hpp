/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ALGORITHM_EQUAL_RANGE_HPP
#define ADOBE_ALGORITHM_EQUAL_RANGE_HPP

#include <adobe/config.hpp>

#include <algorithm>
#include <cassert>
#include <utility>
#include <functional>

#include <adobe/algorithm/lower_bound.hpp>
#include <adobe/algorithm/upper_bound.hpp>
#include <adobe/functional.hpp>

/*************************************************************************************************/

/*!
\defgroup equal_range equal_range
\ingroup sorting

\see
    - STL documentation for \ref stldoc_equal_range
*/

/*************************************************************************************************/

namespace adobe {
namespace implementation {

/*************************************************************************************************/

template <typename I, // I models ForwardIterator
          typename N, // N models IntegralType
          typename T, // T == result_type(P)
          typename C, // C models StrictWeakOrdering(T, T)
          typename P>
// P models UnaryFunction(value_type(I)) -> T
std::pair<I, I> equal_range_n(I f, N n, const T& x, C c, P p) {
    assert(!(n < 0) && "FATAL (sparent) : n must be >= 0");

    while (n != 0) {
        N h = n >> 1;
        I m = std::next(f, h);

        if (c(p(*m), x)) {
            f = std::next(m);
            n -= h + 1;
        } else if (c(x, p(*m))) {
            n = h;
        } else {
            return std::make_pair(
                implementation::lower_bound_n_(f, h, x, c, p),
                implementation::upper_bound_n(std::next(m), n - (h + 1), x, c, p));
        }
    }
    return std::make_pair(f, f);
}

/*************************************************************************************************/

} // namespace implementation

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardIterator
          typename N, // N models IntegralType
          typename T>
// T == result_type(P)
inline std::pair<I, I> equal_range_n(I f, N n, const T& x) {
    return implementation::equal_range_n(f, n, x, less(), identity<T>());
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardIterator
          typename N, // N models IntegralType
          typename T, // T == result_type(P)
          typename C>
// C models StrictWeakOrdering(T, T)
inline std::pair<I, I> equal_range_n(I f, N n, const T& x, C c) {
    return implementation::equal_range_n(f, n, x, std::bind(c, std::placeholders::_1, std::placeholders::_2), identity<T>());
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardIterator
          typename N, // N models IntegralType
          typename T, // T == result_type(P)
          typename C, // C models StrictWeakOrdering(T, T)
          typename P>
// P models UnaryFunction(value_type(I)) -> T
inline std::pair<I, I> equal_range_n(I f, N n, const T& x, C c, P p) {
    return implementation::equal_range_n(f, n, x, std::bind(c, std::placeholders::_1, std::placeholders::_2), std::bind(p, std::placeholders::_1));
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardIterator
          typename T>
// T == value_type(I)
inline std::pair<I, I> equal_range(I f, I l, const T& x) {
    return std::equal_range(f, l, x);
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardIterator
          typename T, // T == result_type(P)
          typename C>
// C models StrictWeakOrdering(T, T)
inline std::pair<I, I> equal_range(I f, I l, const T& x, C c) {
    return std::equal_range(f, l, x, std::bind(c, std::placeholders::_1, std::placeholders::_2));
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardIterator
          typename T, // T == result_type(P)
          typename C, // C models StrictWeakOrdering(T, T)
          typename P>
// P models UnaryFunction(value_type(I)) -> T
inline std::pair<I, I> equal_range(I f, I l, const T& x, C c, P p) {
    return equal_range_n(f, std::distance(f, l), x, c, p);
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardRange
          typename T, // T == result_type(P)
          typename C, // C models StrictWeakOrdering(T, T)
          typename P> // P models UnaryFunction(value_type(I)) -> T
inline auto
equal_range(I& r, const T& x, C c, P p, std::enable_if_t<!std::is_same<I, T>::value>* = 0) {
    return adobe::equal_range(std::begin(r), std::end(r), x, c, p);
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardRange
          typename T, // T == result_type(P)
          typename C, // C models StrictWeakOrdering(T, T)
          typename P> // P models UnaryFunction(value_type(I)) -> T
inline auto
equal_range(const I& r, const T& x, C c, P p, std::enable_if_t<!std::is_same<I, T>::value>* = 0) {
    return adobe::equal_range(std::begin(r), std::end(r), x, c, p);
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardRange
          typename T> // T == result_type(P)
inline auto
equal_range(I& r, const T& x) {
    return std::equal_range(std::begin(r), std::end(r), x);
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardRange
          typename T> // T == result_type(P)
inline auto
equal_range(const I& r, const T& x) {
    return std::equal_range(std::begin(r), std::end(r), x);
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardRange
          typename T, // T == result_type(P)
          typename C> // C models StrictWeakOrdering(T, T)
inline auto
equal_range(I& r, const T& x, C c, std::enable_if_t<!std::is_same<I, T>::value>* = 0) {
    return adobe::equal_range(std::begin(r), std::end(r), x, c);
}

/*************************************************************************************************/

/*!
    \ingroup equal_range
*/

template <typename I, // I models ForwardRange
          typename T, // T == result_type(P)
          typename C> // C models StrictWeakOrdering(T, T)
inline auto
equal_range(const I& r, const T& x, C c, std::enable_if_t<!std::is_same<I, T>::value>* = 0) {
    return adobe::equal_range(std::begin(r), std::end(r), x, c);
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif

/*************************************************************************************************/
