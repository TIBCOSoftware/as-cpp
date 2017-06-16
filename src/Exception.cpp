/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "Exception.h"
#include "Utils.h"

using namespace std;
using namespace ASApi;

Exception::Exception(const tibas_status& status)
: m_status(status),
  m_error(new tibasError(), Deleter<tibasError>(tibasError_Free))
{
	tibas_GetError(m_error.get());
}


Exception::Exception(const tibasError& error)
: m_status(TIBAS_OK),
  m_error(NULL)
{
    if (error != NULL)
    {
        tibasError* clone = new tibasError();
        AS_CALL(tibasError_Clone(error, clone));
        m_error.reset(clone, tibasError_Free);
    }
}


Exception::Exception(SharedPtr<tibasError>& error)
    :m_status(TIBAS_OK),
    m_error(error)
{
}


const tibas_status&
Exception::getStatus() const
{
    return m_status;
}


tibas_status Exception::getCode() const
{
    tibas_status status = TIBAS_OK;
    if (m_error.get() != NULL)
        AS_CALL(tibasError_GetCode(*m_error, &status));
    return status;
}


string Exception::getMessage() const
{
    const char* message = NULL;
    if (m_error.get() != NULL)
        AS_CALL(tibasError_GetMessage(*m_error, &message));
    return message;
}


string Exception::getStackTrace() const
{
    const char* stackTrace = NULL;
    if (m_error.get() != NULL)
        AS_CALL(tibasError_GetStackTrace(*m_error, &stackTrace));
    return stackTrace;
}
