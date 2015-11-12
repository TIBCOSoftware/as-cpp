/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __PutOp__
#define __PutOp__

#include "WriteOp.h"

namespace ASApi
{
    class AS_CPP_API PutOp : public WriteOp
    {
    public:
        PutOp(SharedPtr<tibasOp>& op);
        
        bool hasOldTuple() const;
        Tuple getOldTuple() const;
        long long getTTL() const;
    };
}

#endif
