/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Metaspace__
#define __Metaspace__

#include <string>
#include <cstdarg>
#include <vector>
#include <sstream>
#include "Member.h"
#include "MemberDef.h"
#include "SpaceDef.h"
#include "Space.h"
#include "Browser.h"
#include "BrowserDef.h"
#include "EventBrowser.h"
#include "EventBrowserDef.h"
#include "Listener.h"
#include "MetaspaceMemberListener.h"
#include "MetaspaceRemoteMemberListener.h"
#include "SpaceMemberListener.h"
#include "SpaceRemoteMemberListener.h"
#include "SpaceStateListener.h"
#include "SpaceDefListener.h"
#include "RecoveryOptions.h"
#include "SharedPtr.h"

namespace ASApi
{
    class Space;

    class AS_CPP_API Metaspace
    {
    public:
        Metaspace();
        Metaspace(SharedPtr<tibasMetaspace>& metaspace);
        Metaspace(tibasMetaspace& metaspace);
        ~Metaspace();

        const tibasMetaspace& get() const;
        tibasMetaspace& get();

        //TODO: Throw exception on error
        //This is the entry point for creating the meteaspace. Ensures that the AS API functions are called only after a successful join
        static Metaspace connect(const std::string& msName, const MemberDef& memberDef);

        static Metaspace connect(const std::string& args);

        static Metaspace connect(int numArgs, ...); 

        void closeAll();
        
        std::vector<std::string> getMetaspaceNames() const;

        Space getSpace(const std::string& spaceName, const DistributionRole& distributionRole) const;

        Space getSystemSpace(const std::string& spaceName) const;

		SpaceState getSpaceState(const std::string& spaceName) const;

        std::vector<std::string> getUserSpaceNames() const;

        void defineSpace(const SpaceDef& spaceDef) const;

        void dropSpace(const std::string& spaceName) const; 
       
        void alterSpace(const SpaceDef& spaceDef) const;

        void recoverSpace(const std::string& spaceName) const; 

        void recoverSpace(const std::string& spaceName, const RecoveryOptions& recoveryOptions) const; 

        SpaceDef getSpaceDef( const std::string& spaceName) const;

        void listen(const std::string& spaceName, Listener& listener, const ListenerDef& listenerDef, const std::string& filter);

        void listenSpaceMemberEvents(const std::string& spaceName, SpaceMemberListener& listener);

        void listenMemberEvents(MetaspaceMemberListener& listener);

        void listenSpaceRemoteMemberEvents(const std::string& spaceName, SpaceRemoteMemberListener& listener);

        void listenRemoteMemberEvents(MetaspaceRemoteMemberListener& listener);

        void listenSpaceState(const std::string& spaceName, SpaceStateListener& listener);

        void listenSpaceDefs(SpaceDefListener& listener);
        
        std::string getRemoteListen() const;

        Browser browse(const std::string& spaceName,const BrowserType& browserType, const BrowserDef& browserDef, const std::string& filter) const;

        EventBrowser browseEvents(const std::string& spaceName, const EventBrowserDef& eventBrowserDef, const std::string& filter);

        void beginTransaction();

        void commitTransaction();

        void rollbackTransaction();

        std::vector<Member> getRemoteMembers() const;

        std::vector<Member> getMembers() const;

        std::vector<Member> getSpaceMembers(const std::string& spaceName) const;

        Member getSelfMember() const;

        std::string getDiscovery() const;

        std::string getListen() const;

        std::string getRemoteDiscovery() const;

        const MemberDef& getMemberDef() const;

        Metaspace& setMemberDef(const MemberDef& memberDef);

    private:
        void initialize();
        
        SharedPtr<tibasMetaspace> m_metaspace;
        SharedPtr<AuthenticationCallback> m_authCb;

        MemberDef m_memberDef;
    };
}

#endif /* defined(__C__API__Metaspace__) */
