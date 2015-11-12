/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __PutEvent__
#define __PutEvent__

#include "tibas.h"
#include "SpaceEvent.h"

namespace ASApi
{
    class AS_CPP_API PutEvent : public SpaceEvent
    {
    public:
        PutEvent(const tibasSpaceEvent& event);
        ~PutEvent();

        bool hasOldTuple() const;
        
        Tuple getOldTuple() const;
        
    };
}

#endif
