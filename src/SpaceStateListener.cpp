/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Exception.h"
#include "SpaceStateListener.h"

using namespace std;
using namespace ASApi;


SpaceStateListener::SpaceStateListener()
: ListenerTemplate<tibas_onSpaceStateChange>(tibasSpaceStateListener_Create, onCStateChage)
{
    
}


SpaceStateListener::~SpaceStateListener()
{
    
}


void SpaceStateListener::onCStateChage(const char *spaceName, tibas_spaceState spaceState, void *closure)
{
    SpaceStateListener* spaceStateListener = (SpaceStateListener*) closure;
    if (spaceStateListener != NULL)
    {
        spaceStateListener->onStateChange(spaceName, spaceState);
    }
}
