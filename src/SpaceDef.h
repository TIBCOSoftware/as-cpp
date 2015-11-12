/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _SpaceDef_h
#define _SpaceDef_h

#include <string>
#include <vector>
#include "Tuple.h"
#include "FieldDefList.h"
#include "KeyDef.h"
#include "IndexDef.h"
#include "Exception.h"

namespace ASApi
{
    class AS_CPP_API SpaceDef
    {
    public:
        typedef tibas_distributionPolicy DistributionPolicy;
        typedef tibas_persistenceType    PersistenceType;
        typedef tibas_evictionPolicy     EvictionPolicy;
        typedef tibas_lockScope          LockScope;
        typedef tibas_updateTransport    UpdateTransport;
        typedef tibas_persistencePolicy  PersistencePolicy;

        SpaceDef();
        SpaceDef(SharedPtr<tibasSpaceDef>& spaceDef);
        SpaceDef(const tibasSpaceDef& spaceDef);
        ~SpaceDef();

        const tibasSpaceDef& get() const;

        tibasSpaceDef& get();

        SpaceDef& setName(const std::string& name);

        std::string getName() const;

        SpaceDef& putFieldDef(const FieldDef& fieldDef);

        FieldDef getFieldDef(const std::string& fieldName) const;

        FieldDefList getFieldDefs() const;

        void takeFieldDef(FieldDef fieldDef) const;

        SpaceDef& setKey(const std::string& fieldNames);

        SpaceDef& setKeyDef(const KeyDef& keyDef);

        KeyDef getKeyDef() const;

        SpaceDef& setDistributionPolicy(const DistributionPolicy& distributionPolicy);

        DistributionPolicy getDistributionPolicy() const;

        SpaceDef& setPersistenceType(const PersistenceType& persistenceType);

        PersistenceType getPersistenceType() const;

        SpaceDef& setMinSeederCount(int seederCount);

        int getMinSeederCount() const;

        SpaceDef& setReplicationCount(int replicationCount);

        int getReplicationCount() const;

        SpaceDef& setHostAwareReplication(bool flag);
        
        bool isHostAwareReplication() const;
        
        SpaceDef& setCapacity(long long  capacity);

        long long getCapacity() const;

        SpaceDef& setEvictionPolicy(EvictionPolicy evictionPolicy);

        EvictionPolicy getEvictionPolicy() const;

        LockScope  getLockScope() const;

        SpaceDef& setLockScope(const LockScope& lockScope);

        int getNumFields() const;

        std::vector<std::string> getIndex(const std::string& indexName) const;

        void removeIndexDef(const std::string& indexName) const;

        UpdateTransport getUpdateTransport() const;

        SpaceDef& setUpdateTransport(const UpdateTransport& updateTransport);
        
        SpaceDef& setDistributionFields(const std::string& fieldNames);

        std::vector<std::string> getDistributionFields() const;

        void addIndexDef(const IndexDef& indexDef);

        bool isSyncreplicated() const;

        SpaceDef& setSyncReplicated(bool syncReplicated);

        long long getSpaceWait() const;

        SpaceDef& setSpaceWait(long long spaceWait);

        long long getWriteTimeout() const;

        SpaceDef& setWriteTimeout(long long spaceWait);

        int getReadTimeout() const;

        SpaceDef& setReadTimeout(long long spaceWait);

        long long getTTL() const;

        SpaceDef& setTTL(long long ttl);

        long long getLockTTL() const;

        SpaceDef& setLockTTL(long long lockTTL);

        long long getLockWait() const;

        SpaceDef& setLockWait(long long lockWait);

        SpaceDef& setPersisted(bool persisted);

        bool isPersisted();

        PersistencePolicy getPersistencePolicy() const;

        SpaceDef& setPersistencePolicy(const PersistencePolicy& persistencePolicy);

    private:
        SharedPtr<tibasSpaceDef> m_spaceDef;
    };
}

#endif
