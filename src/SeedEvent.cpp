/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SeedEvent.h"
#include "Exception.h"

using namespace ASApi;
using namespace std;

SeedEvent::SeedEvent(const tibasSpaceEvent& event)
    :SpaceEvent(event)
{
}


SeedEvent::~SeedEvent()
{
    
}
