/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SpaceRemoteMemberListener.h"

using namespace ASApi;

SpaceRemoteMemberListener::SpaceRemoteMemberListener()
: ListenerTemplate<tibas_onSpaceRemoteMemberEvent>(tibasSpaceRemoteMemberListener_Create, onEvent)
{
    
}


SpaceRemoteMemberListener::~SpaceRemoteMemberListener()
{
}


void SpaceRemoteMemberListener::onEvent(tibasSpaceRemoteMemberEvent spaceRemoteMemberEvent, void *closure)
{
    SpaceRemoteMemberListener* spaceRemoteMemberListener = (SpaceRemoteMemberListener*) closure;
    if (spaceRemoteMemberListener != NULL)
    {
        SharedPtr<tibasMember> remoteMember (new tibasMember(), Deleter<tibasMember>(tibasMember_Free));
        AS_CALL(tibasSpaceRemoteMemberEvent_GetRemoteMember(spaceRemoteMemberEvent, remoteMember.get()));
        
        SharedPtr<tibasMember> proxyMember (new tibasMember(), Deleter<tibasMember>(tibasMember_Free));
        AS_CALL(tibasSpaceRemoteMemberEvent_GetProxyMember(spaceRemoteMemberEvent, proxyMember.get()));
        
        tibas_memberEventType eventType;
        AS_CALL(tibasSpaceRemoteMemberEvent_GetType(spaceRemoteMemberEvent, &eventType));
        
        const char* spaceName;
        AS_CALL(tibasSpaceRemoteMemberEvent_GetSpaceName(spaceRemoteMemberEvent, &spaceName));
        
        switch (eventType)
        {
            case TIBAS_MEMBER_EVENT_JOIN:
                spaceRemoteMemberListener->onJoin(spaceName, Member(remoteMember), Member(proxyMember));
                break;
                
            case TIBAS_MEMBER_EVENT_LEAVE:
                spaceRemoteMemberListener->onLeave(spaceName, Member(remoteMember), Member(proxyMember));
                break;
                
            default:
                break;
        }
    }
}
