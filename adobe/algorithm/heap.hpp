/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ALGORITHM_HEAP_HPP
#define ADOBE_ALGORITHM_HEAP_HPP

#include <adobe/config.hpp>

#include <algorithm>
#include <functional>

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/
/*!
\defgroup heap heap operations
\ingroup sorting

\see
    - STL documentation for \ref stldoc_push_heap
    - STL documentation for \ref stldoc_pop_heap
    - STL documentation for \ref stldoc_make_heap
    - STL documentation for \ref stldoc_sort_heap
*/
/*************************************************************************************************/
/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessRange>
inline void push_heap(RandomAccessRange& range) {
    return std::push_heap(std::begin(range), std::end(range));
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessIterator, class Compare>
inline void push_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    return std::push_heap(first, last, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessRange, class Compare>
inline void push_heap(RandomAccessRange& range, Compare comp) {
    return adobe::push_heap(std::begin(range), std::end(range), comp);
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessRange>
inline void pop_heap(RandomAccessRange& range) {
    return std::pop_heap(std::begin(range), std::end(range));
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessIterator, class Compare>
inline void pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    return std::pop_heap(first, last, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessRange, class Compare>
inline void pop_heap(RandomAccessRange& range, Compare comp) {
    return adobe::pop_heap(std::begin(range), std::end(range), comp);
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessRange>
inline void make_heap(RandomAccessRange& range) {
    return std::make_heap(std::begin(range), std::end(range));
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessIterator, class Compare>
inline void make_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    return std::make_heap(first, last, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessRange, class Compare>
inline void make_heap(RandomAccessRange& range, Compare comp) {
    return adobe::make_heap(std::begin(range), std::end(range), comp);
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessRange>
inline void sort_heap(RandomAccessRange& range) {
    return std::sort_heap(std::begin(range), std::end(range));
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessIterator, class Compare>
inline void sort_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    return std::sort_heap(first, last, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup heap

    \brief heap implementation
*/
template <class RandomAccessRange, class Compare>
inline void sort_heap(RandomAccessRange& range, Compare comp) {
    return adobe::sort_heap(std::begin(range), std::end(range), comp);
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif

/*************************************************************************************************/
