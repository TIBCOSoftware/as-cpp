/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __SeedEvent__
#define __SeedEvent__

#include "tibas.h"
#include "SpaceEvent.h"

namespace ASApi
{
    class AS_CPP_API SeedEvent : public SpaceEvent
    {
    public:
        SeedEvent(const tibasSpaceEvent& event);
        ~SeedEvent();

    };    
}

#endif
