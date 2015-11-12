/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __SpaceStateListener__
#define __SpaceStateListener__

#include <memory>
#include <string>
#include "tibas.h"
#include "ListenerTemplate.h"

namespace ASApi
{
    class AS_CPP_API SpaceStateListener : public ListenerTemplate<tibas_onSpaceStateChange>
    {
    public:
        typedef tibas_spaceState SpaceState;
        
        SpaceStateListener();
        virtual ~SpaceStateListener();
        
        virtual void onStateChange(const std::string& spaceName, const SpaceState& spaceState) = 0;
        static void onCStateChage(const char* spaceName, tibas_spaceState spaceState, void* closure);
    };
}

#endif
