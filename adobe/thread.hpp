/*
    Copyright 2015 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/**************************************************************************************************/

#ifndef ADOBE_THREAD_HPP
#define ADOBE_THREAD_HPP

#ifndef HAVE_NO_STD_MUTEX

#include <thread>

/**************************************************************************************************/

namespace adobe {

/**************************************************************************************************/

using std::thread;
namespace this_thread = std::this_thread;

/**************************************************************************************************/

}

#else
	
#include <boost/thread/thread.hpp>

/**************************************************************************************************/

namespace adobe {

/**************************************************************************************************/

using boost::thread;
namespace this_thread = boost::this_thread;

/**************************************************************************************************/

}

#endif

#endif
