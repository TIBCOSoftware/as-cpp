/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "UnlockOptions.h"
#include "options.h"
#include "Exception.h"

using namespace std;
using namespace ASApi;


UnlockOptions::UnlockOptions()
: SpaceOptions<ASApi::UnlockOptions, tibasUnlockOptions>(tibasUnlockOptions_Initialize)
{
    
}


UnlockOptions& UnlockOptions::setLockWait(long long wait)
{
    m_options->lockWait = wait;
    return *this;
}


long long UnlockOptions::getLockWait() const
{
    return m_options->lockWait;
}

