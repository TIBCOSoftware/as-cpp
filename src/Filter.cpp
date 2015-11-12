/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Filter.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

Filter::Filter(const string& filterString)
: m_filter(new tibasFilter(), Deleter<tibasFilter>(tibasFilter_Free))
{
    //Create
    AS_CALL(tibasFilter_Create(m_filter.get(), filterString.c_str()));
}


Filter::~Filter()
{
    
}


const tibasFilter& Filter::get() const
{
    return *m_filter;
}


tibasFilter& Filter::get()
{
    return *m_filter;
}


bool Filter::eval(const Tuple& tuple) const
{
    tibas_boolean result;
    AS_CALL(tibasFilter_Eval(get(), tuple.get(),&result));
    if(result == TIBAS_TRUE)
    {
        return true;
    }
    else
    {
        return false;
    }
}
