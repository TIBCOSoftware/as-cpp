/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Utils__
#define __Utils__

#include <vector>
#include <string>
#include <memory>
#include "tibas.h"
#include "types.h"
#include "Tuple.h"
#include "Member.h"
#include "SharedPtr.h"

namespace ASApi
{
    typedef tibas_status Status;
 
    tibasStringList vectorToStringList(const std::vector<std::string>& strings);

    std::vector<std::string> asStringListToVector(const tibasStringList& stringList);
    
    SharedPtr<tibasTupleList> tuplesToAsTupleList(const std::vector<Tuple>& tuples);

    SharedPtr<tibasMemberList> membersToAsMemberList(const std::vector<Member>& members, const Metaspace& metaspace);
    
    std::vector<Member> asMemberListToVector(tibasMemberList& memberList);

}

#endif
