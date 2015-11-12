/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Admin.h"
#include "Utils.h"

using namespace ASApi;
using namespace std;

Admin::Admin()
: m_admin(new tibasAdmin(), Deleter<tibasAdmin>(tibasAdmin_Free))
{
    AS_CALL(tibasAdmin_Create(m_admin.get()));
}


Admin::~Admin()
{
    
}


Metaspace Admin::connect(const string& command)
{
    tibasMetaspace metaspace;
    AS_CALL(tibasAdmin_Connect(*m_admin, &metaspace, command.c_str()));
    return Metaspace(metaspace);
}


string Admin::execute(const Metaspace &metasace, const string &command)
{
    char* result = NULL;
    AS_CALL(tibasAdmin_Execute(*m_admin, &result, metasace.get(), command.c_str()));
    return result;
}
