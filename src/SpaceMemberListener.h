/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __SpaceMemberListener__
#define __SpaceMemberListener__

#include "tibas.h"
#include <memory>
#include <string>
#include "ListenerTemplate.h"
#include "Member.h"

namespace ASApi
{
    class AS_CPP_API SpaceMemberListener : public ListenerTemplate<tibas_onSpaceMemberEvent>
    {
    public:
        SpaceMemberListener();
        virtual ~SpaceMemberListener();
        
        static void onEvent(tibasSpaceMemberEvent spaceMemberEvent, void* closure);
        
        virtual void onJoin(const std::string& spaceName, const Member& member, DistributionRole role) { }
        virtual void onUpdate(const std::string& spaceName, const Member& member, DistributionRole role) { }
        virtual void onLeave(const std::string& spaceName, const Member& member) { }
    };
}

#endif
