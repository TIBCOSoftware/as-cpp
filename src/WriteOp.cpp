/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "WriteOp.h"
#include "Utils.h"
#include <memory>

using namespace ASApi;
using namespace std;


WriteOp::WriteOp(SharedPtr<tibasOp>& op)
: m_op(op)
{
    
}


WriteOp::~WriteOp()
{
}


WriteOp::Type WriteOp::getType() const
{
    Type type;
    AS_CALL(tibasOp_GetType(*m_op, &type));
    return type;
}


Tuple WriteOp::getTuple() const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasOp_GetTuple(*m_op, tuple.get()));
    return Tuple(tuple);
}


