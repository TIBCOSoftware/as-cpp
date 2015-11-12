/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Router__
#define __Router__

#include "tibas.h"
#include <memory>
#include "Action.h"
#include "ReadAction.h"
#include "WriteAction.h"
#include "AlterAction.h"
#include "ActionResult.h"
#include "ListenerBase.h"
#include "OpenAction.h"
#include "CloseAction.h"


namespace ASApi
{
    class AS_CPP_API Router : public ListenerBase<tibasRouter>
    {
    public:
        Router();
        virtual ~Router();

        virtual void create();
        
        static void onCOpen(tibasRouter router, tibasAction action, tibasActionResult result);
        virtual void onOpen(const OpenAction& openAction, ActionResult& actionResult) { }
        
        static void onCClose(tibasRouter router, tibasAction action, tibasActionResult result);
        virtual void onClose(const CloseAction& closeAction, ActionResult& actionResult) { }
        
        static void onCWrite(tibasRouter router, tibasAction action, tibasActionResult result);
        virtual void onWrite (const WriteAction& writeAction, ActionResult& actionResult) { }
        
        static void onCAlter(tibasRouter router, tibasAction action, tibasActionResult result);
        virtual void onAlter(const AlterAction& alterAction, ActionResult& actionResult) { }
    };
}

#endif
