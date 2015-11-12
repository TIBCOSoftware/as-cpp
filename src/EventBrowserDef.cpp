/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "EventBrowserDef.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

EventBrowserDef::EventBrowserDef()
: m_eventBrowserDef(new tibasEventBrowserDef(), Deleter<tibasEventBrowserDef>(tibasEventBrowserDef_Free))
{
    //Create
    AS_CALL(tibasEventBrowserDef_Create(m_eventBrowserDef.get()));
}


EventBrowserDef::~EventBrowserDef()
{
    
}


const tibasEventBrowserDef& EventBrowserDef::get() const
{
    return *m_eventBrowserDef;
}


tibasEventBrowserDef& EventBrowserDef::get()
{
    return *m_eventBrowserDef;
}


DistributionScope EventBrowserDef::getDistributionScope() const
{
        tibas_distributionScope distributionScope;
        AS_CALL(tibasEventBrowserDef_GetDistributionScope(get(), &distributionScope));
        return distributionScope;
}


long long EventBrowserDef::getTimeout() const
{
    tibas_long timeout = 0;
    AS_CALL(tibasEventBrowserDef_GetTimeout(get(), &timeout));
    return (long long)timeout;
}


TimeScope EventBrowserDef::getTimeScope() const
{
    tibas_timeScope timeScope;
    AS_CALL(tibasEventBrowserDef_GetTimeScope(get(), &timeScope));
    return timeScope;
}


EventBrowserDef& EventBrowserDef::setDistributionScope(const DistributionScope& distributionScope)
{
    AS_CALL(tibasEventBrowserDef_SetDistributionScope(get(), distributionScope));
    return *this;
}


EventBrowserDef& EventBrowserDef::setTimeout(long long timeout)
{
    AS_CALL(tibasEventBrowserDef_SetTimeout(get(), (tibas_long)timeout));
    return *this;
}


EventBrowserDef& EventBrowserDef::setTimeScope(const TimeScope& timescope)
{
    AS_CALL(tibasEventBrowserDef_SetTimeScope(get(), timescope));
    return *this;
}


