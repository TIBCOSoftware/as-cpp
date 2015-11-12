/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Persister.h"

using namespace ASApi;
using namespace std;


Persister::Persister()
: ListenerBase<tibasPersister>(tibasPersister_Free)
{
    
}


Persister::~Persister()
{
    
}


void Persister::create()
{
    AS_CALL(tibasPersister_Create(m_cObject.get(), Persister::onCOpen, Persister::onCLoad, Persister::onCWrite, Persister::onCClose, Persister::onCRead, Persister::onCAlter, this))
}


void Persister::onCOpen(tibasPersister c_persister, tibasAction action, tibasActionResult result)
{
    Persister* persister = (Persister*) c_persister->m_closure;
    if (persister != NULL)
    {
        ActionResult actionResult (result);
        persister->onOpen(OpenAction(action), actionResult);
    }
}


void Persister::onCClose(tibasPersister c_persister, tibasAction action, tibasActionResult result)
{
    Persister* persister = (Persister*) c_persister->m_closure;
    if (persister != NULL)
    {
        ActionResult actionResult (result);
        persister->onClose(CloseAction(action), actionResult);
    }
}


void Persister::onCRead(tibasPersister c_persister, tibasAction action, tibasActionResult result)
{
    Persister* persister = (Persister*) c_persister->m_closure;
    if (persister != NULL)
    {
        ActionResult actionResult (result);
        persister->onRead(ReadAction(action), actionResult);
    }
}


void Persister::onCWrite(tibasPersister c_persister, tibasAction action, tibasActionResult result)
{
    Persister* persister = (Persister*) c_persister->m_closure;
    if (persister != NULL)
    {
        ActionResult actionResult (result);
        persister->onWrite(WriteAction(action), actionResult);
    }
}


void Persister::onCLoad(tibasPersister c_persister, tibasAction action, tibasActionResult result)
{
    Persister* persister = (Persister*) c_persister->m_closure;
    if (persister != NULL)
    {
        ActionResult actionResult (result);
        persister->onLoad(LoadAction(action), actionResult);
    }
}


void Persister::onCAlter(tibasPersister c_persister, tibasAction action, tibasActionResult result)
{
    Persister* persister = (Persister*) c_persister->m_closure;
    if (persister != NULL)
    {
        ActionResult actionResult (result);
        persister->onAlter(AlterAction(action), actionResult);
    }
}
