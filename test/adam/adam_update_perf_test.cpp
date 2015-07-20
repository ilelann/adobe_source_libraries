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
using adobe::array_t;
using adobe::line_position_t;
using adobe::sheet_t;
using relation_t = adobe::sheet_t::relation_t;
using adobe::variable_k;
using adobe::multiply_k;
using adobe::divide_k;
using adobe::name_t;
using std::abs;

int main(int, char*[]) {

    using namespace adobe::literals;

    sheet_t sheet;

    sheet.machine_m.set_variable_lookup([&](const name_t & n) { return sheet.get(n);});

    line_position_t no_line;

    auto a = "a"_name, b = "b"_name, c = "c"_name, d = "d"_name, e = "e"_name, f = "f"_name, g="g"_name, h = "h"_name, i = "i"_name, j = "j"_name;

    sheet.add_interface(a, 0.0);
    sheet.add_interface(b, true, no_line, array_t{}, no_line, {2.0, a, variable_k, multiply_k});
    sheet.add_interface(c, true, no_line, array_t{}, no_line, {3.0, a, variable_k, multiply_k});
    sheet.add_interface(d, true, no_line, array_t{}, no_line, {4.0, a, variable_k, multiply_k});
    sheet.add_interface(e, true, no_line, array_t{}, no_line, {5.0, a, variable_k, multiply_k});
    sheet.add_interface(f, true, no_line, array_t{}, no_line, {6.0, a, variable_k, multiply_k});
    sheet.add_interface(g, true, no_line, array_t{}, no_line, {7.0, a, variable_k, multiply_k});
    sheet.add_interface(h, true, no_line, array_t{}, no_line, {8.0, a, variable_k, multiply_k});
    sheet.add_interface(i, true, no_line, array_t{}, no_line, {9.0, a, variable_k, multiply_k});
    sheet.add_interface(j, true, no_line, array_t{}, no_line, {10.0, a, variable_k, multiply_k});

    sheet.update();

    std::array<double, 10> values;
    auto connections = {
        sheet.monitor_value(a, [&](any_regular_t v) { values[0] = v.cast<double>(); }),
        sheet.monitor_value(b, [&](any_regular_t v) { values[1] = v.cast<double>(); }),
        sheet.monitor_value(c, [&](any_regular_t v) { values[2] = v.cast<double>(); }),
        sheet.monitor_value(d, [&](any_regular_t v) { values[3] = v.cast<double>(); }),
        sheet.monitor_value(e, [&](any_regular_t v) { values[4] = v.cast<double>(); }),
        sheet.monitor_value(f, [&](any_regular_t v) { values[5] = v.cast<double>(); }),
        sheet.monitor_value(g, [&](any_regular_t v) { values[6] = v.cast<double>(); }),
        sheet.monitor_value(h, [&](any_regular_t v) { values[7] = v.cast<double>(); }),
        sheet.monitor_value(i, [&](any_regular_t v) { values[8] = v.cast<double>(); }),
        sheet.monitor_value(j, [&](any_regular_t v) { values[9] = v.cast<double>(); })
    };

    for (int i=1; i < 1000000; ++i)
    {
        sheet.set(a, i);
        sheet.update();
        for (int j = 0; j < 10; ++j)
        {
            if (abs(values[j]- ((j+1)* i)) > 0.001)
                return -1;
        }
    }

    return 0;
}
