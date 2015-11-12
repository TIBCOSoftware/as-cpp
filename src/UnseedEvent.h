/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __UnseedEvent__
#define __UnseedEvent__

#include "tibas.h"
#include "SpaceEvent.h"

namespace ASApi
{
    class AS_CPP_API UnseedEvent : public SpaceEvent
    {
    public:
        UnseedEvent(const tibasSpaceEvent& event);
        ~UnseedEvent();

    };    
}

#endif
