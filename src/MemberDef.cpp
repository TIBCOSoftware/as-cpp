/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "MemberDef.h"
#include "Exception.h"
#include "Utils.h"
#include "tibas.h"

using namespace ASApi;
using namespace std;

MemberDef::MemberDef()
: m_memberDef(new tibasMemberDef(), Deleter<tibasMemberDef>(tibasMemberDef_Free))
{
    AS_CALL(tibasMemberDef_Create(m_memberDef.get()));
}


MemberDef::~MemberDef()
{
    
}


const MemberDef& MemberDef::operator= (SharedPtr<tibasMemberDef>& memberDef)
{
    m_memberDef = memberDef;
    return *this;
}


const tibasMemberDef& MemberDef::get() const
{
    return *m_memberDef;
}


tibasMemberDef& MemberDef::get()
{
    return *m_memberDef;
}


MemberDef& MemberDef::setMemberName(const string& name)
{
    AS_CALL(tibasMemberDef_SetMemberName(get(), name.c_str()));
    return *this;
}


string MemberDef::getMemberName() const
{
    const char* name = NULL;
    AS_CALL(tibasMemberDef_GetMemberName(get(), &name));
    return name;
}


MemberDef& MemberDef::setDataStore(const string& dataStor)
{
    AS_CALL(tibasMemberDef_SetDataStore(get(), dataStor.c_str()));
    return *this;
}


string MemberDef::getDataStore() const
{
    const char* dataStore = NULL;
    AS_CALL(tibasMemberDef_GetDataStore(get(), &dataStore));
    return dataStore;
}


MemberDef& MemberDef::setRxBufferSize(long long bufferSize)
{
    AS_CALL(tibasMemberDef_SetRxBufferSize(get(), bufferSize));
    return *this;
}


long long MemberDef::getRxBufferSize() const
{
    tibas_long bufferSize = 0;
    AS_CALL(tibasMemberDef_GetRxBufferSize(get(), &bufferSize));
    return bufferSize;
}


MemberDef& MemberDef::setWorkerThreadCount(int count)
{
    AS_CALL(tibasMemberDef_SetWorkerThreadCount(get(), count));
    return *this;
}


int MemberDef::getWorkerThreadCount() const
{
    tibas_int count = 0;
    AS_CALL(tibasMemberDef_GetWorkerThreadCount(get(), &count));
    return count;
}


MemberDef& MemberDef::setTransportThreadCount(int count)
{
    AS_CALL(tibasMemberDef_SetTransportThreadCount(get(), count));
    return *this;
}


int MemberDef::getTransportThreadCount() const
{
    tibas_int count = 0;
    AS_CALL(tibasMemberDef_GetTransportThreadCount(get(), &count));
    return count;
}


MemberDef& MemberDef::setConnectTimeout(long long timeout)
{
    AS_CALL(tibasMemberDef_SetConnectTimeout(get(), timeout));
    return *this;
}


long long MemberDef::getConnectTimeout() const
{
    long long timeout = 0;
    AS_CALL(tibasMemberDef_GetConnectTimeout(get(), &timeout));
    return timeout;
}


MemberDef& MemberDef::setListen(const string& listen)
{
    AS_CALL(tibasMemberDef_SetListen(get(), listen.c_str()));
    return *this;
}


string MemberDef::getListen() const
{
    const char* listen;
    AS_CALL(tibasMemberDef_GetListen(get(), &listen));
    return listen;
}


MemberDef& MemberDef::setRemoteListen(const string& remoteListen)
{
    AS_CALL(tibasMemberDef_SetRemoteListen(get(), remoteListen.c_str()));
    return *this;
}


string MemberDef::getRemoteListen() const
{
    const char* remoteListen;
    AS_CALL(tibasMemberDef_GetRemoteListen(get(), &remoteListen));
    return remoteListen;
}


