/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __CloseAction__
#define __CloseAction__

#include "Action.h"

namespace ASApi
{
    class AS_CPP_API CloseAction : public Action
    {
    public:
        CloseAction(const tibasAction& action);
    };
}

#endif
