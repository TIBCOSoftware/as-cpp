/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Space.h"
#include "Exception.h"
#include "Utils.h"
#include "Metaspace.h"

using namespace ASApi;
using namespace std;

Space::Space(SharedPtr<tibasSpace> space)
: m_space(space),
  m_rawSpace(m_space.get())
{
}


Space::Space(tibasSpace& space)
: m_rawSpace(&space)
{
}


Space::~Space()
{
}


tibasSpace& Space::get()
{
    return *m_rawSpace;
}


const tibasSpace& Space::get() const
{
    return *m_rawSpace;
}


string Space::getName() const
{
    const char* name = NULL;
    AS_CALL(tibasSpace_GetName(get(), &name));
    return name;
}

bool Space::isReady() const
{
    tibas_boolean is_ready;
    AS_CALL(tibasSpace_IsReady(get(), &is_ready));
    if(is_ready == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Space::waitForReady(long long timeout) const
{
    tibas_boolean is_ready;
    AS_CALL(tibasSpace_WaitForReady(get(), &is_ready, timeout));
    if(is_ready == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


SpaceState Space::getState() const
{
	SpaceState state;
	AS_CALL(tibasSpace_GetState(get(), &state));
	return state;
}


Tuple Space::compareAndPut(const Tuple& oldValue, const Tuple& newValue)
{
    SharedPtr<tibasTuple> value (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    tibas_status status = tibasSpace_CompareAndPut(get(), value.get(), oldValue.get(), newValue.get());
    switch (status)
    {
        case TIBAS_OK:
            return newValue;
            
        case TIBAS_MISMATCHED_TUPLE:
            return value;
            
        default:
            throw ASApi::Exception(status);
    }
}


Tuple Space::compareAndPut(const Tuple& oldValue, const Tuple& newValue, const PutOptions& putOptions)
{
    if (putOptions.get().closure != NULL)
        putOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasTuple> value (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    tibas_status status = tibasSpace_PutEx(get(), value.get(), newValue.get(), putOptions.get());
    switch (status)
    {
        case TIBAS_OK:
            return newValue;
            
        case TIBAS_MISMATCHED_TUPLE:
            return value;
            
        default:
            throw ASApi::Exception(status);
    }
}


SpaceResultList Space::compareAndPutAll(const vector<Tuple>& oldValue, const vector<Tuple>& newValue)
{
    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));

    SharedPtr<tibasTupleList> oldValueList = ASApi::tuplesToAsTupleList(oldValue);
    SharedPtr<tibasTupleList> newValueList = ASApi::tuplesToAsTupleList(newValue);
    AS_CALL(tibasSpace_CompareAndPutAll(get(), results.get(), *oldValueList, *newValueList));

    return SpaceResultList(results);
}


SpaceResultList Space::compareAndPutAll(const vector<Tuple>& oldValue, const vector<Tuple>& newValue, const PutOptions& putOptions)
{
    if (putOptions.get().closure != NULL)
        putOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));

    SharedPtr<tibasTupleList> oldValueList = ASApi::tuplesToAsTupleList(oldValue);
    SharedPtr<tibasTupleList> newValueList = ASApi::tuplesToAsTupleList(newValue);
    AS_CALL(tibasSpace_CompareAndPutAllEx(get(), results.get(), *oldValueList, *newValueList, putOptions.get()));
    return SpaceResultList(results);
}


Tuple Space::put(const Tuple& newValue)
{
    SharedPtr<tibasTuple> oldTuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_Put(get(), oldTuple.get(), newValue.get()));
    return Tuple(oldTuple);
}


Tuple Space::put(const Tuple& newValue, const PutOptions& putOptions)
{
    if (putOptions.get().closure != NULL)
        putOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;
    
    SharedPtr<tibasTuple> oldTuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_PutEx(get(), oldTuple.get(), newValue.get(), putOptions.get()));
    return Tuple(oldTuple);
}


SpaceResultList Space::putAll(const vector<Tuple>& tuples)
{
    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(tuples);
    AS_CALL(tibasSpace_PutAll(get(), results.get(), *tupleList));
    return SpaceResultList(results);
}


