/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __AlterAction__
#define __AlterAction__

#include "Action.h"

namespace ASApi
{
    class AS_CPP_API AlterAction : public Action
    {
    public:
        AlterAction(const tibasAction& action);
        
        SpaceDef getSpaceDef() const;
        SpaceDef getOldSpaceDef() const;
    };
}

#endif /* defined(__as2_1_cpp__AlterAction__) */
