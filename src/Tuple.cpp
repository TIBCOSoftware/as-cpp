/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Tuple.h"
#include "Utils.h"

using namespace std;
using namespace ASApi;

void deleter(tibasTuple* tuple)
{
    tibasTuple_Free(tuple);
    delete tuple;
}


Tuple::Tuple()
: m_tuple(new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free))
{
    AS_CALL(tibasTuple_Create(m_tuple.get()));
}


Tuple::Tuple(SharedPtr<tibasTuple>& tuple)
: m_tuple(tuple)
{
}


Tuple::Tuple(const tibasTuple& tuple)
: m_tuple(new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free))
{
    if(tuple != NULL)
    {
        AS_CALL(tibasTuple_Clone(m_tuple.get(), tuple));
    }
}


Tuple::~Tuple()
{
    
}


const tibasTuple& Tuple::get() const
{
    return *m_tuple;
}


tibasTuple& Tuple::get()
{
    return *m_tuple;
}


bool Tuple::getBoolean(const string& fieldName) const
{
    tibas_boolean boolean;
    AS_CALL(tibasTuple_GetBoolean(get(), &boolean, fieldName.c_str()));
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


char Tuple::getChar(const string& fieldName) const
{
    char value;
    AS_CALL(tibasTuple_GetChar(get(), &value, fieldName.c_str()));
    return value;
}


short Tuple::getShort(const string& fieldName) const
{
    short value;
    AS_CALL(tibasTuple_GetShort(get(), &value, fieldName.c_str()));
    return value;
}


int Tuple::getInt(const string& fieldName) const
{
    int value;
    AS_CALL(tibasTuple_GetInt(get(), &value, fieldName.c_str()));
    return value;
}


long long Tuple::getLong(const string& fieldName) const
{
    long long value;
    AS_CALL(tibasTuple_GetLong(get(), &value, fieldName.c_str()));
    return value;
}


float Tuple::getFloat(const string& fieldName) const
{
    float value;
    AS_CALL(tibasTuple_GetFloat(get(), &value, fieldName.c_str()));
    return value;
}


double Tuple::getDouble(const string& fieldName) const
{
    double value;
    AS_CALL(tibasTuple_GetDouble(get(), &value, fieldName.c_str()));
    return value;
}


string Tuple::getString(const string& fieldName) const
{
    const char* value = NULL;
    AS_CALL(tibasTuple_GetString(get(), &value, fieldName.c_str()));
    return value;
}

struct timeval Tuple::getDateTime(const string& fieldName) const
{
    tibasDateTime dateTime;
    AS_CALL(tibasTuple_GetDateTime(get(), &dateTime, fieldName.c_str()));
    struct timeval tv;
    tv.tv_sec = (long) dateTime.sec;
    tv.tv_usec = dateTime.nsec;
    
    return tv;
}

char* Tuple::getBlob(const string& fieldName, int& length) const
{
    char* value;
    AS_CALL(tibasTuple_GetBlob(get(), &value, &length, fieldName.c_str()));
    return value;
}


bool Tuple::isNull(const string& fieldName) const
{
    tibas_boolean boolean;
    boolean = tibasTuple_IsNull(get(), fieldName.c_str());
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Tuple::isNull() const
{
    return m_tuple.get() == NULL || get() == NULL;
}


Tuple& Tuple::putBoolean(const string& fieldName, bool value)
{
    AS_CALL(tibasTuple_PutBoolean(get(), fieldName.c_str(), (tibas_boolean)value));
    return *this;
}


Tuple& Tuple::putChar(const string& fieldName, char value)
{
    AS_CALL(tibasTuple_PutChar(get(), fieldName.c_str(), value));
    return *this;
}


Tuple& Tuple::putShort(const string& fieldName, short value)
{
    AS_CALL(tibasTuple_PutShort(get(), fieldName.c_str(), (tibas_short)value));
    return *this;
}


Tuple& Tuple::putInt(const string& fieldName, int value)
{
    AS_CALL(tibasTuple_PutInt(get(), fieldName.c_str(), (tibas_int)value));
    return *this;
}


Tuple& Tuple::putLong(const string& fieldName, long long value)
{
    AS_CALL(tibasTuple_PutLong(get(), fieldName.c_str(), (tibas_long)value));
    return *this;
}


Tuple& Tuple::putFloat(const string& fieldName, float value)
{
    AS_CALL(tibasTuple_PutFloat(get(), fieldName.c_str(), (tibas_float)value));
    return *this;
}


Tuple& Tuple::putDouble(const string& fieldName, double value)
{
    AS_CALL(tibasTuple_PutDouble(get(), fieldName.c_str(), (tibas_double)value));
    return *this;
}


Tuple& Tuple::putString(const string& fieldName, const string& value)
{
    char* value_c = const_cast<char*>(value.c_str());
    AS_CALL(tibasTuple_PutString(get(), fieldName.c_str(), value_c));
    return *this;
}


Tuple& Tuple::putDateTime(const string& fieldName, const struct timeval& dateTime)
{
    tibasDateTime dateTime_c;
    dateTime_c.sec = dateTime.tv_sec;
    dateTime_c.nsec = dateTime.tv_usec;
    
    AS_CALL(tibasTuple_PutDateTime(get(), fieldName.c_str(), dateTime_c));
    return *this;
}


void Tuple::remove(const string& fieldName) const
{
    AS_CALL(tibasTuple_Remove(get(), fieldName.c_str()));
}


int Tuple::size() const
{
    int s = 0;
    AS_CALL(tibasTuple_Size(get(), &s));
    return s;
}


void Tuple::clear()
{
    AS_CALL(tibasTuple_Clear(get()));
}


string Tuple::toString() const
{
    char *str = NULL;
    AS_CALL(tibasTuple_ToString(get(), &str));
    return str;
}


void Tuple::serialize(char** data, int* length) const
{
    AS_CALL(tibasTuple_Serialize(get(), data, (tibas_int*)length));
}


void Tuple::deserialize(char* data, int length) const
{
    AS_CALL(tibasTuple_Deserialize(m_tuple.get(), data, (tibas_int)length));
}


bool Tuple::exists(const string& fieldName) const
{
    tibas_boolean boolean;
    boolean = tibasTuple_Exists(get(), fieldName.c_str());
    if(boolean == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


vector<string> Tuple::getFieldNames() const
{
    tibasStringList fieldNameList;
    AS_CALL(tibasTuple_GetFieldNames(get(), &fieldNameList));
    return asStringListToVector(fieldNameList);
}


FieldDef::Type Tuple::getFieldType(const string& fieldName) const
{
    tibas_type fieldType;
    AS_CALL(tibasTuple_GetFieldType(get(), &fieldType, fieldName.c_str()));
    return fieldType;
}


Tuple& Tuple::putAll(const Tuple& otherTuple)
{
    AS_CALL(tibasTuple_PutAll(get(), otherTuple.get()));
    return *this;
}


bool Tuple::eval(const string& filter) const
{
    tibas_boolean result;
    char* f = const_cast<char*>(filter.c_str());
    AS_CALL(tibasTuple_Eval(get(), &result, f)); 
    if(result == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Tuple::operator== (const Tuple & tuple)
{
    return tibasTuple_Compare(get(), tuple.get()) == 0;
}


ostream& operator<< (ostream& os, const Tuple& tuple)
{
    if (!tuple.isNull() != NULL)
    {
        char* s = NULL;
        tibasTuple_ToString(tuple.get(), &s);
        os << s;
        tibas_FreeData(&s);
    }
    return os;
}


