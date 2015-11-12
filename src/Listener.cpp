/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Listener.h"

using namespace ASApi;


Listener::Listener()
: ListenerTemplate<tibas_onEvent>(tibasListener_Create, onEvent)
{
    
}


Listener::~Listener()
{
    
}


void Listener::onEvent(tibasSpaceEvent event, void *closure)
{
    Listener* listener = (Listener*) closure;
    switch (event->m_eventType)
    {
    case TIBAS_EVENT_PUT:
        {
            PutEvent putEvent(event);
            listener->onPut(putEvent);
            break;

        }
    case TIBAS_EVENT_TAKE:
        {
            TakeEvent takeEvent(event);
            listener->onTake(takeEvent);
            break;

        }
    case TIBAS_EVENT_EXPIRE:
        {
            ExpireEvent expireEvent(event);
            listener->onExpire(expireEvent);
            break;
        }
    case TIBAS_EVENT_SEED:
        {
            SeedEvent seedEvent(event);
            listener->onSeed(seedEvent);
            break;
        }
    case TIBAS_EVENT_UNSEED:
        {
            UnseedEvent unseedEvent(event);
            listener->onUnseed(unseedEvent);
            break;
        }
    case TIBAS_EVENT_EVICT:
        {
            EvictEvent evictEvent(event);
            listener->onEvict(evictEvent);
            break;
        }
    default:
        break;
    }
}
