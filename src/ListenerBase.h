/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _ListenerBase_h
#define _ListenerBase_h

#include "tibas.h"
#include "Utils.h"
#include "Exception.h"
#include <memory>

namespace ASApi
{
    template <typename T>
    class AS_CPP_API ListenerBase
    {
    public:
        virtual ~ListenerBase() { }
        
        const T& get() const;
        T& get();
        
        void start();
        void stop();
        
    protected:
        typedef Status (*ListenerFree) (T* listener);
        ListenerBase(ListenerFree deleter);
        
        virtual void create() = 0;
        
        SharedPtr<T> m_cObject;
        Deleter<T> m_deleter;
    };
    
    
    template <typename T>
    ListenerBase<T>::ListenerBase(ListenerFree deleter)
    : m_deleter(deleter)
    {
        
    }
    
    
    template <typename T>
    const T& ListenerBase<T>::get() const
    {
        if (m_cObject.get() == NULL)
        {
            throw Exception(TIBAS_INVALID_ARG);
        }
        return *m_cObject;
    }
    
    
    template <typename T>
    T& ListenerBase<T>::get()
    {
        if (m_cObject.get() == NULL)
        {
            throw Exception(TIBAS_INVALID_ARG);
        }
        return *m_cObject;
    }

    
    template <typename T>
    void ListenerBase<T>::start()
    {
        if (m_cObject.get() == NULL)
        {
            m_cObject.reset(new T(), m_deleter);
            create();
        }
    }
    
    
    template <typename T>
    void ListenerBase<T>::stop()
    {
        if (m_cObject.get() != NULL)
        {
            m_cObject.reset();
        }
    }
}

#endif
