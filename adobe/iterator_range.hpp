/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#ifndef ADOBE_ITERATOR_RANGE_HPP
#define ADOBE_ITERATOR_RANGE_HPP

#include <algorithm>

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/

template <typename I>
struct iterator_range
{
    iterator_range ()
        : begin_m{}, end_m{}
    {
    }

    iterator_range (const I & b, const I & e)
        : begin_m{b}, end_m{e}
    {
    }

    I begin() const
    {
        return begin_m;
    }

    I end() const
    {
        return end_m;
    }

    using iterator = I;
    using const_iterator = I;

private:
    I begin_m;
    I end_m;
};

template <typename I>
bool
operator==(const iterator_range<I> & l, const iterator_range<I> & r)
{
    return std::equal(std::begin(l), std::end(l), std::begin(r), std::end(r));
}

template <typename I>
bool
operator!=(const iterator_range<I> & l, const iterator_range<I> & r)
{
    return !(l == r);
}

template <typename I>
auto
make_iterator_range(I f, I l)
{
    return iterator_range<I>{f, l};
}

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/

#endif

/*************************************************************************************************/
