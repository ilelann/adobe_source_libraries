///*
//    Copyright 2015 Adobe
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//*/
///*************************************************************************************************/

#include <adobe/config.hpp>

#include <adobe/adam.hpp>

#include <adobe/implementation/token.hpp>

#include <cmath>

using adobe::any_regular_t;
using adobe::line_position_t;
using adobe::name_t;
using adobe::sheet_t;
using adobe::variable_k;
using adobe::divide_k;
using std::abs;

int main(int, char*[]) {

    using namespace adobe::literals;

    sheet_t sheet;

    sheet.machine_m.set_variable_lookup([&](const name_t & n) { return sheet.get(n);});

    line_position_t no_line;

    auto meters = "meters"_name;
    auto seconds = "seconds"_name;
    auto rate = "rate"_name;

    sheet.add_interface(meters, 1.0);
    sheet.add_interface(seconds, 1.0);
    sheet.add_output(rate, no_line, {meters, variable_k, seconds, variable_k, divide_k });
    sheet.update();

    double rate_value;
    auto connection = sheet.monitor_value(rate, [&](const any_regular_t & v) { rate_value = v.cast<double>(); });

    sheet.set(seconds, 42);
    sheet.set(meters, 78);
    sheet.update();

    auto success = abs(rate_value - 1.8571428571428572) < 0.001;
    return !success;
}
