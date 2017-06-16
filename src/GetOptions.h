/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __GetOptions__
#define __GetOptions__

#include "tibas.h"
#include "SpaceOptions.h"

namespace ASApi
{
    class AS_CPP_API GetOptions : public SpaceOptions<GetOptions, tibasGetOptions>
    {
    public:
        GetOptions();

        GetOptions& setFilter(const std::string& filter);
        std::string getFilter() const;

        GetOptions& setFields(int numFields, ...);
        GetOptions& setFields(const std::vector<std::string>& fields);
        std::vector<std::string> getFields() const;
    };    
}

#endif
