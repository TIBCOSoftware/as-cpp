/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "BrowserDef.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

BrowserDef::BrowserDef()
: m_browserDef(new tibasBrowserDef(), Deleter<tibasBrowserDef>(tibasBrowserDef_Free))
{
    //Create
    AS_CALL(tibasBrowserDef_Create(m_browserDef.get()));
}


BrowserDef::~BrowserDef()
{
    
}


const tibasBrowserDef& BrowserDef::get() const
{
    return *m_browserDef;
}


tibasBrowserDef& BrowserDef::get()
{
    return *m_browserDef;
}


DistributionScope BrowserDef::getDistributionScope() const
{
        tibas_distributionScope distributionScope;
        AS_CALL(tibasBrowserDef_GetDistributionScope(get(), &distributionScope));
        return distributionScope;
}


long long BrowserDef::getTimeout() const
{
    tibas_long timeout = 0;
    AS_CALL(tibasBrowserDef_GetTimeout(get(), &timeout));
    return (long long)timeout;
}


TimeScope BrowserDef::getTimeScope() const
{
    tibas_timeScope timeScope;
    AS_CALL(tibasBrowserDef_GetTimeScope(get(), &timeScope));
    return (TimeScope)timeScope;
}


BrowserDef& BrowserDef::setDistributionScope(const DistributionScope& distributionScope)
{
    AS_CALL(tibasBrowserDef_SetDistributionScope(get(), distributionScope));
    return *this;
}


BrowserDef& BrowserDef::setTimeout(long long timeout)
{
    AS_CALL(tibasBrowserDef_SetTimeout(get(), (tibas_long)timeout));
    return *this;
}


BrowserDef& BrowserDef::setTimeScope(const TimeScope& timescope)
{
    AS_CALL(tibasBrowserDef_SetTimeScope(get(), timescope));
    return *this;
}



