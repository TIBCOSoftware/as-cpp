/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SpaceDef.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

SpaceDef::SpaceDef()
: m_spaceDef(new tibasSpaceDef(), Deleter<tibasSpaceDef>(tibasSpaceDef_Free))
{
    AS_CALL(tibasSpaceDef_Create(m_spaceDef.get()));
}


SpaceDef::SpaceDef(SharedPtr<tibasSpaceDef>& spaceDef)
: m_spaceDef(spaceDef)
{
    
}


SpaceDef::SpaceDef(const tibasSpaceDef& spaceDef)
: m_spaceDef(new tibasSpaceDef(), Deleter<tibasSpaceDef>(tibasSpaceDef_Free))
{
    AS_CALL(tibasSpaceDef_Create(m_spaceDef.get()));
    (*m_spaceDef)->m_ctx = spaceDef->m_ctx;
    (*m_spaceDef)->m_ctx2 = spaceDef->m_ctx2;
    (*m_spaceDef)->m_ctx3 = spaceDef->m_ctx3;
    (*m_spaceDef)->m_ctx4 = spaceDef->m_ctx4;
    (*m_spaceDef)->m_ctx5 = spaceDef->m_ctx5;
    (*m_spaceDef)->m_type = spaceDef->m_type;
}


SpaceDef::~SpaceDef()
{
    
}


const tibasSpaceDef& SpaceDef::get() const
{
    return *m_spaceDef;
}


tibasSpaceDef& SpaceDef::get()
{
    return *m_spaceDef;
}


SpaceDef& SpaceDef::setName(const string& name)
{
    AS_CALL(tibasSpaceDef_SetName(get(), name.c_str()));
    return *this;
}


string SpaceDef::getName() const
{
    const char* name = NULL;
    AS_CALL(tibasSpaceDef_GetName(get(), &name));
    return name;
}


SpaceDef& SpaceDef::putFieldDef(const FieldDef& fieldDef)
{
    AS_CALL(tibasSpaceDef_PutFieldDef(get(), fieldDef.get()));
    return *this;
}


FieldDef SpaceDef::getFieldDef(const string& fieldName) const
{
    FieldDef field;
    AS_CALL(tibasSpaceDef_GetFieldDef(get(), &field.get(), fieldName.c_str()));
    return field;
}


FieldDefList SpaceDef::getFieldDefs() const
{
    FieldDefList fieldList;
    AS_CALL(tibasSpaceDef_GetFieldDefs(get(), &fieldList.get()));
    return fieldList;
}


void SpaceDef::takeFieldDef(FieldDef fieldDef) const
{
    AS_CALL(tibasSpaceDef_TakeFieldDef(get(), fieldDef.get()));
}


SpaceDef& SpaceDef::setKey(const string& fieldNames)
{
    AS_CALL(tibasSpaceDef_SetKey(get(), fieldNames.c_str()));
    return *this;
}


SpaceDef& SpaceDef::setKeyDef(const KeyDef& keyDef)
{
    AS_CALL(tibasSpaceDef_SetKeyDef(get(), keyDef.get()));
    return *this;
}


KeyDef SpaceDef::getKeyDef() const
{
    KeyDef keyDef;
    AS_CALL(tibasSpaceDef_GetKeyDef(get(), &keyDef.get()));
    return keyDef;
}


SpaceDef& SpaceDef::setDistributionPolicy(const DistributionPolicy& distributionPolicy)
{
    AS_CALL(tibasSpaceDef_SetDistributionPolicy(get(), distributionPolicy));
    return *this;
}


SpaceDef::DistributionPolicy SpaceDef::getDistributionPolicy() const
{
    tibas_distributionPolicy distributionPolicy;
    AS_CALL(tibasSpaceDef_GetDistributionPolicy(get(), &distributionPolicy));
    return distributionPolicy;
}


SpaceDef& SpaceDef::setPersistenceType(const PersistenceType & persistenceType)
{
    AS_CALL(tibasSpaceDef_SetPersistenceType(get(), persistenceType));
    return *this;
}


