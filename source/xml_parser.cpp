/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/*************************************************************************************************/

#include <adobe/config.hpp>

#include <adobe/xml_parser.hpp>
#include <adobe/implementation/expression_filter.hpp>

#include <map>

#include <adobe/unicode.hpp>

/*************************************************************************************************/

#ifdef BOOST_MSVC
namespace std {
using ::isxdigit;
using ::isdigit;
} // namespace std
#endif

/*************************************************************************************************/

namespace {

/*************************************************************************************************/

adobe::token_range_t to_token_range(boost::uint32_t code) {
    // REVISIT (fbrereto) : Allocation in this function needs to go

    if (code == 0)
        return adobe::token_range_t();

    std::string utf8;

    utf8.reserve(8);

    adobe::copy_utf<char>(&code, &code + 1, std::back_inserter(utf8));

    adobe::name_t utf8_name(utf8.c_str());

    adobe::uchar_ptr_t name_ptr(reinterpret_cast<adobe::uchar_ptr_t>(utf8_name.c_str()));

    return adobe::token_range_t(name_ptr, name_ptr + utf8.size());
}

/*************************************************************************************************/

} // namespace

/*************************************************************************************************/

namespace adobe {

/*************************************************************************************************/

namespace implementation {

/*************************************************************************************************/

adobe::token_range_t transform_reference(const adobe::token_range_t& reference) try {
    auto begin = std::begin(reference);
    return begin && *begin == '&'
               ? to_token_range(adobe::entity_map_find(
                     std::string(std::next(begin), std::prev(std::end(reference)))))
               : adobe::token_range_t();
}
catch (...) {
    // A throw here means the entity could not be found. Return an empty token
    // range in line with the previous implementation.
    return adobe::token_range_t();
}

/*************************************************************************************************/

} // namespace implementation

/*************************************************************************************************/

} // namespace adobe

/*************************************************************************************************/
