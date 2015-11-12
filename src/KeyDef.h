/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _KeyDef_h
#define _KeyDef_h

#include <string>
#include <vector>
#include <cstdarg>
#include "tibas.h"
#include "Types.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API KeyDef
    {
    public:
        KeyDef();
        KeyDef(const std::vector<std::string>& fieldNames);
        KeyDef(const std::string& fieldNames);
        ~KeyDef();
        
        static KeyDef create();

        const tibasKeyDef& get() const;
        
        tibasKeyDef& get();

        IndexType getIndexType() const;
        
        KeyDef& setIndexType(const IndexType& indexType);

        const std::vector<std::string> getFieldNames() const;
       
        KeyDef& setFieldNames(const std::vector<std::string>& fieldNames);

        KeyDef& setFieldNames(const std::string& fieldNames);

        KeyDef& setFieldNames(int numFields, ...);
        
    private:
        SharedPtr<tibasKeyDef> m_keyDef;

        std::string takeVectorFieldNamesToString(const std::vector<std::string>& strList) const;
    };
}

#endif
