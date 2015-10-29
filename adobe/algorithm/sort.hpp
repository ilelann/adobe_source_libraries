/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ALGORITHM_SORT_HPP
#define ADOBE_ALGORITHM_SORT_HPP

#include <adobe/config.hpp>

#include <algorithm>
#include <functional>

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/
/*!
\defgroup sort sort
\ingroup sorting

\see
    - STL documentation for \ref stldoc_sort
    - STL documentation for \ref stldoc_stable_sort
    - STL documentation for \ref stldoc_partial_sort_copy
*/
/*************************************************************************************************/
/*!
    \ingroup sort

    \brief sort implementation
*/
template <class RandomAccessRange>
inline void sort(RandomAccessRange& range) {
    return std::sort(std::begin(range), std::end(range));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class RandomAccessIterator, class Compare>
inline void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    return std::sort(first, last, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <typename I, // I models RandomAccessIterator
          typename C, // C models StrictWeakOrdering(T, T)
          typename P>
// P models UnaryFunction(value_type(I)) -> T
inline void sort(I f, I l, C c, P p) {
    return std::sort(f, l, std::bind(c, std::bind(p, std::placeholders::_1),
                                     std::bind(p, std::placeholders::_2)));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <typename R, // I models RandomAccessRange
          typename C, // C models StrictWeakOrdering(T, T)
          typename P>
// P models UnaryFunction(value_type(I)) -> T
inline void sort(R& r, C c, P p) {
    return adobe::sort(
        std::begin(r), std::end(r),
        std::bind(c, std::bind(p, std::placeholders::_1), std::bind(p, std::placeholders::_2)));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class RandomAccessRange, class Compare>
inline void sort(RandomAccessRange& range, Compare comp) {
    return adobe::sort(std::begin(range), std::end(range), comp);
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class RandomAccessRange>
inline void stable_sort(RandomAccessRange& range) {
    return std::stable_sort(std::begin(range), std::end(range));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class RandomAccessIterator, class Compare>
inline void stable_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    return std::stable_sort(first, last,
                            std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class RandomAccessRange, class Compare>
inline void stable_sort(RandomAccessRange& range, Compare comp) {
    return adobe::stable_sort(std::begin(range), std::end(range), comp);
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class InputRange, class RandomAccessRange>
inline void partial_sort_copy(InputRange& range, RandomAccessRange& result_range) {
    return std::partial_sort_copy(std::begin(range), std::end(range),
                                  std::begin(result_range), std::end(result_range));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class InputRange, class RandomAccessRange>
inline void partial_sort_copy(const InputRange& range, RandomAccessRange& result_range) {
    return std::partial_sort_copy(std::begin(range), std::end(range),
                                  std::begin(result_range), std::end(result_range));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class InputIterator, class RandomAccessIterator, class Compare>
inline void partial_sort_copy(InputIterator first, InputIterator last,
                              RandomAccessIterator result_first, RandomAccessIterator result_last,
                              Compare comp) {
    return std::partial_sort_copy(first, last, result_first, result_last,
                                  std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class InputRange, class RandomAccessRange, class Compare>
inline void partial_sort_copy(InputRange& range, RandomAccessRange& result_range, Compare comp) {
    return adobe::partial_sort_copy(std::begin(range), std::end(range),
                                    std::begin(result_range), std::end(result_range), comp);
}

/*!
    \ingroup sort

    \brief sort implementation
*/
template <class InputRange, class RandomAccessRange, class Compare>
inline void partial_sort_copy(const InputRange& range, RandomAccessRange& result_range,
                              Compare comp) {
    return adobe::partial_sort_copy(std::begin(range), std::end(range),
                                    std::begin(result_range), std::end(result_range), comp);
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif

/*************************************************************************************************/
