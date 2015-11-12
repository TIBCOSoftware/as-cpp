/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

// A minimal implemenation of std::shared_ptr<> if it is not available from the compiler itself
//

#ifndef _SharedPtr_h
#define _SharedPtr_h

#include "Types.h"
#include "Mutex.h"

#ifdef NO_STD_SHARED_PTR
#include <iostream>

namespace ASApi
{
    template<typename T>
    class AS_CPP_API SharedPtr
    {
    public:
        SharedPtr();
        explicit SharedPtr(T* ptr, Deleter<T> deleter = Deleter<T>());
        SharedPtr(const SharedPtr<T>& other);
        
        ~SharedPtr() { reset(); }
        
        // modifiers:
        void swap(SharedPtr<T>& other);
        void reset();
        void reset(T* ptr, Deleter<T> deleter = Deleter<T>());
        
        // observers:
        T* get() const { return m_ptr; }
        
        T& operator*() const { return *m_ptr; }
        
        T* operator->() const {return m_ptr; }
        
        SharedPtr<T>& operator= (const SharedPtr<T>& other);
        
        SharedPtr<T>& operator= (T* ptr);
        
        long use_count() const { return *m_useCount; }
        
        operator bool() const { return m_ptr != NULL; }
        
    private:
        T* m_ptr;
        long* m_useCount;
        Mutex* m_mutex;
        Deleter<T> m_deleter;
    };
    
    
    template <typename T>
    SharedPtr<T>::SharedPtr()
    : m_ptr(NULL),
      m_useCount(new long(1)),
      m_mutex(new Mutex())
    {
    }
    
    
    template <typename T>
    SharedPtr<T>::SharedPtr(T* ptr, Deleter<T> deleter)
    : m_ptr(ptr),
      m_useCount(new long(1)),
      m_mutex(new Mutex()),
      m_deleter(deleter)
    {
    }
    
    
    template <typename T>
    SharedPtr<T>::SharedPtr(const SharedPtr<T>& other)
    : m_ptr (other.m_ptr),
      m_useCount (other.m_useCount),
      m_mutex (other.m_mutex),
      m_deleter(other.m_deleter)
    {
        LockGuard<Mutex> lock (*m_mutex);
        ++(*m_useCount);
    }
    
    
    template <typename T>
    void SharedPtr<T>::reset()
    {
        long useCount;
        {
            LockGuard<Mutex> lock(*m_mutex);
            useCount = --(*m_useCount);
        }
        
        if (useCount == 0)
        {
            m_deleter(m_ptr); m_ptr = NULL; m_deleter.reset();
            delete m_useCount; m_useCount = NULL;
            delete m_mutex; m_mutex = NULL;
        }
    }

    
    template <typename T>
    void SharedPtr<T>::reset(T* ptr, Deleter<T> deleter)
    {
        reset();
        m_ptr = ptr;
        m_useCount = new long(1);
        m_mutex = new Mutex();
        m_deleter = deleter;
    }
    
    
    template <typename T>
    void SharedPtr<T>::swap(SharedPtr<T>& other)
    {
        SharedPtr<T> tmp = other;
        {
            LockGuard<Mutex> lock(*other.m_mutex);
            other.m_ptr = m_ptr;
            other.m_useCount = m_useCount;
            other.m_mutex = m_mutex;
            other.m_deleter = m_deleter;
        }
        {
            LockGuard<Mutex> lock(*m_mutex);
            m_ptr = tmp.m_ptr;
            m_useCount = tmp.m_useCount;
            m_mutex = tmp.m_mutex;
            m_deleter = tmp.m_deleter;
        }
    }
    
    
    template <typename T>
    SharedPtr<T>& SharedPtr<T>::operator= (const SharedPtr<T>& other)
    {
        reset();
        m_ptr = other.m_ptr;
        m_mutex = other.m_mutex;
        m_useCount = other.m_useCount;
        m_deleter = other.m_deleter;
        {
            LockGuard<Mutex> lock(*m_mutex);
            ++(*m_useCount);
        }
        return *this;
    }
    
    
    template <typename T>
    SharedPtr<T>& SharedPtr<T>::operator= (T* ptr)
    {
        reset();
        m_ptr = m_ptr;
        m_mutex = new Mutex();
        m_useCount = new long(1);
        m_deleter = Deleter<T>();
        return *this;
    }
}
#else
#include <memory>

namespace ASApi
{
    template <typename T>
    class AS_CPP_API SharedPtr : public std::shared_ptr<T>
    {
    public:
        SharedPtr() { }
        
        SharedPtr(T* ptr, Deleter<T> deleter) : std::shared_ptr<T>(ptr, deleter) { }
        
        SharedPtr(T* ptr) : std::shared_ptr<T>(ptr) { }
        
        SharedPtr(const SharedPtr<T>& other) : std::shared_ptr<T>(other) { }
    };
}

#endif

#endif
