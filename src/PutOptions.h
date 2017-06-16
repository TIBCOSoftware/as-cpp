/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __PutOptions__
#define __PutOptions__

#include "tibas.h"
#include "SpaceOptions.h"

namespace ASApi
{
    class AS_CPP_API PutOptions : public SpaceOptions<PutOptions, tibasPutOptions>
    {
    public:
        PutOptions();
        
        PutOptions& setLockWait(long long wait);

        long long getLockWait() const;
        
        PutOptions& setLock(bool doLock);

        bool isLock() const;
        
        PutOptions& setForget(bool doForget);

        bool isForget() const;

        PutOptions& setRoute(bool doRoute);

        bool isRoute() const;

        PutOptions& setTTL(long long ttl);

        long long getTTL();

        PutOptions& setFilter(const std::string& filter);
        
        std::string getFilter() const;
    };    
}

#endif
