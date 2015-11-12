/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Invocable__
#define __Invocable__

#include <map>
#include "Space.h"
#include "Tuple.h"
#include "Mutex.h"
#include "tibas.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API Invocable
    {
    public:
        typedef SharedPtr<Invocable> (*Creator)();
        
        virtual void invoke(const Space& space, const Tuple& tuple, const Tuple& context, Tuple& result) = 0;
        
        static void set(const std::string& alias, Creator creator);
        
        static void set(const std::string& alias, SharedPtr<Invocable> object);
        
        static void remove(const std::string& alias);
        
        static void invokeByObject(tibasSpace space, tibasTuple tuple, tibasTuple context, tibasTuple c_result, const char* invocable);
        
        static void invokeByCreator(tibasSpace space, tibasTuple tuple, tibasTuple context, tibasTuple c_result, const char* invocable);

        static void populateAliases(std::vector<std::string>& aliases);
        
    private:
        static Mutex m_mutex;
        
        typedef std::map<std::string, SharedPtr<Invocable> > ObjectMap;
        static ObjectMap m_objects;
        
        typedef std::map<std::string, Creator> CreatorMap;
        static CreatorMap m_creators;
    };
}

#endif
