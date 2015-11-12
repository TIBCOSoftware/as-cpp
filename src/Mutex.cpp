/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Mutex.h"

#ifdef NO_STD_MUTEX

using namespace ASApi;

Mutex::Mutex()
{
#ifdef _WINDOWS
    ::InitializeCriticalSection(&m_critical_section);
#else
    pthread_mutex_init(&m_mutex, NULL);
#endif
}


Mutex::~Mutex()
{
#ifdef _WINDOWS
    ::DeleteCriticalSection(&m_critical_section);
#else
    pthread_mutex_destroy(&m_mutex);
#endif
}


void Mutex::lock()
{
#ifdef _WINDOWS
    ::EnterCriticalSection(&m_critical_section);
#else
    pthread_mutex_lock(&m_mutex);
#endif
}


bool Mutex::trylock()
{
#ifdef _WINDOWS
    return false;
#else
    return pthread_mutex_trylock(&m_mutex) == 0;
#endif
}


void Mutex::unlock()
{
#ifdef _WINDOWS
    ::LeaveCriticalSection(&m_critical_section);
#else
    pthread_mutex_unlock(&m_mutex);
#endif
}

#endif
