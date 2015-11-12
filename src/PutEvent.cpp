/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "PutEvent.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

PutEvent::PutEvent(const tibasSpaceEvent& event)
    :SpaceEvent(event)
{
}


PutEvent::~PutEvent()
{
    
}


bool PutEvent::hasOldTuple() const
{
    tibas_boolean boolean = tibasSpaceEvent_HasOldTuple(m_event);
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


Tuple PutEvent::getOldTuple() const
{
    SharedPtr<tibasTuple> tuple;
    if (tibasSpaceEvent_HasOldTuple(m_event))
    {
        tuple.reset(new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
        AS_CALL(tibasSpaceEvent_GetOldTuple(m_event, tuple.get()));
    }
    return Tuple(tuple);
}
