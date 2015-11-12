/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Metaspace.h"
#include "Exception.h"
#include "Utils.h"
#include "tibas.h"

using namespace ASApi;
using namespace std;

Metaspace::Metaspace()
    : m_metaspace(new tibasMetaspace(), Deleter<tibasMetaspace>(tibasMetaspace_Free))
{
}


Metaspace::Metaspace(SharedPtr<tibasMetaspace>& metaspace)
    : m_metaspace(metaspace)
{
}


Metaspace::Metaspace(tibasMetaspace& metaspace)
    : m_metaspace(new tibasMetaspace(), Deleter<tibasMetaspace>(tibasMetaspace_Free))
{
    (*m_metaspace)->m_ctx = metaspace->m_ctx;
    (*m_metaspace)->m_type = metaspace->m_type;
}


Metaspace::~Metaspace()
{

}


const tibasMetaspace& Metaspace::get() const
{
    return *m_metaspace;
}


tibasMetaspace& Metaspace::get()
{
    return *m_metaspace;
}


Metaspace Metaspace::connect(const string& msName, const MemberDef& memberDef)
{
    string name = msName;

    if (name == "")
    {
        name = "ms";
    }

    SharedPtr<tibasMetaspace> c_ms (new tibasMetaspace(), Deleter<tibasMetaspace>(tibasMetaspace_Free));
    AS_CALL(tibasMetaspace_Connect(c_ms.get(), name.c_str(), memberDef.get()));
    Metaspace ms (c_ms);
    ms.initialize();
    ms.m_authCb = memberDef.getAuthenticationCallback();
    return ms;
}


Metaspace Metaspace::connect(const string& args)
{

    Metaspace ms;
    AS_CALL(tibasMetaspace_ConnectEx(ms.m_metaspace.get(), args.c_str()));
    return ms;
}


Metaspace Metaspace::connect(int numArgs, ...)
{
    ostringstream ostr;
    va_list vl;
    va_start(vl, numArgs);
    for (int i = 0; i < numArgs; ++i)
    {
        char* arg;
        arg = va_arg(vl, char*);
        ostr << arg << " ";
    }
    va_end(vl);

    return connect(ostr.str());
}


void Metaspace::closeAll()
{
    AS_CALL(tibasMetaspace_CloseAll(&get()));
}


void Metaspace::initialize()
{
    SharedPtr<tibasMemberDef> memberDef (new tibasMemberDef(), Deleter<tibasMemberDef>(tibasMemberDef_Free));
    AS_CALL(tibasMetaspace_GetMemberDef (get(), memberDef.get()));
    m_memberDef = memberDef;
}


vector<string> Metaspace::getMetaspaceNames() const
{
    tibasStringList metaspaceNames;
    AS_CALL(tibas_GetMetaspaceNames(&metaspaceNames));
    return asStringListToVector(metaspaceNames);
}


Space Metaspace::getSpace(const string& spaceName, const DistributionRole& distributionRole) const
{
    SharedPtr<tibasSpace> space (new tibasSpace(), Deleter<tibasSpace>(tibasSpace_Free));
    AS_CALL(tibasMetaspace_GetSpace(get(), space.get(), spaceName.c_str(), distributionRole));
    return Space(space);
}


Space Metaspace::getSystemSpace(const string& spaceName) const
{
    SharedPtr<tibasSpace> space (new tibasSpace(), Deleter<tibasSpace>(tibasSpace_Free));
    AS_CALL(tibasMetaspace_GetSystemSpace(get(), space.get(), spaceName.c_str()));
    return Space(space);
}


SpaceState Metaspace::getSpaceState(const string& spaceName) const
{
	SpaceState state;
	AS_CALL(tibasMetaspace_GetSpaceState(get(), spaceName.c_str(), &state));
	return state;
}


vector<string> Metaspace::getUserSpaceNames() const
{
    tibasStringList spaceNameList;
    AS_CALL(tibasMetaspace_GetUserSpaceNames(get(), &spaceNameList));
    return asStringListToVector(spaceNameList);
}


void Metaspace::defineSpace(const SpaceDef& spaceDef) const
{
    AS_CALL(tibasMetaspace_DefineSpace(get(), spaceDef.get()));
}



void Metaspace::dropSpace(const string& spaceName) const
{
    AS_CALL(tibasMetaspace_DropSpace(get(), spaceName.c_str()));
}


void Metaspace::alterSpace(const SpaceDef& spaceDef) const
{
    AS_CALL(tibasMetaspace_AlterSpace(get(), spaceDef.get()));
}


void Metaspace::recoverSpace(const string& spaceName) const
{
    AS_CALL(tibasMetaspace_RecoverSpace(get(), spaceName.c_str()));
}


void Metaspace::recoverSpace(const string& spaceName, const RecoveryOptions& recoveryOptions) const
{
    AS_CALL(tibasMetaspace_RecoverSpaceEx(get(), spaceName.c_str(), recoveryOptions.get()));
}


