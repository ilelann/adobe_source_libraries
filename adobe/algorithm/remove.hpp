/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ALGORITHM_REMOVE_HPP
#define ADOBE_ALGORITHM_REMOVE_HPP

#include <adobe/config.hpp>

#include <algorithm>
#include <functional>

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/
/*!
\defgroup remove remove
\ingroup mutating_algorithm

\see
    - STL documentation for \ref stldoc_remove
    - STL documentation for \ref stldoc_remove_if
    - STL documentation for \ref stldoc_remove_copy
    - STL documentation for \ref stldoc_remove_copy_if
*/
/*************************************************************************************************/
/*!
    \ingroup remove

    \brief remove implementation
*/
template <class InputRange, class T>
inline auto remove(InputRange& range, const T& value) {
    return std::remove(std::begin(range), std::end(range), value);
}

/*!
    \ingroup remove

    \brief remove implementation
*/
template <class InputIterator, class Predicate>
inline InputIterator remove_if(InputIterator first, InputIterator last, Predicate pred) {
    return std::remove_if(first, last, std::bind(pred, std::placeholders::_1));
}

/*!
    \ingroup remove

    \brief remove implementation
*/
template <class InputRange, class Predicate>
inline auto remove_if(InputRange& range,
                                                                  Predicate pred) {
    return adobe::remove_if(std::begin(range), std::end(range), pred);
}

/*!
    \ingroup remove

    \brief remove implementation
*/
template <class InputRange, class OutputIterator, class T>
inline auto
remove_copy(InputRange& range, OutputIterator result, const T& value) {
    return std::remove_copy(std::begin(range), std::end(range), result, value);
}

/*!
    \ingroup remove

    \brief remove implementation
*/
template <class InputRange, class OutputIterator, class T>
inline auto
remove_copy(const InputRange& range, OutputIterator result, const T& value) {
    return std::remove_copy(std::begin(range), std::end(range), result, value);
}

/*!
    \ingroup remove

    \brief remove implementation
*/
template <class InputIterator, class OutputIterator, class Predicate>
inline InputIterator remove_copy_if(InputIterator first, InputIterator last, OutputIterator result,
                                    Predicate pred) {
    return std::remove_copy_if(first, last, result, std::bind(pred, std::placeholders::_1));
}

/*!
    \ingroup remove

    \brief remove implementation
*/
template <class InputRange, class OutputIterator, class Predicate>
inline auto
remove_copy_if(InputRange& range, OutputIterator result, Predicate pred) {
    return adobe::remove_copy_if(std::begin(range), std::end(range), result, pred);
}

/*!
    \ingroup remove

    \brief remove implementation
*/
template <class InputRange, class OutputIterator, class Predicate>
inline auto
remove_copy_if(const InputRange& range, OutputIterator result, Predicate pred) {
    return adobe::remove_copy_if(std::begin(range), std::end(range), result, pred);
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif

/*************************************************************************************************/
