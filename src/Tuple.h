/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Tuple__
#define __Tuple__

#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include "tibas.h"
#include "Exception.h"
#include "FieldDef.h"
#include "SharedPtr.h"

#ifdef _WINDOWS
#include <windows.h>
#else
#include <time.h>
#endif

namespace ASApi
{
    class AS_CPP_API Tuple
    {
    public:
        Tuple();
        Tuple(SharedPtr<tibasTuple>& tuple);
        Tuple(const tibasTuple& tuple);
        ~Tuple();

        tibasTuple& get();

        const tibasTuple& get() const;
        
        bool getBoolean(const std::string& fieldName) const;

        char getChar(const std::string& fieldName) const;

        short getShort(const std::string& fieldName) const;

        int getInt(const std::string& fieldName) const;

        long long getLong(const std::string& fieldName) const;

        float getFloat(const std::string& fieldName) const;
        
        double getDouble(const std::string& fieldName) const;

        std::string getString(const std::string& fieldName) const;
        
        struct timeval getDateTime(const std::string& fieldName) const;

        char* getBlob(const std::string& fieldName, int& length) const;   

        bool isNull(const std::string& fieldName) const;

        bool isNull() const;
        
        Tuple& putBoolean(const std::string& fieldName, bool value);

        Tuple& putChar(const std::string& fieldName, char value);

        Tuple& putShort(const std::string& fieldName, short value);
        
        Tuple& putInt(const std::string& fieldName, int value);

        Tuple& putLong(const std::string& fieldName, long long value);

        Tuple& putFloat(const std::string& fieldName, float value);

        Tuple& putDouble(const std::string& fieldName, double value);

        Tuple& putString(const std::string& fieldName, const std::string& value);
       
        Tuple& putDateTime(const std::string& fieldName, const struct timeval& dateTime);

        void remove(const std::string& fieldName) const;
        
        int size() const;

        void clear();

        std::string toString() const;

        void serialize(char** data, int* length) const;

        void deserialize(char* data, int length) const;

        bool exists(const std::string& fieldName) const;
        
        std::vector<std::string> getFieldNames() const;

        FieldDef::Type getFieldType(const std::string& fieldName) const;

        Tuple& putAll(const Tuple& otherTuple);

        bool eval(const std::string& filter) const;

        bool operator== (const Tuple& tuple);
        
    private:
        SharedPtr<tibasTuple> m_tuple;
    };
    
}

AS_CPP_API std::ostream& operator<< (std::ostream& os, const ASApi::Tuple& tuple);

#endif
