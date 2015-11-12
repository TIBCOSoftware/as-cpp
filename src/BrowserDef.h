/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _BrowserDef_h
#define _BrowserDef_h

#include <string>
#include "SharedPtr.h"
#include "tibas.h"
#include "Exception.h"
#include "Types.h"

namespace ASApi
{
    class AS_CPP_API BrowserDef
    {
    public:
        BrowserDef();
        ~BrowserDef();

        const tibasBrowserDef& get() const;

        tibasBrowserDef& get();

        DistributionScope getDistributionScope() const; 
        
        long long getTimeout() const;

        TimeScope getTimeScope() const;

        BrowserDef& setDistributionScope(const DistributionScope& distributionScope);

        BrowserDef& setTimeout(long long timeout);

        BrowserDef& setTimeScope(const TimeScope& timescope);

    private:
        SharedPtr<tibasBrowserDef> m_browserDef;
    };
}

#endif
