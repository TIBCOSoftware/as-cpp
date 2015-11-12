/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "PutOp.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;


PutOp::PutOp(SharedPtr<tibasOp>& op)
: WriteOp(op)
{
    
}


bool PutOp::hasOldTuple() const
{
    tibas_boolean boolean = tibasOp_HasOldTuple(*m_op);
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


Tuple PutOp::getOldTuple() const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasOp_GetOldTuple(*m_op, tuple.get()));
    return Tuple(tuple);
}


long long PutOp::getTTL() const
{
    long long ttl;
    AS_CALL(tibasOp_GetTTL(*m_op, &ttl));
    return ttl;
}
