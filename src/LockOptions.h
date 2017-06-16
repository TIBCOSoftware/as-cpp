/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __LockOptions__
#define __LockOptions__

#include "tibas.h"
#include "SpaceOptions.h"

namespace ASApi
{
    class AS_CPP_API LockOptions : public SpaceOptions<LockOptions, tibasLockOptions>
    {
    public:
        LockOptions();
        
        LockOptions& setLockWait(long long wait);

        long long getLockWait() const;
        
        LockOptions& setUnlock(bool doLock);

        bool isUnlock() const;
        
        LockOptions& setForget(bool doForget);

        bool isForget() const;

        LockOptions& setFilter(const std::string& filter);
        
        std::string getFilter() const;
    };
}

#endif
