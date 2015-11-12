/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __TakeOp__
#define __TakeOp__

#include "WriteOp.h"

namespace ASApi
{
    class AS_CPP_API TakeOp : public WriteOp
    {
    public:
        TakeOp(SharedPtr<tibasOp>& op);
    };
}

#endif
