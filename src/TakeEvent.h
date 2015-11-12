/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __TakeEvent__
#define __TakeEvent__

#include "tibas.h"
#include "SpaceEvent.h"

namespace ASApi
{
    class AS_CPP_API TakeEvent : public SpaceEvent
    {
    public:
        TakeEvent(const tibasSpaceEvent& event);
        ~TakeEvent();

    };    
}

#endif
