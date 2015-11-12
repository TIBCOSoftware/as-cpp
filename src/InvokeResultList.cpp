/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "InvokeResultList.h"
#include "Utils.h"

using namespace std;
using namespace ASApi;

InvokeResultList::InvokeResultList(const SharedPtr<tibasInvokeResultList>& invokeResultList)
: m_invokeResultList(invokeResultList)
{
    
}


InvokeResultList::~InvokeResultList()
{
    
}


bool InvokeResultList::hasError() const
{
    tibas_boolean boolean = tibasInvokeResultList_HasError(*m_invokeResultList);
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


Exception InvokeResultList::getError(int index) const
{
    tibasError error;
    AS_CALL(tibasInvokeResultList_GetError(*m_invokeResultList, &error, index));
    return Exception(error);
}


Status InvokeResultList::getStatus(int index) const
{
    Status status = TIBAS_OK;
    AS_CALL(tibasInvokeResultList_GetStatus(*m_invokeResultList, &status, index));
    return status;
}


Tuple InvokeResultList::getReturn(int index) const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasInvokeResultList_GetReturn(*m_invokeResultList, tuple.get(), index));
    return Tuple(tuple);
}


int InvokeResultList::size() const
{
    int size;
    AS_CALL(tibasInvokeResultList_Size(*m_invokeResultList, &size));
    return size;
}


void InvokeResultList::getReturns(vector<Tuple>& tuples) const
{
    tibasTupleList tupleList;
    AS_CALL(tibasInvokeResultList_GetReturns(*m_invokeResultList, &tupleList));
    
    int size;
    AS_CALL(tibasTupleList_Size(tupleList, &size));
    
    tuples.clear();
    for (int i = 0; i < size; ++i)
    {
        SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
        AS_CALL(tibasTupleList_Get(tupleList, tuple.get(), i));
        tuples.push_back(Tuple(tuple));
    }
}


InvokeResult InvokeResultList::get(int index) const
{
    SharedPtr<tibasInvokeResult> result (new tibasInvokeResult(), Deleter<tibasInvokeResult>(tibasInvokeResult_Free));
    AS_CALL(tibasInvokeResultList_Get(*m_invokeResultList, result.get() ,index));
    return InvokeResult(result);
}


void InvokeResultList::put(const InvokeResult& result) const
{
    AS_CALL(tibasInvokeResultList_Put(*m_invokeResultList, result.get()));
}





