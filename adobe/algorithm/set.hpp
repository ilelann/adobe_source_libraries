/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ALGORITHM_SET_HPP
#define ADOBE_ALGORITHM_SET_HPP

#include <adobe/config.hpp>

#include <algorithm>
#include <functional>

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/
/*!
\defgroup set set operations on sorted ranges
\ingroup sorting

\see
    - STL documentation for \ref stldoc_includes
    - STL documentation for \ref stldoc_set_union
    - STL documentation for \ref stldoc_set_intersection
    - STL documentation for \ref stldoc_set_difference
    - STL documentation for \ref stldoc_set_symmetric_difference
*/
/*************************************************************************************************/
/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2>
inline bool includes(const InputRange1& range1, const InputRange2& range2) {
    return std::includes(std::begin(range1), std::end(range1), std::begin(range2),
                         std::end(range2));
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputIterator1, class InputIterator2, class Compare>
inline bool includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                     InputIterator2 last2, Compare comp) {
    return std::includes(first1, last1, first2, last2, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class Compare>
inline bool includes(const InputRange1& range1, const InputRange2& range2, Compare comp) {
    return adobe::includes(std::begin(range1), std::end(range1), std::begin(range2),
                           std::end(range2), comp);
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class OutputIterator>
inline OutputIterator set_union(const InputRange1& range1, const InputRange2& range2,
                                OutputIterator result) {
    return std::set_union(std::begin(range1), std::end(range1), std::begin(range2),
                          std::end(range2), result);
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
inline OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                InputIterator2 last2, OutputIterator result, Compare comp) {
    return std::set_union(first1, last1, first2, last2, result, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class OutputIterator, class Compare>
inline OutputIterator set_union(const InputRange1& range1, const InputRange2& range2,
                                OutputIterator result, Compare comp) {
    return adobe::set_union(std::begin(range1), std::end(range1), std::begin(range2),
                            std::end(range2), result, comp);
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class OutputIterator>
inline OutputIterator set_intersection(const InputRange1& range1, const InputRange2& range2,
                                       OutputIterator result) {
    return std::set_intersection(std::begin(range1), std::end(range1), std::begin(range2),
                                 std::end(range2), result);
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
inline OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1,
                                       InputIterator2 first2, InputIterator2 last2,
                                       OutputIterator result, Compare comp) {
    return std::set_intersection(first1, last1, first2, last2, result, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class OutputIterator, class Compare>
inline OutputIterator set_intersection(const InputRange1& range1, const InputRange2& range2,
                                       OutputIterator result, Compare comp) {
    return adobe::set_intersection(std::begin(range1), std::end(range1), std::begin(range2),
                                   std::end(range2), result, comp);
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class OutputIterator>
inline OutputIterator set_difference(const InputRange1& range1, const InputRange2& range2,
                                     OutputIterator result) {
    return std::set_difference(std::begin(range1), std::end(range1), std::begin(range2),
                               std::end(range2), result);
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
inline OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1,
                                     InputIterator2 first2, InputIterator2 last2,
                                     OutputIterator result, Compare comp) {
    return std::set_difference(first1, last1, first2, last2, result, std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class OutputIterator, class Compare>
inline OutputIterator set_difference(const InputRange1& range1, const InputRange2& range2,
                                     OutputIterator result, Compare comp) {
    return adobe::set_difference(std::begin(range1), std::end(range1), std::begin(range2),
                                 std::end(range2), result, comp);
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class OutputIterator>
inline OutputIterator set_symmetric_difference(const InputRange1& range1, const InputRange2& range2,
                                               OutputIterator result) {
    return std::set_symmetric_difference(std::begin(range1), std::end(range1),
                                         std::begin(range2), std::end(range2), result);
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
inline OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
                                               InputIterator2 first2, InputIterator2 last2,
                                               OutputIterator result, Compare comp) {
    return std::set_symmetric_difference(first1, last1, first2, last2, result,
                                         std::bind(comp, std::placeholders::_1, std::placeholders::_2));
}

/*!
    \ingroup set

    \brief set implementation
*/
template <class InputRange1, class InputRange2, class OutputIterator, class Compare>
inline OutputIterator set_symmetric_difference(const InputRange1& range1, const InputRange2& range2,
                                               OutputIterator result, Compare comp) {
    return adobe::set_symmetric_difference(std::begin(range1), std::end(range1),
                                           std::begin(range2), std::end(range2), result, comp);
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif

/*************************************************************************************************/
