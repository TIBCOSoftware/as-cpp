/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "FieldDef.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

FieldDef::FieldDef()
: m_fieldDef(new tibasFieldDef(), Deleter<tibasFieldDef>(tibasFieldDef_Free))
{
    
}

FieldDef::FieldDef(const string& fieldName, tibas_type fieldType)
: m_fieldDef(new tibasFieldDef(), Deleter<tibasFieldDef>(tibasFieldDef_Free))
{
    //emue as class var or golb var?
    AS_CALL(tibasFieldDef_Create(m_fieldDef.get(),const_cast<char*>(fieldName.c_str()), fieldType));
}


FieldDef::~FieldDef()
{
    
}


FieldDef FieldDef::create(const string& fieldName, tibas_type fieldType)
{
    FieldDef fieldDef(fieldName, fieldType);
    return fieldDef;
}


const tibasFieldDef& FieldDef::get() const
{
    return *m_fieldDef;
}


tibasFieldDef& FieldDef::get()
{
    return *m_fieldDef;
}


string FieldDef::getName() const
{
    const char* name = NULL;
    AS_CALL(tibasFieldDef_GetName(get(),&name));
    return name;
}

FieldDef::Type FieldDef::getType() const
{
    tibas_type* type = NULL;
    AS_CALL(tibasFieldDef_GetType(get(),type));
    return *type;
}

bool FieldDef::isNullable() const
{   
    if(tibasFieldDef_IsNullable(get()) == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}


 FieldDef& FieldDef::setNullable(bool nullable)
{
    tibas_boolean tmpBool = TIBAS_FALSE;

    if(nullable == true)
    {
        tmpBool= TIBAS_TRUE;
    }

    AS_CALL(tibasFieldDef_SetNullable(get(),tmpBool));
    return *this;
}


FieldDef& FieldDef::setEncrypted(bool secured)
{
    tibas_boolean tmpSecured = TIBAS_FALSE;
    if(secured == true)
    {
        tmpSecured = TIBAS_TRUE;
    }

    AS_CALL(tibasFieldDef_SetEncrypted(get(),tmpSecured));
    return *this;
}


bool FieldDef::isEncrypted()
{
    if(tibasFieldDef_IsEncrypted(get()) == TIBAS_TRUE)
    {
        return true;
    }
    else 
    {
        return false;
    }
}


