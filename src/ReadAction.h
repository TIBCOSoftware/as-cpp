/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __ReadAction__
#define __ReadAction__

#include "Action.h"
#include "Tuple.h"

namespace ASApi
{
    class AS_CPP_API ReadAction : public Action
    {
    public:
        ReadAction(const tibasAction& action);
        
        Tuple getTuple() const;
    };
}

#endif
