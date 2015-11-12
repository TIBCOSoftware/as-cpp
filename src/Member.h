/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _Member_h
#define _Member_h

#include <string>
#include "tibas.h"
#include "Exception.h"
#include "Tuple.h"
#include "Types.h"
#include "SharedPtr.h"

namespace ASApi
{
    class Metaspace;
    
    class AS_CPP_API Member
    {
    public:
        Member(const Metaspace& metaspace, const std::string& memberId, const std::string& memberName);
        Member(SharedPtr<tibasMember>& member);
        ~Member();

        const tibasMember& get() const;

        tibasMember& get();

        std::string getName() const;
       
        ManagementRole getManagementRole() const;

        DistributionRole getDistributionRole(const std::string& spaceName) const;

        Tuple getContext() const;

        std::string getHostAddress() const;

        int getPort() const;

        time_t getJoinTime() const;

        std::string getId() const;

        std::vector<Member> getProxies() const;
        
    private:
        SharedPtr<tibasMember> m_member;
    };
}

#endif