MemberDef& MemberDef::setDiscovery(const string& discovery)
{
    AS_CALL(tibasMemberDef_SetDiscovery(get(), discovery.c_str()));
    return *this;
}


string MemberDef::getDiscovery() const
{
    const char* discovery;
    AS_CALL(tibasMemberDef_GetDiscovery(get(), &discovery));
    return discovery;
}


MemberDef& MemberDef::setRemoteDiscovery(const string& remoteDiscovery)
{
    AS_CALL(tibasMemberDef_SetRemoteDiscovery(get(), remoteDiscovery.c_str()));
    return *this;
}


string MemberDef::getRemoteDiscovery() const
{
    const char* discovery;
    AS_CALL(tibasMemberDef_GetRemoteDiscovery(get(), &discovery));
    return discovery;
}


MemberDef& MemberDef::setContext(const Tuple& context)
{
    AS_CALL(tibasMemberDef_SetContext(get(), context.get()));
    return *this;
}


Tuple MemberDef::getContext() const
{
    SharedPtr<tibasTuple> context (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasMemberDef_GetContext(get(), context.get()));
    return Tuple(context);
}


MemberDef& MemberDef::setSecurityPolicyFile(const string& fileName)
{
    AS_CALL(tibasMemberDef_SetSecurityPolicyFile(get(), fileName.c_str()));
    return *this;
}


string MemberDef::getSecurityPolicyFile() const
{
    const char* fileName = NULL;
    AS_CALL(tibasMemberDef_GetSecurityPolicyFile(get(), &fileName));
    return fileName;
}


MemberDef& MemberDef::setSecurityTokenFile(const string& fileName)
{
    AS_CALL(tibasMemberDef_SetSecurityTokenFile(get(), fileName.c_str()));
    return *this;
}


string MemberDef::getSecurityTokenFile() const
{
    const char* fileName = NULL;
    AS_CALL(tibasMemberDef_GetSecurityTokenFile(get(), &fileName));
    return fileName;
}


MemberDef& MemberDef::setIdentityPassword(const string& identityPassword)
{
    AS_CALL(tibasMemberDef_SetIdentityPassword(get(), identityPassword.c_str()));
    return *this;
}


string MemberDef::getIdentityPassword() const
{
    const char* identityPassword = NULL;
    AS_CALL(tibasMemberDef_GetIdentityPassword(get(), &identityPassword));
    return identityPassword;
}


MemberDef& MemberDef::setAuthenticationCallback(SharedPtr<AuthenticationCallback> &authCb)
{
    AS_CALL(tibasMemberDef_SetAuthenticationCallback(get(), AuthenticationCallback::callback, (void*)authCb.get()))
    m_authCb = authCb;
    return *this;
}


const SharedPtr<AuthenticationCallback>& MemberDef::getAuthenticationCallback() const
{
    return m_authCb;
}


MemberDef& MemberDef::setMemberTimeout(long long timeout)
{
	AS_CALL(tibasMemberDef_SetMemberTimeout(get(), timeout));
	return *this;
}


long long MemberDef::getMemberTimeout() const
{
	long long timeout;
	AS_CALL(tibasMemberDef_GetMemberTimeout(get(), &timeout));
	return timeout;
}


MemberDef& MemberDef::setClientTimeout(long long timeout)
{
	AS_CALL(tibasMemberDef_SetClientTimeout(get(), timeout));
	return *this;
}


long long MemberDef::getClientTimeout() const
{
	long long timeout;
	AS_CALL(tibasMemberDef_GetClientTimeout(get(), &timeout));
	return timeout;
}


MemberDef& MemberDef::setClusterSuspendThreshold(int threshold)
{
	AS_CALL(tibasMemberDef_SetClusterSuspendThreshold(get(), threshold));
	return *this;
}


int MemberDef::getClusterSuspendThreshold() const
{
	int threshold;
	AS_CALL(tibasMemberDef_GetClusterSuspendThreshold(get(), &threshold));
	return threshold;
}
