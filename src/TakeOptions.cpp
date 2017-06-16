/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "TakeOptions.h"
#include "options.h"
#include "Exception.h"

using namespace std;
using namespace ASApi;


TakeOptions::TakeOptions()
: SpaceOptions<ASApi::TakeOptions, tibasTakeOptions>(tibasTakeOptions_Initialize)
{
    
}


TakeOptions& TakeOptions::setLockWait(long long wait)
{
    m_options->lockWait = wait;
    return *this;
}


long long TakeOptions::getLockWait() const
{
    return m_options->lockWait;
}


TakeOptions& TakeOptions::setLock(bool doLock)
{
    m_options->lock = (tibas_boolean)doLock; 
    return *this;
}


TakeOptions& TakeOptions::setUnlock(bool doLock)
{
    m_options->unlock = (tibas_boolean)doLock; 
    return *this;
}


bool TakeOptions::isLock() const
{
    tibas_boolean bl = m_options->lock;
    if(bl == TIBAS_FALSE)
    {
        return false;
    }
    else if(bl == TIBAS_TRUE)
    {
        return true;
    }

    return false;
}


bool TakeOptions::isUnlock() const
{
    tibas_boolean boolean;
    boolean = m_options->unlock;
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


TakeOptions& TakeOptions::setForget(bool doForget)
{
    m_options->forget = (tibas_boolean)doForget;
    return *this;
}


bool TakeOptions::isForget() const
{
    tibas_boolean boolean;
    boolean = m_options->forget;
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


TakeOptions& TakeOptions::setRoute(bool doRoute)
{
    m_options->route = (tibas_boolean)doRoute;
    return *this;
}


bool TakeOptions::isRoute() const
{
    tibas_boolean boolean;
    boolean = m_options->route;
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

TakeOptions&
TakeOptions::setFilter(const std::string& filter)
{
    m_options->filter = filter.c_str();
    return *this;
}

std::string
TakeOptions::getFilter() const
{
    return m_options->filter;
}
