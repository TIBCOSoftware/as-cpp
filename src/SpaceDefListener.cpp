/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SpaceDefListener.h"

using namespace ASApi;
using namespace std;

SpaceDefListener::SpaceDefListener()
: ListenerBase<tibasListener>(tibasListener_Free)
{
    
}


SpaceDefListener::~SpaceDefListener()
{
    
}


void SpaceDefListener::create()
{
    AS_CALL(tibasSpaceDefListener_CreateEx(m_cObject.get(), onSpaceDefine, onSpaceAlter, onSpaceDrop, this));
}


void SpaceDefListener::onSpaceDefine(tibasSpaceDef spaceDef, void *closure)
{
    SpaceDefListener* spaceDefListener = (SpaceDefListener*) closure;
    if (spaceDefListener != NULL)
    {
        spaceDefListener->onDefine(SpaceDef(spaceDef));
        spaceDef = NULL;
    }
}


void SpaceDefListener::onSpaceAlter(tibasSpaceDef oldSpaceDef, tibasSpaceDef newSpaceDef, void *closure)
{
    SpaceDefListener* spaceDefListener = (SpaceDefListener*) closure;
    if (spaceDefListener != NULL)
    {
        spaceDefListener->onAlter(SpaceDef(oldSpaceDef), SpaceDef(newSpaceDef));
        oldSpaceDef = NULL;
        newSpaceDef = NULL;
    }
}


void SpaceDefListener::onSpaceDrop(tibasSpaceDef spaceDef, void *closure)
{
    SpaceDefListener* spaceDefListener = (SpaceDefListener*) closure;
    if (spaceDefListener != NULL)
    {
        spaceDefListener->onDrop(SpaceDef(spaceDef));
        spaceDef = NULL;
    }
}
