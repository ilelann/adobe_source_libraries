/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ITERATOR_DISTANCE_HPP
#define ADOBE_ITERATOR_DISTANCE_HPP

#include <adobe/config.hpp>

#include <iterator>

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/

/*!
\ingroup adobe_iterator
*/

template <typename I> // I models InputRange
inline auto distance(I& range) {
    return std::distance(std::begin(range), std::end(range));
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif
// ADOBE_ITERATOR_DISTANCE_HPP
