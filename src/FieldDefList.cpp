/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "FieldDefList.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

FieldDefList::FieldDefList()
: m_fieldDefList(new tibasFieldDefList(), Deleter<tibasFieldDefList>(tibasFieldDefList_Free))
{
    //Create
    
}


FieldDefList::~FieldDefList()
{
    
}


const tibasFieldDefList& FieldDefList::get() const
{
    return *m_fieldDefList;
}


tibasFieldDefList& FieldDefList::get()
{
    return *m_fieldDefList;
}


FieldDef FieldDefList::get(int index)
{
    FieldDef fieldDef;
    AS_CALL(tibasFieldDefList_Get(get(), &fieldDef.get(), index));
    return fieldDef;
}


int FieldDefList::size() const
{
    int s = 0;
    AS_CALL(tibasFieldDefList_Size(get(), &s));
    return s;
}
