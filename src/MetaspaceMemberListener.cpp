/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "MetaspaceMemberListener.h"
#include "Utils.h"

using namespace ASApi;


MetaspaceMemberListener::MetaspaceMemberListener()
: ListenerTemplate<tibas_onMemberEvent>(tibasMemberListener_Create, onEvent)
{
    
}


MetaspaceMemberListener::~MetaspaceMemberListener()
{

}


void MetaspaceMemberListener::onEvent(tibasMemberEvent memberEvent, void *closure)
{
    MetaspaceMemberListener* metaspaceMemberListener = (MetaspaceMemberListener*) closure;
    if (metaspaceMemberListener != NULL)
    {
        SharedPtr<tibasMember> member (new tibasMember(), Deleter<tibasMember>(tibasMember_Free));
        AS_CALL(tibasMemberEvent_GetMember(memberEvent, member.get()));
        
        tibas_memberEventType eventType;
        AS_CALL(tibasMemberEvent_GetType(memberEvent, &eventType));
        
        switch (eventType)
        {
            case TIBAS_MEMBER_EVENT_JOIN:
            {
                ManagementRole role;
                AS_CALL(tibasMemberEvent_GetManagementRole(memberEvent, &role));
                metaspaceMemberListener->onJoin(Member(member), role);
                break;
            }
                
            case TIBAS_MEMBER_EVENT_UPDATE:
            {
                ManagementRole role;
                AS_CALL(tibasMemberEvent_GetManagementRole(memberEvent, &role));
                metaspaceMemberListener->onUpdate(Member(member), role);
                break;
            }
                
            case TIBAS_MEMBER_EVENT_LEAVE:
                metaspaceMemberListener->onLeave(member);
                break;
                
            default:
                break;
        }
    }
}
