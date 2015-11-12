/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _Types_h
#define _Types_h

#include "types.h"
#include <tibas.h>

#ifdef _WINDOWS
    #define AS_CPP_API __declspec( dllexport )
#else
    #define AS_CPP_API
#endif

namespace ASApi
{
    typedef tibas_status Status;
    typedef tibas_distributionScope DistributionScope;
    typedef tibas_timeScope TimeScope;
    typedef tibas_logLevel LogLevel;
    typedef tibas_indexType IndexType;
    typedef tibas_managementRole ManagementRole;
    typedef tibas_distributionRole DistributionRole;
    typedef tibas_browserType BrowserType;
    typedef tibas_spaceState SpaceState;


    typedef tibas_distributionPolicy DistributionPolicy;
    typedef tibas_persistenceType  PersistenceType;
    typedef tibas_persistencePolicy PersistencePolicy;
    typedef tibas_evictionPolicy EvictionPolicy;

    template <typename T>
    class AS_CPP_API Deleter
    {
    private:
        typedef Status (*Function) (T*);
        Function m_fn;
        
    public:
        Deleter(Function fn = NULL);
        
        void operator()(T* ptr);
        
        void reset() { m_fn = NULL; }
    };
    
    
    template <typename T>
    Deleter<T>::Deleter(Function fn)
    : m_fn(fn)
    {
        
    }
    
    
    template <typename T>
    void Deleter<T>::operator()(T *ptr)
    {
        if (m_fn != NULL)
            (*m_fn)(ptr);
        else
            delete ptr;
    }
}

#endif
