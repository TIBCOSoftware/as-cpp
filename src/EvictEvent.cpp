/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "EvictEvent.h"
#include "Exception.h"

using namespace ASApi;
using namespace std;

EvictEvent::EvictEvent(const tibasSpaceEvent& event)
    :SpaceEvent(event)
{
}


EvictEvent::~EvictEvent()
{
    
}
