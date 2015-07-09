/*
    Copyright 2015 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/**************************************************************************************************/

#ifndef ADOBE_CONDITION_VARIABLE_HPP
#define ADOBE_CONDITION_VARIABLE_HPP

#ifndef HAVE_NO_STD_MUTEX

#include <condition_variable>

/**************************************************************************************************/

namespace adobe {

/**************************************************************************************************/

using std::condition_variable;

/**************************************************************************************************/

}

#else
	
#include <boost/thread/condition_variable.hpp>

/**************************************************************************************************/

namespace adobe {

/**************************************************************************************************/

using boost::condition_variable;

/**************************************************************************************************/

}

#endif

#endif
