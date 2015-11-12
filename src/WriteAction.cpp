/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "WriteAction.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;


WriteAction::WriteAction(const tibasAction& action)
: Action(action)
{
    
}


vector<WriteOp> WriteAction::getOps() const
{
    vector<WriteOp> ops;
    tibasOpList opList;
    AS_CALL(tibasAction_GetOps(m_action, &opList));
    
    int size = 0;
    AS_CALL(tibasOpList_Size(opList, &size));
    
    for (int i = 0; i < size; ++i)
    {
        SharedPtr<tibasOp> op (new tibasOp(), Deleter<tibasOp>(tibasOp_Free));
        ops.push_back(op);
    }
    return ops;
}
