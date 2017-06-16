/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "SpaceResultList.h"

using namespace std;
using namespace ASApi;

SpaceResultList::SpaceResultList(const SharedPtr<tibasSpaceResultList>& spaceResultList)
: m_spaceResultList(spaceResultList)
{
    
}


SpaceResultList::~SpaceResultList()
{
    
}


bool SpaceResultList::hasError() const
{
    tibas_boolean boolean = tibasSpaceResultList_HasError(*m_spaceResultList);
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


Exception SpaceResultList::getError(int index) const
{
    tibasError error;
    AS_CALL(tibasSpaceResultList_GetError(*m_spaceResultList, &error, index));
    return Exception(error);
}


Status SpaceResultList::getStatus(int index) const
{
    Status retStatus = TIBAS_OK;
    AS_CALL(tibasSpaceResultList_GetStatus(*m_spaceResultList, &retStatus, index));
    return retStatus;
}


Tuple SpaceResultList::getTuple(int index) const
{
    tibasTuple tuple;
    AS_CALL(tibasSpaceResultList_GetTuple(*m_spaceResultList, &tuple, index));
    return Tuple(tuple);
}


int SpaceResultList::size() const
{
    int size;
    AS_CALL(tibasSpaceResultList_Size(*m_spaceResultList, &size));
    return size;
}


void SpaceResultList::getTuples(vector<Tuple>& tuples) const
{
    tibasTupleList tupleList;
    AS_CALL(tibasSpaceResultList_GetTuples(*m_spaceResultList, &tupleList));
    
    int size;
    AS_CALL(tibasTupleList_Size(tupleList, &size));
    
    tuples.clear();
    for (int i = 0; i < size; ++i)
    {
        tibasTuple tuple;
        AS_CALL(tibasTupleList_Get(tupleList, &tuple, i));
        tuples.push_back(Tuple(tuple));
    }
}
