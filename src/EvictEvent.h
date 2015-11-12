/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __EvictEvent__
#define __EvictEvent__

#include "tibas.h"
#include "SpaceEvent.h"

namespace ASApi
{
    class AS_CPP_API EvictEvent : public SpaceEvent
    {
    public:
        EvictEvent(const tibasSpaceEvent& event);
        ~EvictEvent();

    };    
}

#endif
