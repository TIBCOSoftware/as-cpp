/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _EventBrowser_h
#define _EventBrowser_h

#include <string>
#include "tibas.h"
#include "Exception.h"
#include "Tuple.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API EventBrowser
    {
    public:

        EventBrowser();
        ~EventBrowser();

        const tibasEventBrowser& get() const;

        tibasEventBrowser& get();

    private:
        SharedPtr<tibasEventBrowser> m_eventBrowser;
    };
}

#endif
