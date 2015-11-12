/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __WriteAction__
#define __WriteAction__

#include <vector>
#include "Action.h"
#include "SpaceDef.h"
#include "WriteOp.h"

namespace ASApi
{
    class AS_CPP_API WriteAction : public Action
    {
    public:
        WriteAction(const tibasAction& action);
        
        std::vector<WriteOp> getOps() const;
    };
}

#endif
