/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __OpenAction__
#define __OpenAction__

#include "Action.h"

namespace ASApi
{
    class AS_CPP_API OpenAction : public Action
    {
    public:
        OpenAction(const tibasAction& action);
    };
}
#endif
