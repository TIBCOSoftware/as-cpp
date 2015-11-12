/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _SpaceResultHandler_h
#define _SpaceResultHandler_h

#include "SpaceResult.h"
#include "tibas.h"

namespace ASApi
{
    class AS_CPP_API SpaceResultHandler
    {
    public:
        struct Closure
        {
            SharedPtr<SpaceResultHandler> m_handler;
            void* m_closure;
        };
        
        virtual void onComplete(const SpaceResult& spaceResult, void* closure) = 0;
        
        static void onCComplete(tibasSpaceResult result, void* closure);
    };
}

#endif
