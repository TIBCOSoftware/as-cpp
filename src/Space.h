/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _Space_h
#define _Space_h

#include <string>
#include "Exception.h"
#include "Tuple.h"
#include "SpaceDef.h"
#include "Browser.h"
#include "BrowserDef.h"
#include "Listener.h"
#include "ListenerDef.h"
#include "PutOptions.h"
#include "TakeOptions.h"
#include "GetOptions.h"
#include "LockOptions.h"
#include "UnlockOptions.h"
#include "SpaceResultList.h"
#include "InvokeOptions.h"
#include "InvokeResult.h"
#include "InvokeResultList.h"
#include "Persister.h"
#include "Router.h"

namespace ASApi
{
    class Metaspace;

    class AS_CPP_API Space
    {
    public:
        Space(SharedPtr<tibasSpace> space = SharedPtr<tibasSpace>(NULL));
        Space(tibasSpace& space);
        ~Space();

        std::string getName() const;

        bool isReady() const;

        bool waitForReady(long long timeout) const;

		SpaceState getState() const;

        // Return the value of the tuple.
        Tuple compareAndPut(const Tuple& oldValue, const Tuple& newValue);

        Tuple compareAndPut(const Tuple& oldValue, const Tuple& newValue, const PutOptions& putOptions);

        SpaceResultList compareAndPutAll(const std::vector<Tuple>& oldValue, const std::vector<Tuple>& newValue);

        SpaceResultList compareAndPutAll(const std::vector<Tuple>& oldValue, const std::vector<Tuple>& newValue, const PutOptions& putOptions);

        // Return the value that is taken. 
        Tuple compareAndTake(const Tuple& oldValue) const;

        Tuple compareAndTake(const Tuple& oldValue, const TakeOptions& takeOptions) const;

        SpaceResultList compareAndTakeAll(const std::vector<Tuple>& oldValueList);

        SpaceResultList compareAndTakeAll(const std::vector<Tuple>& oldValueList, const TakeOptions& takeOptions);

        // Return old value.
        Tuple put(const Tuple& newValue);
        
        Tuple put(const Tuple& newValue, const PutOptions& putOptions);

        SpaceResultList putAll(const std::vector<Tuple>& tuples);
        
        SpaceResultList putAll(const std::vector<Tuple>& tuples, const PutOptions& putOptions);

        // Return the tuple whose key fields match the key fields of the key provided(if the tuple exists).
        Tuple take(const Tuple& key) const;

        Tuple take(const Tuple& key, const TakeOptions& takeOptions) const;

        SpaceResultList takeAll(const std::vector<Tuple>& tuples) const;

        SpaceResultList takeAll(const std::vector<Tuple>& tuples, const TakeOptions& takeOptions) const;

        void load(const Tuple& newValue);

        SpaceResultList loadAll(const std::vector<Tuple>& valueList);

        // Return old value.
        Tuple update(const Tuple& keyTuple, const Tuple& tuple);
        
        Tuple update(const Tuple& keyTuple, const Tuple& tuple, const PutOptions& putOptions);
        
        void update(const std::string& filter);
        
        SpaceDef getSpaceDef() const;

        std::string getMetaspaceName() const;

        Metaspace getMetaspace() const;

        long long size(const std::string& filter) const;

        long long size() const;

		void clear(const std::string& filter) const;

        void clear() const;


        // Return either the tuple containing the locked tuple or NULL if no matching tuple can be found in the space.
        Tuple lock(const Tuple& key) const;

        Tuple lock(const Tuple& key, const LockOptions lockOptions);

        SpaceResultList lockAll(const std::vector<Tuple>& keyList) const;

        SpaceResultList lockAll(const std::vector<Tuple>& keyList, const LockOptions lockOptions) const;

        void unlock(const Tuple& key) const;

        void unlock(const Tuple& key, const UnlockOptions unlockOptions) const;

        SpaceResultList unlockAll(const std::vector<Tuple>& keyList) const;

        Browser browse(const BrowserType& browserType, const BrowserDef& browserDef, const std::string& filter) const;

        Tuple get(const Tuple& keyTuple) const;

        Tuple get(const Tuple& keyTuple, const GetOptions& getOptions) const;

        SpaceResultList getAll(const std::vector<Tuple>& keyList) const;

        SpaceResultList getAll(const std::vector<Tuple>& keyList, const GetOptions& getOptions) const;

        void listen(Listener& listener, const ListenerDef& listenerDef, const std::string& filter);
        
        Space& setDistributionRole(const DistributionRole& distributionRole);

        InvokeResult invoke(const Tuple& tuple, const std::string& invocable, const InvokeOptions& invokeOptions = InvokeOptions()) const;

        InvokeResult invokeMember(const Member& member, const std::string& invocable, const InvokeOptions& invokeOptions = InvokeOptions()) const;

        InvokeResultList invokeMembers(const std::vector<Member>& memberList, const std::string& invocable, const InvokeOptions& invokeOptions = InvokeOptions()) const;

        InvokeResultList invokeRemoteMembers(const std::string& invocable, const InvokeOptions& invokeOptions = InvokeOptions()) const;

        InvokeResultList invokeSeeders(const std::string& invocable, const InvokeOptions& invokeOptions = InvokeOptions()) const;

        void setPersister(Persister& persister);
        
        void setRouter(Router& router);
        
    private:
        tibasSpace& get();
        
        const tibasSpace& get() const;
        
        SharedPtr<tibasSpace> m_space;
        tibasSpace* m_rawSpace;
    };
}

#endif
