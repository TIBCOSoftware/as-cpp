/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Browser.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;

Browser::Browser()
: m_browser(new tibasBrowser(), Deleter<tibasBrowser>(tibasBrowser_Free))
{
    //Create
}


Browser::~Browser()
{
    
}


const tibasBrowser& Browser::get() const
{
    return *m_browser;
}


tibasBrowser& Browser::get()
{
    return *m_browser;
}

Tuple Browser::next() const
{
    SharedPtr<tibasTuple> tuple (new tibasTuple(), Deleter<tibasTuple>(tibasTuple_Free));
    AS_CALL(tibasBrowser_Next(get(), tuple.get()));
    return Tuple(tuple);
}













