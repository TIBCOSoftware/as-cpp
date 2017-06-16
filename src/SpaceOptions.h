/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _SpaceOptions_h
#define _SpaceOptions_h

#include "SpaceResultHandler.h"
#include "SharedPtr.h"

namespace ASApi
{
    template <typename OptionsType, typename tibasType>
    class SpaceOptions
    {
        typedef void (*Initializer)(tibasType* options);
        
    public:
        virtual ~SpaceOptions();
        
        tibasType& get() const;
        
        SpaceOptions& setResultHandler(SharedPtr<SpaceResultHandler> handler);
        SharedPtr<SpaceResultHandler> getResultHandler() const;
        
        SpaceOptions& setClosure(void* closure);
        void* getClosure() const;

    protected:
        SpaceOptions(Initializer init);

        SpaceOptions(Initializer init, const Deleter<tibasType>& deleter);

        SharedPtr<tibasType> m_options;
    };
    
    template <typename OptionsType, typename tibasType>
    SpaceOptions<OptionsType, tibasType>::SpaceOptions(Initializer init)
    : m_options(new tibasType())
    {
        (*init)(m_options.get());
    }
    
    template <typename OptionsType, typename tibasType>
    SpaceOptions<OptionsType, tibasType>::SpaceOptions(Initializer init, const Deleter<tibasType>& deleter)
    : m_options(new tibasType(), deleter)
    {
        (*init)(m_options.get());
    }

    template <typename OptionsType, typename tibasType>
    SpaceOptions<OptionsType, tibasType>::~SpaceOptions()
    {
        
    }
    
    template <typename OptionsType, typename tibasType>
    tibasType& SpaceOptions<OptionsType, tibasType>::get() const
    {
        return *m_options;
    }
    
    template <typename OptionsType, typename tibasType>
    SpaceOptions<OptionsType, tibasType>& SpaceOptions<OptionsType, tibasType>::setResultHandler(SharedPtr<SpaceResultHandler> handler)
    {
        SpaceResultHandler::Closure* c_closure = (SpaceResultHandler::Closure*) m_options->closure;
        if (c_closure == NULL)
        {
            c_closure = new SpaceResultHandler::Closure();
            m_options->closure = c_closure;
        }
        c_closure->m_handler = handler;
        return *this;
    }
    
    
    template <typename OptionsType, typename tibasType>
    SharedPtr<SpaceResultHandler> SpaceOptions<OptionsType, tibasType>::getResultHandler() const
    {
        SpaceResultHandler::Closure* c_closure = (SpaceResultHandler::Closure*) m_options->closure;
        return c_closure == NULL ? SharedPtr<SpaceResultHandler>(NULL) : c_closure->m_handler;
    }
    
    
    template <typename OptionsType, typename tibasType>
    SpaceOptions<OptionsType, tibasType>& SpaceOptions<OptionsType, tibasType>::setClosure(void *closure)
    {
        SpaceResultHandler::Closure* c_closure = (SpaceResultHandler::Closure*) m_options->closure;
        if (c_closure == NULL)
        {
            c_closure = new SpaceResultHandler::Closure();
            m_options->closure = c_closure;
        }
        c_closure->m_closure = closure;
        return *this;
    }
    
    
    template <typename OptionsType, typename tibasType>
    void* SpaceOptions<OptionsType, tibasType>::getClosure() const
    {
        SpaceResultHandler::Closure* c_closure = (SpaceResultHandler::Closure*) m_options->closure;
        return c_closure == NULL ? NULL : c_closure->m_closure;
    }

}

#endif
