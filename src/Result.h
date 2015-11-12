/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Result__
#define __Result__

#include "Exception.h"
#include "Types.h"

namespace ASApi
{
    class AS_CPP_API Result
    {
    public:
        virtual bool hasError() const = 0;
        
        virtual Status getStatus() const = 0;
        
        virtual Exception getError() const = 0;
    };
}

#endif
