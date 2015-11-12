/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "MemberInvocable.h"

using namespace ASApi;
using namespace std;

Mutex MemberInvocable::m_mutex;

map<string, SharedPtr<MemberInvocable> > MemberInvocable::m_objects;

map<string, MemberInvocable::Creator> MemberInvocable::m_creators;

void MemberInvocable::set(const string& alias, Creator creator)
{
    LockGuard<Mutex> lock(m_mutex);
    m_creators.erase(alias);
    m_objects.erase(alias);
    m_creators.insert(make_pair(alias, creator));
    tibas_SetMemberInvocable(alias.c_str(), MemberInvocable::invokeByCreator);
}


void MemberInvocable::set(const string& alias, SharedPtr<MemberInvocable> object)
{
    LockGuard<Mutex> lock(m_mutex);
    m_creators.erase(alias);
    m_objects.erase(alias);
    m_objects.insert(make_pair(alias, object));
    tibas_SetMemberInvocable(alias.c_str(), MemberInvocable::invokeByObject);
}


void MemberInvocable::remove(const string& alias)
{
    LockGuard<Mutex> lock(m_mutex);
    m_creators.erase(alias);
    m_objects.erase(alias);
    AS_CALL(tibas_RemoveMemberInvocable(alias.c_str()));
}


void MemberInvocable::populateAliases(vector<string>& aliases)
{
    aliases.clear();
    LockGuard<Mutex> lock(m_mutex);

    for (ObjectMap::const_iterator iter = m_objects.begin(); iter != m_objects.end(); ++iter)
        aliases.push_back(iter->first);
    
    for (CreatorMap::const_iterator iter = m_creators.begin(); iter != m_creators.end(); ++iter)
        aliases.push_back(iter->first);
}


void MemberInvocable::invokeByObject(tibasSpace space, tibasTuple context, tibasTuple c_result, const char* invocable)
{
    SharedPtr<MemberInvocable> object;
    {
        LockGuard<Mutex> lock(m_mutex);
        ObjectMap::const_iterator iter = m_objects.find(invocable);
        if (iter != m_objects.end())
        {
            object = iter->second;
        }
    }
    
    if (object.get() != NULL)
    {
        Tuple result (c_result);
        object->invoke(Space(space), Tuple(context), result);
    }
}

void MemberInvocable::invokeByCreator(tibasSpace space, tibasTuple context, tibasTuple c_result, const char* invocable)
{
    Creator creator = NULL;
    {
        LockGuard<Mutex> lock(m_mutex);
        CreatorMap::const_iterator iter = m_creators.find(invocable);
        if (iter != m_creators.end())
        {
            creator = iter->second;
        }
    }
    
    if (creator != NULL)
    {
        SharedPtr<MemberInvocable> object = (*creator)();
        if (object.get() != NULL)
        {
            Tuple result (c_result);
            object->invoke(Space(space), Tuple(context), result);
        }
    }
}
