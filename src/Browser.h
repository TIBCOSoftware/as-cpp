/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _Browser_h
#define _Browser_h

#include <string>
#include "SharedPtr.h"
#include "tibas.h"
#include "Exception.h"
#include "Tuple.h"

namespace ASApi
{
    class AS_CPP_API Browser
    {
    public:
        Browser();
        ~Browser();

        const tibasBrowser& get() const;

        tibasBrowser& get();
        
        Tuple next() const;
        

    private:
        SharedPtr<tibasBrowser> m_browser;
    };
}

#endif
