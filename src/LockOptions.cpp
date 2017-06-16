/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "LockOptions.h"
#include "options.h"
#include "Exception.h"

using namespace std;
using namespace ASApi;


LockOptions::LockOptions()
: SpaceOptions<ASApi::LockOptions, tibasLockOptions>(tibasLockOptions_Initialize)
{
    
}


LockOptions& LockOptions::setLockWait(long long wait)
{
    m_options->lockWait = wait;
    return *this;
}


long long LockOptions::getLockWait() const
{
    return m_options->lockWait;
}

LockOptions& LockOptions::setForget(bool doForget)
{
    m_options->forget = (tibas_boolean)doForget;
    return *this;
}


bool LockOptions::isForget() const
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

LockOptions&
LockOptions::setFilter(const std::string& filter)
{
    m_options->filter = filter.c_str();
    return *this;
}

std::string
LockOptions::getFilter() const
{
    return m_options->filter;
}
