/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ALGORITHM_REVERSE_HPP
#define ADOBE_ALGORITHM_REVERSE_HPP

#include <adobe/config.hpp>

#include <adobe/iterator/set_next.hpp>

#include <algorithm>
#include <utility>

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/
/*!
\defgroup reverse reverse
\ingroup mutating_algorithm

\see
    - STL documentation for \ref stldoc_reverse
    - STL documentation for \ref stldoc_reverse_copy
*/
/*************************************************************************************************/

namespace unsafe {

/*************************************************************************************************/

/*!
\ingroup node_algorithm
*/
template <typename I> // I models NodeIterator
I reverse_append(I first, I last, I result) {
    while (first != last) {
        I prior(first);
        ++first;
        adobe::unsafe::set_next(prior, result);
        result = prior;
    }
    return result;
}

/*!
\ingroup node_algorithm
*/
template <typename R, // R models NodeRange
          typename I>
// I models NodeIterator
inline I reverse_append(R& range, I result) {
    return adobe::unsafe::reverse_append(std::begin(range), std::end(range), result);
}

/*!
\ingroup node_algorithm
*/
template <typename I> // I models NodeIterator
inline I reverse_nodes(I first, I last) {
    return adobe::unsafe::reverse_append(first, last, last);
}

/*!
\ingroup node_algorithm
*/
template <typename R> // R models NodeRange
inline auto reverse_nodes(R& range) {
    return adobe::unsafe::reverse_nodes(std::begin(range), std::end(range));
}

/*************************************************************************************************/

} // namspace unsafe

/*************************************************************************************************/
/*!
    \ingroup reverse

    \brief reverse implementation
*/
template <class BidirectionalRange>
inline void reverse(BidirectionalRange& range) {
    std::reverse(std::begin(range), std::end(range));
}

/*!
    \ingroup reverse

    \brief reverse implementation
*/
template <class BidirectionalRange, class OutputIterator>
inline void reverse_copy(BidirectionalRange& range, OutputIterator result) {
    std::reverse_copy(std::begin(range), std::end(range), result);
}

/*!
    \ingroup reverse

    \brief reverse implementation
*/
template <class BidirectionalRange, class OutputIterator>
inline void reverse_copy(const BidirectionalRange& range, OutputIterator result) {
    std::reverse_copy(std::begin(range), std::end(range), result);
}

/*************************************************************************************************/
/*!
    \ingroup reverse

    \brief reverse implementation
*/
template <typename I> // I models Bidirectional Iterator
std::pair<I, I> reverse_until(I f, I m, I l) {
    while (f != m && m != l) {
        --l;

        std::iter_swap(f, l);

        ++f;
    }

    return std::pair<I, I>(f, l);
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif

/*************************************************************************************************/
