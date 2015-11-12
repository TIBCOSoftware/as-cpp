/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "RecoveryOptions.h"
#include "options.h"
#include "Exception.h"

using namespace std;
using namespace ASApi;


RecoveryOptions::RecoveryOptions()
{
    
}

const tibasRecoveryOptions& RecoveryOptions::get() const
{
    return *m_recoveryOptions;
}


tibasRecoveryOptions& RecoveryOptions::get()
{
    return *m_recoveryOptions;
}
