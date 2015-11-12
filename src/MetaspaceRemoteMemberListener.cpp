/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "MetaspaceRemoteMemberListener.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

MetaspaceRemoteMemberListener::MetaspaceRemoteMemberListener()
: ListenerTemplate<tibas_onRemoteMemberEvent>(tibasRemoteMemberListener_Create, onEvent)
{
    
}


MetaspaceRemoteMemberListener::~MetaspaceRemoteMemberListener()
{
}


void MetaspaceRemoteMemberListener::onEvent(tibasRemoteMemberEvent remoteMemberEvent, void *closure)
{
    MetaspaceRemoteMemberListener* remoteMemberListener = (MetaspaceRemoteMemberListener*) closure;
    if (remoteMemberListener != NULL)
    {
        SharedPtr<tibasMember> remoteMember (new tibasMember(), Deleter<tibasMember>(tibasMember_Free));
        AS_CALL(tibasRemoteMemberEvent_GetRemoteMember(remoteMemberEvent, remoteMember.get()));

        SharedPtr<tibasMember> proxyMember;
        // TODO!!!
//        SharedPtr<tibasMember> proxyMember (new tibasMember(), Deleter<tibasMember>(tibasMember_Free));
//        AS_CALL(tibasRemoteMemberEvent_GetProxyMembers(remoteMemberEvent, proxyMember.get()));
        
        tibas_memberEventType eventType;
        AS_CALL(tibasRemoteMemberEvent_GetType(remoteMemberEvent, &eventType));
        
        switch (eventType)
        {
            case TIBAS_MEMBER_EVENT_JOIN:
                remoteMemberListener->onJoin(Member(remoteMember), Member(proxyMember));
                break;
                
            case TIBAS_MEMBER_EVENT_LEAVE:
                remoteMemberListener->onLeave(Member(remoteMember), Member(proxyMember));
                break;
                
            default:
                break;
        }
    }
}
