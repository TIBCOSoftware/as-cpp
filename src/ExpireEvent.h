/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __ExpireEvent__
#define __ExpireEvent__

#include "tibas.h"
#include "SpaceEvent.h"

namespace ASApi
{
    class AS_CPP_API ExpireEvent : public SpaceEvent
    {
    public:
        ExpireEvent(const tibasSpaceEvent& event);
        ~ExpireEvent();

    };    
}

#endif
