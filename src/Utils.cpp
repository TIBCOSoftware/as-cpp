/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Utils.h"
#include "Exception.h"
#include "Metaspace.h"

using namespace ASApi;
using namespace std;

tibasStringList
ASApi::vectorToStringList(const vector<string>& strings)
{
    tibasStringList stringList;
    tibasStringList_Create(&stringList);
    for (vector<string>::const_iterator iter = strings.begin(); iter != strings.end(); ++iter)
    {
        tibasStringList_Put(stringList, iter->c_str());
    }
    return stringList;
}

vector<string> ASApi::asStringListToVector (const tibasStringList& stringList)
{
    int size;
    AS_CALL(tibasStringList_Size(stringList, &size));
    
    vector<string> strings;
    for (int i = 0; i < size; ++i)
    {
        const char* value;
        AS_CALL(tibasStringList_Get(stringList, &value, i));
        strings.push_back(value);
    }
    return strings;
}


SharedPtr<tibasTupleList> ASApi::tuplesToAsTupleList(const vector<Tuple>& tuples)
{
    tibasTupleList tupleList;

    AS_CALL(tibasTupleList_Create(&tupleList));

    for (vector<Tuple>::const_iterator iter = tuples.begin(); iter != tuples.end(); ++iter)
    {
        AS_CALL(tibasTupleList_Put(tupleList, iter->get()));
    }

    SharedPtr<tibasTupleList> asTuples(&tupleList, tibasTupleList_Free);
    return asTuples;
}


SharedPtr<tibasMemberList> ASApi::membersToAsMemberList(const vector<Member>& members, const Metaspace& metaspace)
{
    tibasStringList memberIdList;
    AS_CALL(tibasStringList_Create(&memberIdList));
    for (vector<Member>::const_iterator iter = members.begin(); iter != members.end(); ++iter)
    {
        const char* memberId;
        AS_CALL(tibasMember_GetId(iter->get(), &memberId));
        AS_CALL(tibasStringList_Put(memberIdList, memberId));
    }
    
    SharedPtr<tibasMemberList> asMembers(new tibasMemberList(), Deleter<tibasMemberList>(tibasMemberList_Free));
    AS_CALL(tibasMemberList_Create(asMembers.get(), metaspace.get(), memberIdList));
    return asMembers;
}


vector<Member> ASApi::asMemberListToVector(tibasMemberList& memberList)
{
    vector<Member> members;
    int size = 0;
    AS_CALL(tibasMemberList_Size(memberList, &size));
    for (int i = 0; i < size; ++i)
    {
        SharedPtr<tibasMember> member (new tibasMember(), Deleter<tibasMember>(tibasMember_Free));
        AS_CALL(tibasMemberList_Get(memberList, member.get(), i));
        members.push_back(Member(member));
    }
    tibasMemberList_Free(&memberList);
    return members;
}
