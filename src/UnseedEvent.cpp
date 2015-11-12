/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "UnseedEvent.h"
#include "Exception.h"

using namespace ASApi;
using namespace std;

UnseedEvent::UnseedEvent(const tibasSpaceEvent& event)
    :SpaceEvent(event)
{
}


UnseedEvent::~UnseedEvent()
{
    
}
