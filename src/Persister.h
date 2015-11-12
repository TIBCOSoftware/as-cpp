/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Persister__
#define __Persister__

#include "tibas.h"
#include <memory>
#include "Action.h"
#include "OpenAction.h"
#include "CloseAction.h"
#include "LoadAction.h"
#include "ReadAction.h"
#include "WriteAction.h"
#include "AlterAction.h"
#include "ActionResult.h"
#include "ListenerBase.h"


namespace ASApi
{
    class AS_CPP_API Persister : public ListenerBase<tibasPersister>
    {
    public:
        Persister();
        virtual ~Persister();

        void create();

        static void onCOpen(tibasPersister persister, tibasAction action, tibasActionResult result);
        virtual void onOpen(const OpenAction& openAction, ActionResult& actionResult) { }
        
        static void onCClose(tibasPersister persister, tibasAction action, tibasActionResult result);
        virtual void onClose(const CloseAction& closeAction, ActionResult& actionResult) { }
        
        static void onCRead(tibasPersister persister, tibasAction action, tibasActionResult result);
        virtual void onRead(const ReadAction& readAction, ActionResult& actionResult) { }

        static void onCWrite(tibasPersister persister, tibasAction action, tibasActionResult result);
        virtual void onWrite (const WriteAction& writeAction, ActionResult& actionResult) { }
        
        static void onCLoad(tibasPersister persister, tibasAction action, tibasActionResult result);
        virtual void onLoad (const LoadAction& loadAction, ActionResult& actionResult) { }
        
        static void onCAlter(tibasPersister persister, tibasAction action, tibasActionResult result);
        virtual void onAlter(const AlterAction& alterAction, ActionResult& actionResult) { }
    };
}

#endif
