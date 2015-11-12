/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "TakeEvent.h"
#include "Exception.h"

using namespace ASApi;
using namespace std;

TakeEvent::TakeEvent(const tibasSpaceEvent& event)
    :SpaceEvent(event)
{
}


TakeEvent::~TakeEvent()
{
    
}
