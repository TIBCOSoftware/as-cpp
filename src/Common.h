/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _Common_h
#define _Common_h

#include <string>
#include <vector>
#include <map>
#include "tibas.h"
#include "Exception.h"
#include "Metaspace.h"
#include "Invocable.h"
#include "MemberInvocable.h"
#include "Mutex.h"
#include "SharedPtr.h"

namespace ASApi
{
    namespace Common
    {
        void AS_CPP_API setLogLevel(const LogLevel& logLevel);

        void AS_CPP_API setSecurityLogLevel(const LogLevel& logLevel);

        LogLevel AS_CPP_API getLogLevel();

        LogLevel AS_CPP_API getSecurityLogLevel();

        void AS_CPP_API setFileLogging(const LogLevel& logLevel);

        void AS_CPP_API setFileLogging(const std::string& fileName, const LogLevel& logLevel);

        void AS_CPP_API setFileLogging(const std::string& logDir, const std::string& fileName, const LogLevel& logLevel);

        void AS_CPP_API setEventLogging(const std::string& fileName, const LogLevel& logLevel);

        Metaspace AS_CPP_API getMetaspace(const std::string& metaspaceName);

        Metaspace AS_CPP_API connectMetaspace(const std::string& metaspaceName, const MemberDef& memberDef);

        std::vector<std::string> AS_CPP_API getMetaspaceNames();

        void AS_CPP_API setInvocable(const std::string& alias, Invocable::Creator creator);

        void AS_CPP_API setInvocable(const std::string& alias, SharedPtr<Invocable> invocable);
        
        void AS_CPP_API setMemberInvocable(const std::string& alias, MemberInvocable::Creator creator);
        
        void AS_CPP_API setMemberInvocable(const std::string& alias, SharedPtr<MemberInvocable> memberInvocable);

        std::vector<std::string> AS_CPP_API getInvocableAliases();

        std::vector<std::string> AS_CPP_API getMemberInvocableAliases();
        
        void AS_CPP_API removeInvocable(const std::string& alias);
        
        void AS_CPP_API removeMemberInvocable(const std::string& alias);
    }
}

#endif
