/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SpaceResult.h"

using namespace std;
using namespace ASApi;

SpaceResult::SpaceResult(const tibasSpaceResult& spaceResult)
: m_spaceResult(spaceResult)
{
    
}


SpaceResult::~SpaceResult()
{
    
}


bool SpaceResult::hasError() const
{
    tibas_boolean boolean = tibasSpaceResult_HasError(m_spaceResult);
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


Status SpaceResult::getStatus() const
{
    Status status = TIBAS_OK;
    AS_CALL(tibasSpaceResult_GetStatus(m_spaceResult, &status));
    return status;
}


Exception SpaceResult::getError() const
{
    tibasError error;
    AS_CALL(tibasSpaceResult_GetError(m_spaceResult, &error));
    return Exception(error);
}


Tuple SpaceResult::getTuple() const
{
    tibasTuple tuple;
    AS_CALL(tibasSpaceResult_GetTuple(m_spaceResult, &tuple));
    return Tuple(tuple);
}
