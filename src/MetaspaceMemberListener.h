/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __MetaspaceMemberListener__
#define __MetaspaceMemberListener__

#include "tibas.h"
#include "Exception.h"
#include <memory>
#include <string>
#include "ListenerTemplate.h"
#include "Member.h"

namespace ASApi
{
    class AS_CPP_API MetaspaceMemberListener : public ListenerTemplate<tibas_onMemberEvent>
    {
    public:
        MetaspaceMemberListener();
        virtual ~MetaspaceMemberListener();
        
        static void onEvent(tibasMemberEvent memberEvent, void* closure);
        
        virtual void onJoin(const Member& member, ManagementRole role) { }
        virtual void onUpdate(const Member& member, ManagementRole role) { }
        virtual void onLeave(const Member& member) { }
    };
}
#endif
