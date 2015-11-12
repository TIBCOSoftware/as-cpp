/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Action__
#define __Action__


#include <string>

#include "tibas.h"
#include "Tuple.h"
#include "SpaceDef.h"

namespace ASApi
{
    class AS_CPP_API Action
    {
    public:
        std::string getSpaceName() const;
        std::string getMetaspaceName() const;
        
    protected:
        Action(const tibasAction& action);

        const tibasAction& m_action;
    };
}
#endif
