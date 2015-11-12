/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SpaceResultHandler.h"

using namespace ASApi;

void SpaceResultHandler::onCComplete(tibasSpaceResult result, void *closure)
{
    SpaceResultHandler::Closure* c_closure = (SpaceResultHandler::Closure*) closure;
    if (c_closure != NULL && c_closure->m_handler.get() != NULL)
    {
        c_closure->m_handler->onComplete(SpaceResult(result), c_closure->m_closure);
    }
    delete c_closure;
}
