/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __ResultList__
#define __ResultList__

#include "Exception.h"
#include "Result.h"
#include "Types.h"

namespace ASApi
{
    class AS_CPP_API ResultList
    {
    public:
        virtual bool hasError() const = 0;
        
        virtual Exception getError(int index) const = 0;
        
        virtual Status getStatus(int index) const = 0;
        
        virtual int size() const = 0;
    };
}

#endif
