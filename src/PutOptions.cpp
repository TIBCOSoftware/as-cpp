/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "PutOptions.h"
#include "options.h"
#include "Exception.h"

using namespace std;
using namespace ASApi;


PutOptions::PutOptions()
: SpaceOptions<ASApi::PutOptions, tibasPutOptions>(tibasPutOptions_Initialize)
{
    
}


PutOptions& PutOptions::setLockWait(long long wait)
{
    m_options->lockWait = wait;
    return *this;
}


long long PutOptions::getLockWait() const
{
    return m_options->lockWait;
}


PutOptions& PutOptions::setLock(bool doLock)
{
    m_options->lock = (tibas_boolean)doLock; 
    return *this;
}


bool PutOptions::isLock() const
{
    tibas_boolean boolean = m_options->lock;
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


PutOptions& PutOptions::setForget(bool doForget)
{
    m_options->forget = (tibas_boolean)doForget;
    return *this;
}


bool PutOptions::isForget() const
{
    tibas_boolean boolean = m_options->forget;
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


PutOptions& PutOptions::setRoute(bool doRoute)
{
    m_options->route = (tibas_boolean)doRoute;
    return *this;
}


bool PutOptions::isRoute() const
{
    tibas_boolean boolean = m_options->route;
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


PutOptions& PutOptions::setTTL(long long ttl)
{
    m_options->entryTTL = ttl;
    return *this;
}


long long PutOptions::getTTL()
{
    return m_options->entryTTL;
}


