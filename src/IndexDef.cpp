/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "IndexDef.h"
#include "Exception.h"
#include "Utils.h"
#include <sstream>

using namespace ASApi;
using namespace std;

IndexDef::IndexDef()
: m_indexDef(new tibasIndexDef(), Deleter<tibasIndexDef>(tibasIndexDef_Free))
{
    //Create
}

IndexDef::IndexDef(string& indexName, string& fieldNames)
: m_indexDef(new tibasIndexDef(), Deleter<tibasIndexDef>(tibasIndexDef_Free))
{
    //Create
    char* indexName_c = const_cast<char*>(indexName.c_str());
    char* fieldNames_c = const_cast<char*>(fieldNames.c_str());
    AS_CALL(tibasIndexDef_Create(m_indexDef.get(), indexName_c, fieldNames_c));
}

IndexDef::~IndexDef()
{
    
}


const tibasIndexDef& IndexDef::get() const
{
    return *m_indexDef;
}


tibasIndexDef& IndexDef::get()
{
    return *m_indexDef;
}


IndexDef& IndexDef::setName(const string& indexName)
{
    char* indexName_c = const_cast<char*>(indexName.c_str());
    AS_CALL(tibasIndexDef_SetName(get(), indexName_c));
    return *this;
}


string IndexDef::getName() const
{
    const char* indexName = NULL;
    AS_CALL(tibasIndexDef_GetName(get(), &indexName));
    return indexName;
}


IndexDef& IndexDef::setIndexType(const IndexType& indexType)
{
    AS_CALL(tibasIndexDef_SetIndexType(get(), indexType));
    return *this;
}


IndexType IndexDef::getIndexType() const
{
    IndexType indexType;
    AS_CALL(tibasIndexDef_GetIndexType(get(),&indexType));
    return indexType; 
}


vector<string> IndexDef::getFieldNames() const
{
    tibasStringList fieldNames;
    AS_CALL(tibasIndexDef_GetFieldNames(get(), &fieldNames));
    return asStringListToVector(fieldNames);
}


IndexDef& IndexDef::setFieldNames(const string& fieldNames)
{
    char* fieldNames_c = const_cast<char*>(fieldNames.c_str());
    AS_CALL(tibasIndexDef_SetFieldNames(get(), fieldNames_c));
    return *this;
}


IndexDef& IndexDef::setFieldNames(int numFields, ...)
{
    ostringstream ostr;
    va_list vl;
    va_start(vl, numFields);
    for (int i = 0; i < numFields; ++i)
    {
        char* field;
        field = va_arg(vl, char*);
        ostr << field << ",";
    }
    va_end(vl);
    return setFieldNames(ostr.str());
}