SpaceDef Metaspace::getSpaceDef( const string& spaceName) const
{
    SharedPtr<tibasSpaceDef> spaceDef (new tibasSpaceDef(), Deleter<tibasSpaceDef>(tibasSpaceDef_Free));
    AS_CALL(tibasMetaspace_GetSpaceDef(get(), spaceDef.get(), spaceName.c_str()));
    return SpaceDef(spaceDef);
}


void Metaspace::listen(const string& spaceName, Listener& listener, const ListenerDef& listenerDef, const string& filter)
{
    listener.start();
    AS_CALL(tibasMetaspace_Listen(get(),spaceName.c_str(), listener.get(), listenerDef.get(), filter.c_str()));
}


void Metaspace::listenSpaceMemberEvents(const string& spaceName, SpaceMemberListener& listener)
{
    listener.start();
    AS_CALL(tibasMetaspace_ListenSpaceMemberEvents(get(), spaceName.c_str(), listener.get()));
}


void Metaspace::listenMemberEvents(MetaspaceMemberListener& listener)
{
    listener.start();
    AS_CALL(tibasMetaspace_ListenMemberEvents(get(), listener.get()));
}


void Metaspace::listenSpaceRemoteMemberEvents(const string& spaceName, SpaceRemoteMemberListener& listener)
{
    listener.start();
    AS_CALL(tibasMetaspace_ListenSpaceRemoteMemberEvents(get(), spaceName.c_str(), listener.get()));
}


void Metaspace::listenRemoteMemberEvents(MetaspaceRemoteMemberListener& listener)
{
    listener.start();
    AS_CALL(tibasMetaspace_ListenRemoteMemberEvents(get(), listener.get()));
}


void Metaspace::listenSpaceState(const string& spaceName, SpaceStateListener& listener)
{
    listener.start();
    AS_CALL(tibasMetaspace_ListenSpaceState(get(), spaceName.c_str(), listener.get()));
}


void Metaspace::listenSpaceDefs(SpaceDefListener &listener)
{
    listener.start();
    AS_CALL(tibasMetaspace_ListenSpaceDef(get(), listener.get()));
}


string Metaspace::getRemoteListen() const
{
    const char* remoteList = NULL;
    AS_CALL(tibasMetaspace_GetRemoteListen(get(), &remoteList));
    return remoteList;
}


Browser Metaspace::browse(const string& spaceName,const BrowserType& browserType, const BrowserDef& browserDef, const string& filter) const
{
    Browser browser;
    AS_CALL(tibasMetaspace_Browse(get(), &browser.get(), spaceName.c_str(), browserType, browserDef.get(), filter.c_str()));
    return browser;
}


EventBrowser Metaspace::browseEvents(const string& spaceName, const EventBrowserDef& eventBrowserDef, const string& filter)
{
    EventBrowser eventBrowser; 
    AS_CALL(tibasMetaspace_BrowseEvents(get(), &eventBrowser.get(), spaceName.c_str(), eventBrowserDef.get(), filter.c_str()));
    return eventBrowser;
}


void Metaspace::beginTransaction()
{
    AS_CALL(tibasMetaspace_BeginTransaction(get()));
}


void Metaspace::commitTransaction()
{
    AS_CALL(tibasMetaspace_CommitTransaction(get()));
}


void Metaspace::rollbackTransaction()
{
    AS_CALL(tibasMetaspace_RollbackTransaction(get()));
}


vector<Member> Metaspace::getRemoteMembers() const
{   
    tibasMemberList memberList;
    AS_CALL(tibasMetaspace_GetRemoteMembers(get(), &memberList));
    return asMemberListToVector(memberList);
}


vector<Member> Metaspace::getMembers() const
{
    tibasMemberList memberList;
    AS_CALL(tibasMetaspace_GetMembers(get(), &memberList));
    return asMemberListToVector(memberList);
}


vector<Member> Metaspace::getSpaceMembers(const string& spaceName) const
{
    tibasMemberList memberList;
    AS_CALL(tibasMetaspace_GetSpaceMembers(get(), &memberList, spaceName.c_str()));
    return asMemberListToVector(memberList);
}


Member Metaspace::getSelfMember() const
{
    SharedPtr<tibasMember> member (new tibasMember(), Deleter<tibasMember>(tibasMember_Free));
    AS_CALL(tibasMetaspace_GetSelfMember(get(), member.get()));
    return Member(member);
}


string Metaspace::getDiscovery() const
{
    const char* discovery = NULL;
    AS_CALL(tibasMetaspace_GetDiscovery(get(), &discovery));
    return discovery;
}


string Metaspace::getListen() const
{
    const char* listen = NULL;
    AS_CALL(tibasMetaspace_GetListen(get(), &listen));
    return listen;
}


string Metaspace::getRemoteDiscovery() const
{
    const char* remoteDiscovery = NULL;
    AS_CALL(tibasMetaspace_GetRemoteDiscovery(get(), &remoteDiscovery));
    return remoteDiscovery;
}


const MemberDef& Metaspace::getMemberDef() const
{
    return m_memberDef;
}








