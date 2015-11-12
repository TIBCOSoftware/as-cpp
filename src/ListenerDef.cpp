/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "ListenerDef.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;

ListenerDef::ListenerDef()
: m_listenerDef(new tibasListenerDef(), Deleter<tibasListenerDef>(tibasListenerDef_Free))
{
    AS_CALL(tibasListenerDef_Create(m_listenerDef.get()));
}


ListenerDef::~ListenerDef()
{
    
}


const tibasListenerDef& ListenerDef::get() const
{
    return *m_listenerDef;
}


DistributionScope ListenerDef::getDistributionScope() const
{
    DistributionScope distributionScope;
    AS_CALL(tibasListenerDef_GetDistributionScope(*m_listenerDef, &distributionScope));
    return distributionScope;
}


ListenerDef& ListenerDef::setDistributionScope(DistributionScope distributionScope)
{
    AS_CALL(tibasListenerDef_SetDistributionScope(*m_listenerDef, distributionScope));
    return *this;
}


TimeScope ListenerDef::getTimeScope() const
{
    TimeScope timeScope;
    AS_CALL(tibasListenerDef_GetTimeScope(*m_listenerDef, &timeScope));
    return timeScope;
}


ListenerDef& ListenerDef::setTimeScope(TimeScope timeScope)
{
    AS_CALL(tibasListenerDef_SetTimeScope(*m_listenerDef, timeScope));
    return *this;
}


long long ListenerDef::getQueryLimit() const
{
    long long queryLimit;
    AS_CALL(tibasListenerDef_GetQueryLimit(*m_listenerDef, &queryLimit));
    return queryLimit;
}


ListenerDef& ListenerDef::setQueryLimit(long long queryLimit)
{
    AS_CALL(tibasListenerDef_SetQueryLimit(*m_listenerDef, queryLimit));
    return *this;
}
