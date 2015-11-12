/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _ListenerTemplate_h
#define _ListenerTemplate_h

#include "ListenerBase.h"

namespace ASApi
{
    template <typename T>
    class AS_CPP_API ListenerTemplate : public ListenerBase<tibasListener>
    {
        typedef tibas_status(*Creator)(tibasListener* listener, T callback, void* closure);
        
    public:
        virtual ~ListenerTemplate() { }
        
        virtual void create();
        
    protected:
        ListenerTemplate(Creator creator, T callback);
        
        SharedPtr <tibasListener> m_listener;
        Creator m_creator;
        T m_callback;
    };
    
    
    template <typename T>
    ListenerTemplate<T>::ListenerTemplate(Creator creator, T callback)
    : ListenerBase<tibasListener>(tibasListener_Free),
      m_creator(creator),
      m_callback(callback)
    {
        
    }
    
    
    template <typename T>
    void ListenerTemplate<T>::create()
    {
        AS_CALL(m_creator(m_cObject.get(), m_callback, this));
    }
}

#endif
