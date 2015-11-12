/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __MetaspaceRemoteMemberListener__
#define __MetaspaceRemoteMemberListener__

#include "tibas.h"
#include <memory>
#include <string>
#include "ListenerTemplate.h"
#include "Member.h"

namespace ASApi
{
    class AS_CPP_API MetaspaceRemoteMemberListener : public ListenerTemplate<tibas_onRemoteMemberEvent>
    {
    public:
        MetaspaceRemoteMemberListener();
        virtual ~MetaspaceRemoteMemberListener();
        
        static void onEvent(tibasRemoteMemberEvent remoteMemberEvent, void* closure);
        
        virtual void onJoin(const Member& member, const Member& proxyMember) { }
        virtual void onLeave(const Member& member, const Member& proxyMember) { }
    };
}

#endif
