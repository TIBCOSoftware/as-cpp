/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __MemberInvocable__
#define __MemberInvocable__

#include <map>
#include "Tuple.h"
#include "Space.h"
#include "Mutex.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API MemberInvocable
    {
    public:
        typedef SharedPtr<MemberInvocable> (*Creator)();
        
        virtual void invoke(const Space& space, const Tuple& context, Tuple& result) = 0;
        
        static void set(const std::string& alias, Creator creator);
        
        static void set(const std::string& alias, SharedPtr<MemberInvocable> object);
        
        static void remove(const std::string& alias);
        
        static void invokeByObject(tibasSpace space, tibasTuple context, tibasTuple c_result, const char* invocable);
        
        static void invokeByCreator(tibasSpace space, tibasTuple context, tibasTuple c_result, const char* invocable);
        
        static void populateAliases(std::vector<std::string>& aliases);
        
    private:
        static Mutex m_mutex;
        
        typedef std::map<std::string, SharedPtr<MemberInvocable> > ObjectMap;
        static ObjectMap m_objects;
        
        typedef std::map<std::string, Creator> CreatorMap;
        static CreatorMap m_creators;
    };
}

#endif
