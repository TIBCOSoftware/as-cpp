/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _MemberDef_h
#define _MemberDef_h

#include <string>
#include "Tuple.h"
#include "Exception.h"
#include "AuthenticationCallback.h"

namespace ASApi
{
    class AS_CPP_API MemberDef
    {
    public:
        MemberDef();
        ~MemberDef();

        const MemberDef& operator= (SharedPtr<tibasMemberDef>& memberDef);
        
        const tibasMemberDef& get() const;

        tibasMemberDef& get();
        
        MemberDef& setMemberName(const std::string& name);

        std::string getMemberName() const;

        MemberDef& setDataStore(const std::string& dataStor);

        std::string getDataStore() const;

        MemberDef& setRxBufferSize(long long bufferSize);

        long long getRxBufferSize() const;

        MemberDef& setWorkerThreadCount(int count);

        int getWorkerThreadCount() const;

        MemberDef& setTransportThreadCount(int count);

        int getTransportThreadCount() const;

        MemberDef& setConnectTimeout(long long timeout);

        long long getConnectTimeout() const;

		MemberDef& setMemberTimeout(long long timeout);

		long long getMemberTimeout() const;

		MemberDef& setClientTimeout(long long timeout);

		long long getClientTimeout() const;

		MemberDef& setClusterSuspendThreshold(int threshold);

		int getClusterSuspendThreshold() const;

		MemberDef& setListen(const std::string& listen);

        std::string getListen() const;

        MemberDef& setRemoteListen(const std::string& remoteListen);

        std::string getRemoteListen() const;

        MemberDef& setDiscovery(const std::string& discovery);

        std::string getDiscovery() const;

        MemberDef& setRemoteDiscovery(const std::string& discovery);

        std::string getRemoteDiscovery() const;

        MemberDef& setContext(const Tuple& context);

        Tuple getContext() const;

        MemberDef& setSecurityPolicyFile(const std::string& fileName);

        std::string getSecurityPolicyFile() const;

        MemberDef& setSecurityTokenFile(const std::string& fileName);

        std::string getSecurityTokenFile() const;

        MemberDef& setIdentityPassword(const std::string& identityPassword);

        std::string getIdentityPassword() const;

        MemberDef& setAuthenticationCallback(SharedPtr<AuthenticationCallback>& authCb);
        
        const SharedPtr<AuthenticationCallback>& getAuthenticationCallback() const;
        
    private:
        SharedPtr<tibasMemberDef> m_memberDef;
        SharedPtr<AuthenticationCallback> m_authCb;
    };
}

#endif