SpaceDef::PersistenceType SpaceDef::getPersistenceType() const
{
    tibas_persistenceType persistenceType;
    AS_CALL(tibasSpaceDef_GetPersistenceType(get(), &persistenceType));
    return persistenceType;
}


SpaceDef& SpaceDef::setMinSeederCount(int minSeederCount)
{
    AS_CALL(tibasSpaceDef_SetMinSeederCount(get(), minSeederCount));
    return *this;
}


int SpaceDef::getMinSeederCount() const
{
    int minSeederCount = 0;
    AS_CALL(tibasSpaceDef_GetMinSeederCount(get(), &minSeederCount));
    return minSeederCount;
}


SpaceDef& SpaceDef::setReplicationCount(int replicationCount)
{
    AS_CALL(tibasSpaceDef_SetReplicationCount(get(), replicationCount));
    return *this;
}

int SpaceDef::getReplicationCount() const
{
    int replicationCount = 0;
    AS_CALL(tibasSpaceDef_GetReplicationCount(get(), &replicationCount));

    return replicationCount;
}

SpaceDef& SpaceDef::setHostAwareReplication(bool flag)
{
    AS_CALL(tibasSpaceDef_SetHostAwareReplication(get(), flag ? TIBAS_TRUE : TIBAS_FALSE));
    return *this;
}


