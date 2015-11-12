/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _Filter_h
#define _Filter_h

#include <string>
#include "tibas.h"
#include "Exception.h"
#include "Tuple.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API Filter
    {
    public:
        Filter(const std::string& filterString);
        ~Filter();

        const tibasFilter& get() const;

        tibasFilter& get();

        bool eval(const Tuple& tuple) const;        

    private:
        SharedPtr<tibasFilter> m_filter;
    };
}

#endif