SpaceResultList Space::putAll(const vector<Tuple>& tuples, const PutOptions& putOptions)
{
    if (putOptions.get().closure != NULL)
        putOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(tuples);
    AS_CALL(tibasSpace_PutAllEx(get(), results.get(), *tupleList, putOptions.get()));
    return SpaceResultList(results);
}


Tuple Space::take(const Tuple& key) const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_Take(get(), tuple.get(), key.get()));
    return Tuple(tuple);
}


Tuple Space::take(const Tuple& key, const TakeOptions& takeOptions) const
{
    if (takeOptions.get().closure != NULL)
        takeOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_TakeEx(get(), tuple.get(), key.get(), takeOptions.get()));
    return Tuple(tuple);
}


SpaceResultList Space::takeAll(const vector<Tuple>& tuples) const
{
    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(tuples);
    AS_CALL(tibasSpace_TakeAll(get(), results.get(), *tupleList));
    return SpaceResultList(results);
}


SpaceResultList Space::takeAll(const vector<Tuple>& tuples, const TakeOptions& takeOptions) const
{
    if (takeOptions.get().closure != NULL)
        takeOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(tuples);
    AS_CALL(tibasSpace_TakeAllEx(get(), results.get(), *tupleList, takeOptions.get()));
    return SpaceResultList(results);
}


SpaceResultList Space::compareAndTakeAll(const vector<Tuple>& oldValueList)
{

    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));

    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(oldValueList);
    AS_CALL(tibasSpace_CompareAndTakeAll(get(), results.get(), *tupleList));

    return SpaceResultList(results);
}


SpaceResultList Space::compareAndTakeAll(const vector<Tuple>& oldValueList, const TakeOptions& takeOptions)
{

    if (takeOptions.get().closure != NULL)
        takeOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));

    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(oldValueList);
    AS_CALL(tibasSpace_CompareAndTakeAllEx(get(), results.get(), *tupleList, takeOptions.get()));
    return SpaceResultList(results);
}

Tuple Space::update(const Tuple& keyTuple, const Tuple& tuple)
{
    SharedPtr<tibasTuple> oldTuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_UpdateKey(get(), oldTuple.get(), keyTuple.get(), tuple.get()));
    return Tuple(oldTuple);
}

Tuple Space::update(const Tuple& keyTuple, const Tuple& tuple, const PutOptions& putOptions)
{
    if (putOptions.get().closure != NULL)
        putOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;
    
    SharedPtr<tibasTuple> oldTuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_UpdateKeyEx(get(), oldTuple.get(), keyTuple.get(), tuple.get(), putOptions.get()));
    return Tuple(oldTuple);
}

void Space::update(const string& filter)
{
    AS_CALL(tibasSpace_UpdateTuples(get(), filter.c_str()));
}

void Space::load(const Tuple& newValue)
{
    AS_CALL(tibasSpace_Load(get(), newValue.get()));
}


SpaceResultList Space::loadAll(const vector<Tuple>& valueList)
{
    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(valueList);
    AS_CALL(tibasSpace_LoadAll(get(), results.get(), *tupleList));
    return SpaceResultList(results);
}


