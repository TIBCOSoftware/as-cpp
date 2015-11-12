/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __ActionResult__
#define __ActionResult__

#include <memory>
#include "tibas.h"
#include "Tuple.h"
#include "Types.h"

namespace ASApi
{
    class AS_CPP_API ActionResult
    {
    public:
        explicit ActionResult(tibasActionResult& actionResult);

        ActionResult& setFailed();
        ActionResult& setFailed(const Status& status);
        Status getStatus() const;
        
        ActionResult& setTuple(const Tuple& tuple);
        Tuple getTuple() const;
        
    private:
        tibasActionResult& m_actionResult;
    };
}
#endif
