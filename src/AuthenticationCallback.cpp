/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "AuthenticationCallback.h"

using namespace ASApi;

tibas_status AuthenticationCallback::callback(tibasAuthenticationInfo authInfo, void *closure)
{
    AuthenticationCallback* authCb = (AuthenticationCallback*)(closure);
    AuthenticationInfo info(authInfo);
    return authCb == NULL ? TIBAS_NOT_FOUND : authCb->createUserCredential(info);
}
