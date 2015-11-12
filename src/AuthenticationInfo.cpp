/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "AuthenticationInfo.h"
#include <string.h>

using namespace ASApi;
using namespace std;

#ifdef _WINDOWS
	#define strcpy strcpy_s
#endif

AuthenticationInfo::AuthenticationInfo(const tibasAuthenticationInfo& info)
: m_authInfo(info)
{
    
}


string AuthenticationInfo::getMetaspaceName() const
{
    return m_authInfo.metaspaceName;
}


string AuthenticationInfo::getHint() const
{
    return m_authInfo.authHint;
}


string AuthenticationInfo::getDomain() const
{
    return m_authInfo.credential->domain;
}


void AuthenticationInfo::setDomain(const string& domain)
{
	strcpy(m_authInfo.credential->domain, domain.c_str());
}


string AuthenticationInfo::getUserName() const
{
    return m_authInfo.credential->username;
}


void AuthenticationInfo::setUserName(const string& userName)
{
    strcpy(m_authInfo.credential->username, userName.c_str());
}


string AuthenticationInfo::getPassword() const
{
    return m_authInfo.credential->password;
}


void AuthenticationInfo::setPassword(const string& password)
{
    strcpy(m_authInfo.credential->password, password.c_str());
}

