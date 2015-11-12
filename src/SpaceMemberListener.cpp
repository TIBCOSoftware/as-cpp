/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SpaceMemberListener.h"

using namespace ASApi;

SpaceMemberListener::SpaceMemberListener()
: ListenerTemplate<tibas_onSpaceMemberEvent>(tibasSpaceMemberListener_Create, onEvent)
{
    
}


SpaceMemberListener::~SpaceMemberListener()
{
}


void SpaceMemberListener::onEvent(tibasSpaceMemberEvent spaceMemberEvent, void *closure)
{
    SpaceMemberListener* spaceMemberListener = (SpaceMemberListener*) closure;
    if (spaceMemberListener != NULL)
    {
        SharedPtr<tibasMember> member (new tibasMember(), Deleter<tibasMember>(tibasMember_Free));
        AS_CALL(tibasSpaceMemberEvent_GetMember(spaceMemberEvent, member.get()));
        
        tibas_memberEventType eventType;
        AS_CALL(tibasSpaceMemberEvent_GetType(spaceMemberEvent, &eventType));
        
        const char* spaceName;
        AS_CALL(tibasSpaceMemberEvent_GetSpaceName(spaceMemberEvent, &spaceName));
        
        switch (eventType)
        {
            case TIBAS_MEMBER_EVENT_JOIN:
            {
                DistributionRole role;
                AS_CALL(tibasSpaceMemberEvent_GetDistributionRole(spaceMemberEvent, &role));
                spaceMemberListener->onJoin(spaceName, Member(member), role);
                break;
            }
                
            case TIBAS_MEMBER_EVENT_UPDATE:
            {
                DistributionRole role;
                AS_CALL(tibasSpaceMemberEvent_GetDistributionRole(spaceMemberEvent, &role));
                spaceMemberListener->onUpdate(spaceName, Member(member), role);
                break;
            }
                
            case TIBAS_MEMBER_EVENT_LEAVE:
                spaceMemberListener->onLeave(spaceName, member);
                break;
                
            default:
                break;
        }
    }
}
