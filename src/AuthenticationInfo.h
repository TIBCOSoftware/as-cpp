/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __AuthenticationInfo__
#define __AuthenticationInfo__

#include "tibas.h"
#include <string>
#include <stdlib.h>
#include <string.h>
#include "Types.h"

namespace ASApi
{
    class AS_CPP_API AuthenticationInfo
    {
    public:
        typedef tibas_authenticationMethod Method;
        
        AuthenticationInfo(const tibasAuthenticationInfo& authInfo);
        
        std::string getMetaspaceName() const;
        
        std::string getHint() const;
        
        std::string getDomain() const;
        void setDomain(const std::string& domain);
        
        std::string getUserName() const;
        void setUserName(const std::string& userName);
        
        std::string getPassword() const;
        void setPassword(const std::string& password);
        
    private:
        const tibasAuthenticationInfo& m_authInfo;
    };
}

#endif
