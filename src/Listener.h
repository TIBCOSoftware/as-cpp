/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Listener__
#define __Listener__

#include "tibas.h"
#include <memory>
#include "PutEvent.h"
#include "TakeEvent.h"
#include "ExpireEvent.h"
#include "SeedEvent.h"
#include "UnseedEvent.h"
#include "EvictEvent.h"
#include "ListenerTemplate.h"

namespace ASApi
{
    class AS_CPP_API Listener : public ListenerTemplate<tibas_onEvent>
    {
    public:

        Listener();
        virtual ~Listener();
        
        static void onEvent(tibasSpaceEvent event, void* closure);
        
        virtual void onPut(const PutEvent& putEvent) { }
        virtual void onTake(const TakeEvent& takeEvent) { }
        virtual void onExpire(const ExpireEvent& expireEvent) { }
        virtual void onSeed(const SeedEvent& seedEvent) { }
        virtual void onUnseed(const UnseedEvent& UnseedEvent) { }
        virtual void onEvict(const EvictEvent& evictEvent) { } 
    };
}

#endif
