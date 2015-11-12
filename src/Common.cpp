/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Common.h"
#include "Exception.h"
#include "Utils.h"
#include "Types.h"

using namespace ASApi;
using namespace std;

void Common::setLogLevel(const LogLevel& logLevel)
{
    AS_CALL(tibas_SetLogLevel(logLevel));
}


void Common::setSecurityLogLevel(const LogLevel& logLevel)
{
    AS_CALL(tibas_SetSecurityLogLevel(logLevel));
}


LogLevel Common::getLogLevel()
{
    tibas_logLevel logLevel;
    AS_CALL(tibas_GetLogLevel(&logLevel));
    return logLevel;
}


LogLevel Common::getSecurityLogLevel()
{
    tibas_logLevel logLevel;
    AS_CALL(tibas_GetSecurityLogLevel(&logLevel));
    return logLevel;
}


void Common::setFileLogging(const LogLevel& logLevel)
{

}


void Common::setEventLogging(const string& fileName, const LogLevel& logLevel)
{

}



Metaspace Common::getMetaspace(const string& metaspaceName)
{
    Metaspace metaspace;
    AS_CALL(tibas_GetMetaspace(&metaspace.get(), metaspaceName.c_str()));
    return metaspace;
}


Metaspace Common::connectMetaspace(const string& metaspaceName, const MemberDef& memberDef)
{
    return Metaspace::connect(metaspaceName, memberDef);
}


vector<string> Common::getMetaspaceNames()
{
    tibasStringList metaspaceName;
    tibas_GetMetaspaceNames(&metaspaceName);
    return asStringListToVector(metaspaceName);
}


void Common::setInvocable(const string& alias, Invocable::Creator creator)
{
    Invocable::set(alias, creator);
}


void Common::setInvocable(const string& alias, SharedPtr<Invocable> object)
{
    Invocable::set(alias, object);
}


void Common::setMemberInvocable(const string& alias, MemberInvocable::Creator creator)
{
    MemberInvocable::set(alias, creator);
}


void Common::setMemberInvocable(const string& alias, SharedPtr<MemberInvocable> object)
{
    MemberInvocable::set(alias, object);
}


vector<string> Common::getInvocableAliases()
{
    vector<string> aliases;
    Invocable::populateAliases(aliases);
    return aliases;
}


vector<string> Common::getMemberInvocableAliases()
{
    vector<string> aliases;
    MemberInvocable::populateAliases(aliases);
    return aliases;
}


void Common::removeInvocable(const string& alias)
{
    Invocable::remove(alias);
}


void Common::removeMemberInvocable(const string& alias)
{
    MemberInvocable::remove(alias);
}
