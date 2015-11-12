/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include <sstream>
#include "KeyDef.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

KeyDef::KeyDef()
: m_keyDef(new tibasKeyDef(), Deleter<tibasKeyDef>(tibasKeyDef_Free))
{
    AS_CALL(tibasKeyDef_Create(m_keyDef.get(), ""));
}


KeyDef::KeyDef(const vector<string>& fieldNames)
: m_keyDef(new tibasKeyDef(), Deleter<tibasKeyDef>(tibasKeyDef_Free))
{
    const string str = takeVectorFieldNamesToString(fieldNames);

    char* name = const_cast<char*>(str.c_str());
    AS_CALL(tibasKeyDef_Create(m_keyDef.get(), name));
}


KeyDef::KeyDef(const string& fieldNames)
: m_keyDef(new tibasKeyDef(), Deleter<tibasKeyDef>(tibasKeyDef_Free))
{
    char* name = const_cast<char*>(fieldNames.c_str());
    AS_CALL(tibasKeyDef_Create(m_keyDef.get(), name));
}


KeyDef::~KeyDef()
{
    
}


KeyDef KeyDef::create()
{
    KeyDef keyDef;
    return keyDef; 
}


const tibasKeyDef& KeyDef::get() const
{
    return *m_keyDef;
}


tibasKeyDef& KeyDef::get()
{
    return *m_keyDef;
}


KeyDef& KeyDef::setIndexType(const IndexType& indexType)
{
    AS_CALL(tibasKeyDef_SetIndexType(get(), indexType));
    return *this;
}

IndexType KeyDef::getIndexType() const
{
    tibas_indexType indexType;
    AS_CALL(tibasKeyDef_GetIndexType(get(), &indexType));
    return indexType;
}


KeyDef& KeyDef::setFieldNames(const vector<string>& fieldNames)
{
    const string str = takeVectorFieldNamesToString(fieldNames);
    return setFieldNames(str);
}


KeyDef& KeyDef::setFieldNames(int numFields, ...)
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


KeyDef& KeyDef::setFieldNames(const string& fieldNames)
{
    AS_CALL(tibasKeyDef_SetFieldNames(get(), (char*) fieldNames.c_str()));
    return *this;
}


const vector<string> KeyDef::getFieldNames() const
{
    tibasStringList asFields;
    AS_CALL(tibasKeyDef_GetFieldNames(get(), &asFields));
    
    return asStringListToVector(asFields);
}


string KeyDef::takeVectorFieldNamesToString(const vector<string>& strList) const
{
    ostringstream ostr;
    for (vector<string>::const_iterator iter = strList.begin(); iter != strList.end(); ++iter)
    {
        ostr << *iter << ",";
    }
    return ostr.str();
}
