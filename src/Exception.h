/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __Exception__
#define __Exception__

#include <string>
#include "tibas.h"
#include "SharedPtr.h"

#define AS_CALL(statement) \
{ \
    tibas_status status = statement; \
    if (status != TIBAS_OK) \
    { \
        throw ASApi::Exception(status); \
    } \
} \

namespace ASApi
{
    class AS_CPP_API Exception
    {
    public:
        Exception(const tibas_status& status);
        
        Exception(const tibasError& error);
        
        Exception(SharedPtr<tibasError>& error);
        const tibas_status& getStatus() const;
        
        tibas_status getCode() const;
        
        std::string getMessage() const;
        
        std::string getStackTrace() const;

    private:
        SharedPtr<tibasError> m_error;
        tibas_status m_status;
    };
}

#endif /* defined(__C__API__Exception__) */
