/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ALGORITHM_COUNT_HPP
#define ADOBE_ALGORITHM_COUNT_HPP

#include <adobe/config.hpp>

#include <algorithm>
#include <functional>

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/
/*!
\defgroup count count
\ingroup non_mutating_algorithm

\see
    - STL documentation for \ref stldoc_count
    - STL documentation for \ref stldoc_count_if
*/
/*************************************************************************************************/
/*!
    \ingroup count

    \brief count implementation
*/
template <class InputRange, class T>
inline auto count(InputRange& range, T& value) {
    return std::count(std::begin(range), std::end(range), value);
}

/*!
    \ingroup count

    \brief count implementation
*/
template <class InputRange, class T>
inline auto count(const InputRange& range, T& value) {
    return std::count(std::begin(range), std::end(range), value);
}

/*!
    \ingroup count

    \brief count implementation
*/
template <class InputIterator, class Predicate>
inline typename std::iterator_traits<InputIterator>::difference_type
count_if(InputIterator first, InputIterator last, Predicate pred) {
    return std::count_if(first, last, std::bind(pred, std::placeholders::_1));
}

/*!
    \ingroup count

    \brief count implementation
*/
template <class InputRange, class Predicate>
inline auto count_if(InputRange& range,
                                                                   Predicate pred) {
    return adobe::count_if(std::begin(range), std::end(range), pred);
}

/*!
    \ingroup count

    \brief count implementation
*/
template <class InputRange, class Predicate>
inline auto count_if(const InputRange& range,
                                                                   Predicate pred) {
    return adobe::count_if(std::begin(range), std::end(range), pred);
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif

/*************************************************************************************************/
