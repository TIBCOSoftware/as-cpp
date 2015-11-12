/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __WriteOp__
#define __WriteOp__

#include "tibas.h"
#include "Tuple.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API WriteOp
    {
    public:
        typedef tibas_opType Type;
        WriteOp(SharedPtr<tibasOp>& op);
        ~WriteOp();
        
        Type getType() const;
        Tuple getTuple() const;
        
    protected:
        SharedPtr<tibasOp> m_op;
    };
}
#endif
