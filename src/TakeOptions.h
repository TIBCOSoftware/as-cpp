/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __TakeOptions__
#define __TakeOptions__

#include "tibas.h"
#include "SpaceOptions.h"

namespace ASApi
{
    class AS_CPP_API TakeOptions : public SpaceOptions<TakeOptions, tibasTakeOptions>
    {
    public:
        TakeOptions();
        
        TakeOptions& setLockWait(long long wait);

        long long getLockWait() const;
        
        TakeOptions& setLock(bool doLock);

        TakeOptions& setUnlock(bool doLock);

        bool isLock() const;

        bool isUnlock() const;
        
        TakeOptions& setForget(bool doForget);

        bool isForget() const;

        TakeOptions& setRoute(bool doRoute);

        bool isRoute() const;

    };    
}

#endif
