/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __UnlockOptions__
#define __UnlockOptions__

#include "tibas.h"
#include "SpaceOptions.h"

namespace ASApi
{
    class AS_CPP_API UnlockOptions : public SpaceOptions<UnlockOptions, tibasUnlockOptions>
    {
    public:
        UnlockOptions();
        
        UnlockOptions& setLockWait(long long wait);

        long long getLockWait() const;

    };    
}

#endif
