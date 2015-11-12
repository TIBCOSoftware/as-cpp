/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __SpaceEvent__h
#define __SpaceEvent__h

#include "tibas.h"
#include "Tuple.h"
#include <memory>

namespace ASApi
{
    class AS_CPP_API SpaceEvent
    {
    public:
        typedef tibas_eventType EventType;
        
        SpaceEvent(const tibasSpaceEvent& event);
        ~SpaceEvent();
        
        Tuple getTuple() const;
        
        std::string getMetaspaceName() const;
        
        std::string getSpaceName() const;
        
        EventType getType() const;
        
    protected:
        const tibasSpaceEvent& m_event;
    };
}

#endif
