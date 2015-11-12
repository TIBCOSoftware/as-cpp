/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Router.h"

using namespace ASApi;
using namespace std;


Router::Router()
: ListenerBase<tibasRouter>(tibasRouter_Free)
{
    
}


Router::~Router()
{
    
}


void Router::create()
{
    AS_CALL(tibasRouter_Create(m_cObject.get(), Router::onCOpen, Router::onCWrite, Router::onCClose, Router::onCAlter, this))
}


void Router::onCOpen(tibasRouter c_router, tibasAction action, tibasActionResult result)
{
    Router* router = (Router*) c_router->m_closure;
    if (router != NULL)
    {
        ActionResult actionResult (result);
        router->onOpen(OpenAction(action), actionResult);
    }
}


void Router::onCClose(tibasRouter c_router, tibasAction action, tibasActionResult result)
{
    Router* router = (Router*) c_router->m_closure;
    if (router != NULL)
    {
        ActionResult actionResult (result);
        router->onClose(CloseAction(action), actionResult);
    }
}


void Router::onCWrite(tibasRouter c_router, tibasAction action, tibasActionResult result)
{
    Router* router = (Router*) c_router->m_closure;
    if (router != NULL)
    {
        ActionResult actionResult (result);
        router->onWrite(WriteAction(action), actionResult);
    }
}


void Router::onCAlter(tibasRouter c_router, tibasAction action, tibasActionResult result)
{
    Router* router = (Router*) c_router->m_closure;
    if (router != NULL)
    {
        ActionResult actionResult (result);
        router->onAlter(AlterAction(action), actionResult);
    }
}
