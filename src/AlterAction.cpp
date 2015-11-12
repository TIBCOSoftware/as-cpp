/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "AlterAction.h"
#include "Utils.h"

using namespace ASApi;

AlterAction::AlterAction(const tibasAction& action)
: Action(action)
{
    
}


SpaceDef AlterAction::getOldSpaceDef() const
{
    SharedPtr<tibasSpaceDef> spaceDef (new tibasSpaceDef(), Deleter<tibasSpaceDef>(tibasSpaceDef_Free));
    AS_CALL(tibasAction_GetOldSpaceDef(m_action, spaceDef.get()));
    return SpaceDef(spaceDef);
}


SpaceDef AlterAction::getSpaceDef() const
{
    SharedPtr<tibasSpaceDef> spaceDef (new tibasSpaceDef(), Deleter<tibasSpaceDef>(tibasSpaceDef_Free));
    AS_CALL(tibasAction_GetSpaceDef(m_action, spaceDef.get()));
    return SpaceDef(spaceDef);
}