Tuple Space::compareAndTake(const Tuple& oldValue) const
{
    SharedPtr<tibasTuple> value (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    tibas_status status = tibasSpace_CompareAndTake(get(), value.get(), oldValue.get());

    switch (status)
    {
        case TIBAS_OK:
            return oldValue;
            
        case TIBAS_MISMATCHED_TUPLE:
            return value;
            
        default:
            throw ASApi::Exception(status);
    }
}


Tuple Space::compareAndTake(const Tuple& oldValue, const TakeOptions& takeOptions) const
{
    if (takeOptions.get().closure != NULL)
        takeOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasTuple> value (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_CompareAndTakeEx(get(), value.get(), oldValue.get(), takeOptions.get()));
    return Tuple(value);
}


SpaceDef Space::getSpaceDef() const
{
    SpaceDef spaceDef;
    AS_CALL(tibasSpace_GetSpaceDef(get(), &spaceDef.get()));
    return spaceDef;
}


string Space::getMetaspaceName() const
{
    const char* name = NULL;
    AS_CALL(tibasSpace_GetMetaspaceName(get(), &name));
    return name;
}


Metaspace Space::getMetaspace() const
{
    SharedPtr<tibasMetaspace> metaspace (new tibasMetaspace, Deleter<tibasMetaspace>(tibasMetaspace_Free));
    AS_CALL(tibasSpace_GetMetaspace(get(), metaspace.get()));
    return Metaspace(metaspace);
}


long long Space::size(const string& filter) const
{
    tibas_long spaceSize = 0;
    AS_CALL(tibasSpace_Size(get(), &spaceSize, filter.c_str()));
    return (long long)spaceSize;
}


long long Space::size() const
{
    char* filter = NULL;
    tibas_long spaceSize = 0;
    AS_CALL(tibasSpace_Size(get(), &spaceSize, filter));
    return (long long)spaceSize;
}

void Space::clear(const string& filter) const
{
    AS_CALL(tibasSpace_Clear(get(), filter.c_str()));
}


void Space::clear() const
{
    char* filter = NULL;
    AS_CALL(tibasSpace_Clear(get(), filter));
}

Tuple Space::lock(const Tuple& key) const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_Lock(get(), tuple.get(), key.get()));
    return Tuple(tuple);
}


Tuple Space::lock(const Tuple& key, const LockOptions lockOptions)
{
    if (lockOptions.get().closure != NULL)
        lockOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_LockEx(get(), tuple.get(), key.get(), lockOptions.get()));
    return Tuple(tuple);
}


SpaceResultList Space::lockAll(const vector<Tuple>& keyList) const
{
    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(keyList);
    AS_CALL(tibasSpace_LockAll(get(), results.get(), *tupleList));
    return SpaceResultList(results);
}


SpaceResultList Space::lockAll(const vector<Tuple>& keyList, const LockOptions lockOptions) const
{

    if (lockOptions.get().closure != NULL)
        lockOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(keyList);
    AS_CALL(tibasSpace_LockAllEx(get(), results.get(), *tupleList, lockOptions.get()));
    return SpaceResultList(results);
}


void Space::unlock(const Tuple& key) const
{
    AS_CALL(tibasSpace_Unlock(get(), key.get())); 
}


void Space::unlock(const Tuple& key, const UnlockOptions unlockOptions) const
{
    if (unlockOptions.get().closure != NULL)
        unlockOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    AS_CALL(tibasSpace_UnlockEx(get(), key.get(), unlockOptions.get())); 
}

SpaceResultList Space::unlockAll(const vector<Tuple>& keyList) const
{
    SharedPtr<tibasSpaceResultList> results(new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(keyList);
    AS_CALL(tibasSpace_UnlockAll(get(), results.get(), *tupleList));
    return SpaceResultList(results);
}

Browser Space::browse(const BrowserType& browserType, const BrowserDef& browserDef, const string& filter) const
{
    Browser browser;
    AS_CALL(tibasSpace_Browse(get(), &browser.get(),browserType, browserDef.get(), filter.c_str()));
    return browser;
}


Tuple Space::get(const Tuple& keyTuple) const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_Get(get(), tuple.get(), keyTuple.get()));
    return Tuple(tuple);
}


Tuple Space::get(const Tuple& keyTuple, const GetOptions& getOptions) const
{
    if (getOptions.get().closure != NULL)
        getOptions.get().resultHandler = (void*)SpaceResultHandler::onCComplete;

    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasSpace_GetEx(get(), tuple.get(), keyTuple.get(), getOptions.get()));
    return Tuple(tuple);
}