bool SpaceDef::isHostAwareReplication() const
{
    tibas_boolean boolean = tibasSpaceDef_IsHostAwareReplication(get());
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


SpaceDef& SpaceDef::setCapacity(long long capacity)
{
    AS_CALL(tibasSpaceDef_SetCapacity(get(), capacity));
    return *this;
}


long long SpaceDef::getCapacity() const
{
    long long capacity = 0;
    AS_CALL(tibasSpaceDef_GetCapacity(get(), &capacity));

    return capacity;
}


SpaceDef& SpaceDef::setEvictionPolicy(tibas_evictionPolicy evictionPolicy)
{
    AS_CALL(tibasSpaceDef_SetEvictionPolicy(get(), evictionPolicy));
    return *this;
}


SpaceDef::EvictionPolicy SpaceDef::getEvictionPolicy() const
{
    tibas_evictionPolicy evictionPolicy;
    AS_CALL(tibasSpaceDef_GetEvictionPolicy(get(), &evictionPolicy));
    return evictionPolicy;
}


SpaceDef::LockScope  SpaceDef::getLockScope() const
{
    LockScope lockScope;
    AS_CALL(tibasSpaceDef_GetLockScope(get(), &lockScope));
    return lockScope;
}


SpaceDef& SpaceDef::setLockScope(const LockScope& lockScope)
{
    AS_CALL(tibasSpaceDef_SetLockScope(get(),lockScope));
    return *this;
}


int SpaceDef::getNumFields() const
{
    int numFields = 0;
    AS_CALL(tibasSpaceDef_GetNumFields(get(), &numFields));
    return numFields; 
}


vector<string> SpaceDef::getIndex(const string& indexName) const
{
    vector<string> fieldNames;
    //AS_CALL(tibasSpaceDef_GetInde);
    return fieldNames; 
}


void SpaceDef::removeIndexDef(const string& indexName) const
{
    char* indexName_c = const_cast<char*>(indexName.c_str());
    AS_CALL(tibasSpaceDef_RemoveIndexDef(get(), indexName_c));
    
}


SpaceDef::UpdateTransport SpaceDef::getUpdateTransport() const
{
    UpdateTransport updateTransport;
    AS_CALL(tibasSpaceDef_GetUpdateTransport(get(), &updateTransport));
    return updateTransport; 
}


SpaceDef& SpaceDef::setUpdateTransport(const UpdateTransport& updateTransport)
{
    AS_CALL(tibasSpaceDef_SetUpdateTransport(get(), updateTransport));
    return *this;
}


SpaceDef& SpaceDef::setDistributionFields(const string& fieldNames)
{
    AS_CALL(tibasSpaceDef_SetDistributionFields(get(), fieldNames.c_str()));
    return *this;
}


vector<string> SpaceDef::getDistributionFields() const
{
    tibasStringList fieldNames;
    AS_CALL(tibasSpaceDef_GetDistributionFields(get(), &fieldNames));
    return asStringListToVector(fieldNames); 
}


void SpaceDef::addIndexDef(const IndexDef& indexDef)
{
    AS_CALL(tibasSpaceDef_AddIndexDef(get(), indexDef.get()));
}


bool SpaceDef::isSyncreplicated() const
{
    tibas_boolean boolean = tibasSpaceDef_IsSyncReplicated(get());
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


SpaceDef& SpaceDef::setSyncReplicated(bool syncReplicated)
{
    AS_CALL(tibasSpaceDef_SetSyncReplicated(get(), syncReplicated ? TIBAS_TRUE : TIBAS_FALSE));
    return *this;
}


long long SpaceDef::getSpaceWait() const
{
    long long spaceWait = 0;
    AS_CALL(tibasSpaceDef_GetSpaceWait(get(), &spaceWait));
    return spaceWait; 
}


SpaceDef& SpaceDef::setSpaceWait(long long spaceWait)
{
    AS_CALL(tibasSpaceDef_SetSpaceWait(get(), spaceWait));
    return *this;
}


long long SpaceDef::getWriteTimeout() const
{
    long long writeTimeout = 0;
    AS_CALL(tibasSpaceDef_GetWriteTimeout(get(), &writeTimeout));
    return writeTimeout;
}


SpaceDef& SpaceDef::setWriteTimeout(long long spaceWait)
{
    AS_CALL(tibasSpaceDef_SetWriteTimeout(get(), spaceWait));
    return *this;
}


int SpaceDef::getReadTimeout() const
{
    int readTimeout = 0;
    AS_CALL(tibasSpaceDef_GetReplicationCount(get(), &readTimeout));
    return readTimeout; 
}


SpaceDef& SpaceDef::setReadTimeout(long long spaceWait)
{
    AS_CALL(tibasSpaceDef_SetReadTimeout(get(), spaceWait));
    return *this;
}


long long SpaceDef::getTTL() const
{
    long long ttl = 0;
    AS_CALL(tibasSpaceDef_GetTTL(get(), &ttl));
    return ttl; 
}


SpaceDef& SpaceDef::setTTL(long long ttl)
{
    AS_CALL(tibasSpaceDef_SetTTL(get(), ttl));
    return *this;
}


long long SpaceDef::getLockTTL() const
{
    long long lockTTL = 0;
    AS_CALL(tibasSpaceDef_GetLockTTL(get(), &lockTTL));
    return lockTTL; 
}


SpaceDef& SpaceDef::setLockTTL(long long lockTTL)
{
    AS_CALL(tibasSpaceDef_SetLockTTL(get(), lockTTL));
    return *this;
}


long long SpaceDef::getLockWait() const
{
    long long lockWait = 0;
    AS_CALL(tibasSpaceDef_GetLockWait(get(), &lockWait));
    return lockWait;
}


SpaceDef& SpaceDef::setLockWait(long long lockWait)
{
    AS_CALL(tibasSpaceDef_SetLockWait(get(), lockWait));
    return *this;
}


SpaceDef& SpaceDef::setPersisted(bool persisted)
{
    tibas_boolean persisted_c = (tibas_boolean)persisted;
    AS_CALL(tibasSpaceDef_SetPersisted(get(), persisted_c));
    return *this;
}


bool SpaceDef::isPersisted()
{
    tibas_boolean boolean = tibasSpaceDef_IsPersisted(get());
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


SpaceDef::PersistencePolicy SpaceDef::getPersistencePolicy() const
{
    PersistencePolicy persistencePolicy;
    AS_CALL(tibasSpaceDef_GetPersistencePolicy(get(), &persistencePolicy));
    return persistencePolicy; 
}


SpaceDef& SpaceDef::setPersistencePolicy(const PersistencePolicy& persistencePolicy)
{
    AS_CALL(tibasSpaceDef_SetPersistencePolicy(get(), persistencePolicy));
    return *this;
}

