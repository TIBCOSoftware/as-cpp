/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __RecoveryOptions__
#define __RecoveryOptions__

#include <memory>
#include "tibas.h"
#include "SpaceOptions.h"

namespace ASApi
{
    class AS_CPP_API RecoveryOptions
    {
    public:
        RecoveryOptions();

        const tibasRecoveryOptions& get() const;

        tibasRecoveryOptions& get();
        
    private:
        SharedPtr<tibasRecoveryOptions> m_recoveryOptions;
    };
}

#endif
