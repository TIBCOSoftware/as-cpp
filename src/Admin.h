/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Admin__
#define __Admin__

#include "tibas.h"
#include "Metaspace.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API Admin
    {
    public:
        Admin();
        ~Admin();
        
        Metaspace connect(const std::string& command);
        
        std::string execute(const Metaspace& metasace, const std::string& command);
        
    private:
        SharedPtr<tibasAdmin> m_admin;
    };
}

#endif
