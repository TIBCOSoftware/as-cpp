/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SpaceEvent.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

SpaceEvent::SpaceEvent (const tibasSpaceEvent& event)
: m_event(event)
{
    
}


SpaceEvent::~SpaceEvent()
{
    
}


SpaceEvent::EventType SpaceEvent::getType() const
{
    EventType type;
    AS_CALL(tibasSpaceEvent_GetType(m_event, &type));
    return type;
}


Tuple SpaceEvent::getTuple() const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpaceEvent_GetTuple(m_event, tuple.get()));
    return Tuple(tuple);
}


string SpaceEvent::getMetaspaceName() const
{
    const char* name;
    AS_CALL(tibasSpaceEvent_GetMetaspaceName(m_event, &name));
    return name;
}


string SpaceEvent::getSpaceName() const
{
    const char* name;
    AS_CALL(tibasSpaceEvent_GetSpaceName(m_event, &name));
    return name;
}
