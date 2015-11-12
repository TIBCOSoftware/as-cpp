/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __SpaceRemoteMemberListener__
#define __SpaceRemoteMemberListener__

#include "tibas.h"
#include <memory>
#include <string>
#include "ListenerTemplate.h"
#include "Member.h"

namespace ASApi
{
    class AS_CPP_API SpaceRemoteMemberListener : public ListenerTemplate<tibas_onSpaceRemoteMemberEvent>
    {
    public:
        SpaceRemoteMemberListener();
        virtual ~SpaceRemoteMemberListener();
        
        static void onEvent(tibasSpaceRemoteMemberEvent spaceRemoteMemberEvent, void* closure);
        
        virtual void onJoin(const std::string& spaceName, const Member& member, const Member& proxyMember) { }
        virtual void onLeave(const std::string& spaceName, const Member& member, const Member& proxyMember) { }
    };
}

#endif
