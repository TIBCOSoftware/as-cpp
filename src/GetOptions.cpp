/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include <cstdarg>
#include "GetOptions.h"
#include "options.h"
#include "Exception.h"
#include "Utils.h"

using namespace std;
using namespace ASApi;


GetOptions::GetOptions()
: SpaceOptions<ASApi::GetOptions, tibasGetOptions>(tibasGetOptions_Initialize, tibasGetOptions_Free)
{
    
}

GetOptions&
GetOptions::setFilter(const std::string& filter)
{
    tibasGetOptions_SetFilter(get(), filter.c_str());
    return *this;
}

std::string
GetOptions::getFilter() const
{
    const char* filter = NULL;
    tibasGetOptions_GetFilter(get(), &filter);
    return filter;
}

GetOptions&
GetOptions::setFields(int numFields, ...)
{
    va_list ap;
    tibasStringList fields;
    tibasStringList_Create(&fields);
    va_start(ap, numFields);
    for (int i = 0; i < numFields; ++i)
    {
        char* str = va_arg(ap, char*);
        tibasStringList_Put(fields, str);
    }
    va_end(ap);
    tibasGetOptions_SetFieldsEx(get(), fields);
    tibasStringList_Free(&fields);
    return *this;
}

GetOptions&
GetOptions::setFields(const vector<string>& fields)
{
    tibasGetOptions_SetFieldsEx(get(), vectorToStringList(fields));
    return *this;
}

vector<string>
GetOptions::getFields() const
{
    tibasStringList fields;
    tibasGetOptions_GetFields(get(), &fields);
    return asStringListToVector(fields);
}
