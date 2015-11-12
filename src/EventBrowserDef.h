/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _EventBrowserDef_h
#define _EventBrowserDef_h

#include <string>
#include "tibas.h"
#include "Exception.h"
#include "Types.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API EventBrowserDef
    {
    public:
        EventBrowserDef();
        ~EventBrowserDef();

        const tibasEventBrowserDef& get() const;

        tibasEventBrowserDef& get();

        DistributionScope getDistributionScope() const; 
        
        long long getTimeout() const;

        TimeScope getTimeScope() const;

        EventBrowserDef& setDistributionScope(const DistributionScope& distributionScope);

        EventBrowserDef& setTimeout(long long timeout);

        EventBrowserDef& setTimeScope(const TimeScope& timescope);

    private:
        SharedPtr<tibasEventBrowserDef> m_eventBrowserDef;
    };
}

#endif
