/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __LoadAction__
#define __LoadAction__

#include "Action.h"

namespace ASApi
{
    class AS_CPP_API LoadAction : public Action
    {
    public:
        LoadAction(const tibasAction& action);
    };
}

#endif
