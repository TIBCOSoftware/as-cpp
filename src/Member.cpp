/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Member.h"
#include "Exception.h"
#include "Metaspace.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;


Member::Member(const Metaspace& metaspace, const string& memberId, const string& memberName)
: m_member(new tibasMember(), Deleter<tibasMember>(tibasMember_Free))
{
    AS_CALL(tibasMember_Create(m_member.get(), metaspace.get(), memberId.c_str(), memberName.c_str()));
}


Member::Member(SharedPtr<tibasMember>& member)
: m_member(member)
{
}


Member::~Member()
{
    
}


const tibasMember& Member::get() const
{
    return *m_member;
}


tibasMember& Member::get()
{
    return *m_member;
}


string Member::getName() const
{
    const char* name = NULL;
    AS_CALL(tibasMember_GetName(get(), &name));
    return name;
}


ManagementRole Member::getManagementRole() const
{
    tibas_managementRole managementRole;
    AS_CALL(tibasMember_GetManagementRole(get(), &managementRole));
    return managementRole;
}


DistributionRole Member::getDistributionRole(const string& spaceName) const
{
    tibas_distributionRole distributionRole;
    char* spaceName_c = const_cast<char*>(spaceName.c_str());
    AS_CALL(tibasMember_GetDistributionRole(get(), spaceName_c, &distributionRole));
    return distributionRole;
}


Tuple Member::getContext() const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasMember_GetContext(get(), tuple.get()));
    return Tuple(tuple);
}


string Member::getHostAddress() const
{
    const char* hostAddress = NULL;
    AS_CALL(tibasMember_GetHostAddress(get(), &hostAddress));
    return hostAddress;
}


int Member::getPort() const
{
    int port = 0;
    AS_CALL(tibasMember_GetPort(get(), &port));
    return port;
}


time_t Member::getJoinTime() const
{
    time_t joinTime;
    AS_CALL(tibasMember_GetJoinTime(get(), &joinTime));
    return joinTime;
}


string Member::getId() const
{
    const char* id = NULL;
    AS_CALL(tibasMember_GetId(get(), &id));
    return id;
}


vector<Member> Member::getProxies() const
{
    tibasMemberList proxyMemberIds;
    AS_CALL(tibasMember_GetProxies(get(), &proxyMemberIds));

    tibas_int size;
    AS_CALL(tibasMemberList_Size(proxyMemberIds, &size));
    
    vector<Member> proxies;
    for (int i = 0; i < size; ++i)
    {
        SharedPtr<tibasMember> member (new tibasMember(), tibasMember_Free);
        AS_CALL(tibasMemberList_Get(proxyMemberIds, member.get(), i));
        proxies.push_back(member);
    }
    return proxies;
}




