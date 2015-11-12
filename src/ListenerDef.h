/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __ListenerDef__
#define __ListenerDef__

#include "tibas.h"
#include "Types.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API ListenerDef
    {
    public:
        ListenerDef();
        ~ListenerDef();
        
        const tibasListenerDef& get() const;
        
        DistributionScope getDistributionScope() const;
        ListenerDef& setDistributionScope(DistributionScope distributionScope);
        
        TimeScope getTimeScope() const;
        ListenerDef& setTimeScope(TimeScope timeScope);
        
        long long getQueryLimit() const;
        ListenerDef& setQueryLimit(long long limit);
        
    private:
        SharedPtr<tibasListenerDef> m_listenerDef;
    };
}

#endif
