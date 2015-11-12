/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __AuthenticationCallback__
#define __AuthenticationCallback__

#include "SharedPtr.h"
#include "tibas.h"
#include "AuthenticationInfo.h"
#include "Types.h"

namespace ASApi
{
    class AS_CPP_API AuthenticationCallback
    {
    public:
        struct AS_CPP_API CClosure
        {
            SharedPtr<AuthenticationCallback> m_callback;
        };
        
        static tibas_status callback(tibasAuthenticationInfo authInfo, void* closure);
        
        virtual Status createUserCredential(AuthenticationInfo& info) = 0;
    };
}
#endif
