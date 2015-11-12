/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Invocable.h"

using namespace ASApi;
using namespace std;

Mutex Invocable::m_mutex;

map<string, SharedPtr<Invocable> > Invocable::m_objects;

map<string, Invocable::Creator> Invocable::m_creators;

void Invocable::set(const string& alias, Creator creator)
{
    LockGuard<Mutex> lock(m_mutex);
    m_creators.erase(alias);
    m_objects.erase(alias);
    m_creators.insert(make_pair(alias, creator));
    tibas_SetInvocable(alias.c_str(), Invocable::invokeByCreator);
}


void Invocable::set(const string& alias, SharedPtr<Invocable> object)
{
    LockGuard<Mutex> lock(m_mutex);
    m_creators.erase(alias);
    m_objects.erase(alias);
    m_objects.insert(make_pair(alias, object));
    tibas_SetInvocable(alias.c_str(), Invocable::invokeByObject);
}


void Invocable::remove(const string& alias)
{
    LockGuard<Mutex> lock(m_mutex);
    m_creators.erase(alias);
    m_objects.erase(alias);
    AS_CALL(tibas_RemoveInvocable(alias.c_str()));
}


void Invocable::populateAliases(vector<string>& aliases)
{
    aliases.clear();
    LockGuard<Mutex> lock(m_mutex);
    
    for (ObjectMap::const_iterator iter = m_objects.begin(); iter != m_objects.end(); ++iter)
        aliases.push_back(iter->first);
    
    for (CreatorMap::const_iterator iter = m_creators.begin(); iter != m_creators.end(); ++iter)
        aliases.push_back(iter->first);
}


void Invocable::invokeByObject(tibasSpace space, tibasTuple keyTuple, tibasTuple context, tibasTuple c_result, const char* invocable)
{
    SharedPtr<Invocable> object;
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
        object->invoke(Space(space), Tuple(keyTuple), Tuple(context), result);
    }
}

void Invocable::invokeByCreator(tibasSpace space, tibasTuple keyTuple, tibasTuple context, tibasTuple c_result, const char* invocable)
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
        SharedPtr<Invocable> object = (*creator)();
        if (object.get() != NULL)
        {
            Tuple result (c_result);
            object->invoke(Space(space), Tuple(keyTuple), Tuple(context), result);
        }
    }
}
