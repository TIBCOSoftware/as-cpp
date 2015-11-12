/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __SpaceResult__
#define __SpaceResult__

#include "tibas.h"
#include "Exception.h"
#include "Tuple.h"
#include "Result.h"
#include "Types.h"

namespace ASApi
{
    class AS_CPP_API SpaceResult : public Result
    {
    public:
        SpaceResult(const tibasSpaceResult& spaceResult);
        ~SpaceResult();
        
        bool hasError() const;
        Status getStatus() const;
        Exception getError() const;
        Tuple getTuple() const;
        
    private:
        const tibasSpaceResult& m_spaceResult;
    };
}

#endif