SpaceResultList Space::getAll(const vector<Tuple>& keyList) const
{
    SharedPtr<tibasSpaceResultList> results (new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(keyList);
    AS_CALL(tibasSpace_GetAll(get(), results.get(), *tupleList));
    return SpaceResultList(results);
}

SpaceResultList Space::getAll(const vector<Tuple>& keyList, const GetOptions& getOptions) const
{
    SharedPtr<tibasSpaceResultList> results(new tibasSpaceResultList(), Deleter<tibasSpaceResultList>(tibasSpaceResultList_Free));
    SharedPtr<tibasTupleList> tupleList = ASApi::tuplesToAsTupleList(keyList);
    AS_CALL(tibasSpace_GetAllEx(get(), results.get(), *tupleList, getOptions.get()));
    return SpaceResultList(results);
}

void Space::listen(Listener& listener, const ListenerDef& listenerDef, const string& filter)
{
    listener.start();
    AS_CALL(tibasSpace_Listen(get(), listener.get(), listenerDef.get(), filter.c_str()));
}


Space& Space::setDistributionRole(const DistributionRole& distributionRole)
{
    AS_CALL(tibasSpace_SetDistributionRole(get(), distributionRole));
    return *this;
}


InvokeResult Space::invoke(const Tuple& tuple, const string& invocable, const InvokeOptions& invokeOptions) const
{
    SharedPtr<tibasInvokeResult> invokeResult (new tibasInvokeResult(), Deleter<tibasInvokeResult>(tibasInvokeResult_Free));
    invokeOptions.get().invocable = invocable.c_str();
    AS_CALL(tibasSpace_Invoke(get(), invokeResult.get(), tuple.get(), invokeOptions.get()));
    return InvokeResult(invokeResult);
}


InvokeResult Space::invokeMember(const Member& member, const string& invocable, const InvokeOptions& invokeOptions) const
{
    SharedPtr<tibasInvokeResult> invokeResult (new tibasInvokeResult(), Deleter<tibasInvokeResult>(tibasInvokeResult_Free));
    invokeOptions.get().invocable = invocable.c_str();
    AS_CALL(tibasSpace_InvokeMember(get(), invokeResult.get(), member.get(), invokeOptions.get()));
    return InvokeResult(invokeResult);
}


InvokeResultList Space::invokeMembers(const vector<Member>& memberList, const string& invocable, const InvokeOptions& invokeOptions) const
{
    SharedPtr<tibasInvokeResultList> invokeResultList(new tibasInvokeResultList(), Deleter<tibasInvokeResultList>(tibasInvokeResultList_Free));
    Metaspace metaspace = getMetaspace();
    SharedPtr<tibasMemberList> asMemberList = membersToAsMemberList(memberList, metaspace);
    invokeOptions.get().invocable = invocable.c_str();
    AS_CALL(tibasSpace_InvokeMembers(get(), invokeResultList.get(), *asMemberList, invokeOptions.get()));
    return InvokeResultList(invokeResultList);
}

InvokeResultList Space::invokeRemoteMembers(const string& invocable, const InvokeOptions& invokeOptions) const
{
    SharedPtr<tibasInvokeResultList> invokeResultList(new tibasInvokeResultList(), Deleter<tibasInvokeResultList>(tibasInvokeResultList_Free));
    invokeOptions.get().invocable = invocable.c_str();
    AS_CALL(tibasSpace_InvokeRemoteMembers(get(), invokeResultList.get(), invokeOptions.get()));
    return InvokeResultList(invokeResultList);
}


InvokeResultList Space::invokeSeeders(const string& invocable, const InvokeOptions& invokeOptions) const
{
    SharedPtr<tibasInvokeResultList> invokeResultList(new tibasInvokeResultList(), Deleter<tibasInvokeResultList>(tibasInvokeResultList_Free));
    invokeOptions.get().invocable = invocable.c_str();
    AS_CALL(tibasSpace_InvokeSeeders(get(), invokeResultList.get(), invokeOptions.get()));
    return InvokeResultList(invokeResultList);
}


void Space::setPersister(Persister& persister)
{
    persister.start();
    AS_CALL(tibasSpace_SetPersister(get(), persister.get()));
}


void Space::setRouter(Router& router)
{
    router.start();
    AS_CALL(tibasSpace_SetRouter(get(), router.get()));
}
