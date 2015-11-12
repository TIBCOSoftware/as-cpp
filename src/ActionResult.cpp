/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "ActionResult.h"
#include "Utils.h"
#include "SharedPtr.h"

using namespace ASApi;


ActionResult::ActionResult(tibasActionResult& actionResult)
    : m_actionResult(actionResult)
{
}


ActionResult& ActionResult::setFailed()
{
    AS_CALL(tibasActionResult_SetFailed(m_actionResult));
    return *this;
}


ActionResult& ActionResult::setFailed(const Status& status)
{
    AS_CALL(tibasActionResult_SetFailedEx(m_actionResult, status));
    return *this;
}


ASApi::Status ActionResult::getStatus() const
{
    Status status = TIBAS_OK;
    AS_CALL(tibasActionResult_GetStatus(m_actionResult, &status));
    return status;
}


ActionResult& ActionResult::setTuple(const Tuple& tuple)
{
    AS_CALL(tibasActionResult_SetTuple(m_actionResult, tuple.get()));
    return *this;
}


Tuple ActionResult::getTuple() const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasActionResult_GetTuple(m_actionResult, tuple.get()));
    return Tuple(tuple);
}
