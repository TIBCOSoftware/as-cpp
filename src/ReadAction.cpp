/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "ReadAction.h"
#include "Utils.h"

using namespace ASApi;

ReadAction::ReadAction(const tibasAction& action)
: Action(action)
{
    
}


Tuple ReadAction::getTuple() const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasAction_GetTuple(m_action, tuple.get()));
    return Tuple(tuple);
}
