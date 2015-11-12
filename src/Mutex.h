/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _Mutex_h
#define _Mutex_h

#ifdef NO_STD_MUTEX
#include "Types.h"

#ifdef _WINDOWS
#include <Windows.h>
#else
#include <pthread.h>
#endif

namespace ASApi
{
    class AS_CPP_API Mutex
    {
    public:
        Mutex();
        ~Mutex();

        void lock();

        bool trylock();

        void unlock();

    private:
#ifdef _WINDOWS
        CRITICAL_SECTION m_critical_section;
#else
        pthread_mutex_t m_mutex;
#endif
    };
    
    template<typename TLockable>
    class LockGuard
    {
    public:
        LockGuard(TLockable &lockable)
            : lockable(lockable)
        {
            lockable.lock();
        }
        
        ~LockGuard()
        {
            lockable.unlock();
        }
        
    private:
        TLockable &lockable;
    };
}

#else
#include <mutex>

namespace ASApi
{
    typedef std::mutex Mutex;
    
    template<typename T> using LockGuard = std::lock_guard<T>;
}

#endif

#endif
