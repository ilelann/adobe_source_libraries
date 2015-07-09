/*
    Copyright 2015 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/**************************************************************************************************/

#ifndef ADOBE_MUTEX_HPP
#define ADOBE_MUTEX_HPP

#ifndef HAVE_NO_STD_MUTEX

#include <mutex>

/**************************************************************************************************/

namespace adobe {

/**************************************************************************************************/

using std::mutex;
using std::unique_lock;
using std::lock_guard;
using std::call_once;
using std::once_flag;

/**************************************************************************************************/

}

#else
	
#include <boost/thread/lock_guard.hpp>
#include <boost/thread/lock_types.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/once.hpp>

/**************************************************************************************************/

namespace adobe {

/**************************************************************************************************/

using boost::mutex;
using boost::unique_lock;
using boost::lock_guard;
using boost::call_once;
using boost::once_flag;

/**************************************************************************************************/

}

#endif

#endif
