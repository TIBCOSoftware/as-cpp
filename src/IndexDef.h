/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _IndexDef_h
#define _IndexDef_h

#include <string>
#include <vector>
#include <cstdarg>
#include "tibas.h"
#include "Exception.h"
#include "Types.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API IndexDef
    {
    public:
        IndexDef();

        IndexDef(const std::string& indexName, const std::string& fieldNames);

        ~IndexDef();

        const tibasIndexDef& get() const;

        tibasIndexDef& get();

        IndexDef& setName(const std::string& indexName);

        std::string getName() const;
        
        IndexDef& setIndexType(const IndexType& indexType);

        IndexType getIndexType() const;

        std::vector<std::string> getFieldNames() const;

        IndexDef& setFieldNames(const std::string& fieldNames);

        IndexDef& setFieldNames(int numFields, ...);
        
    private:
        SharedPtr<tibasIndexDef> m_indexDef;
    };
}

#endif

