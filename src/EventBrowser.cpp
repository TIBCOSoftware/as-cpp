/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "EventBrowser.h"
#include "Exception.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

EventBrowser::EventBrowser()
: m_eventBrowser(new tibasEventBrowser(), Deleter<tibasEventBrowser>(tibasEventBrowser_Free))
{
    //Create
}


EventBrowser::~EventBrowser()
{
    
}


const tibasEventBrowser& EventBrowser::get() const
{
    return *m_eventBrowser;
}


tibasEventBrowser& EventBrowser::get()
{
    return *m_eventBrowser;
}

/*
Tuple EventBrowser::next() const
{
    Tuple tuple;
    //AS_CALL(tibasEventBrowser_Next(get(), &tuple.get()));
    return tuple;
}
*/












