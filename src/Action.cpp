/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Action.h"


using namespace ASApi;
using namespace std;


Action::Action(const tibasAction& action)
: m_action(action)
{
    
}


string Action::getSpaceName() const
{
    const char* spaceName;
    AS_CALL(tibasAction_GetSpaceName(m_action, &spaceName));
    return spaceName;
}


string Action::getMetaspaceName() const
{
    const char* msName;
    AS_CALL(tibasAction_GetMetaspaceName(m_action, &msName));
    return msName;
}
