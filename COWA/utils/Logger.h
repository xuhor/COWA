#ifndef _LOGGER_H_
#define _LOGGER_H_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#ifdef WIN32
// Win Socket Header File(s)
#include <Windows.h>
#include <process.h>
#else
// POSIX Socket Header File(s)
#include <errno.h>
#include <pthread.h>
#endif


namespace CPlusPlusLogging
{
} // End of namespace


#endif // End of _LOGGER_H_

