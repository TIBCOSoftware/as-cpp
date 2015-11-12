/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _FieldDef_h
#define _FieldDef_h

#include <string>
#include "tibas.h"
#include "Exception.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API FieldDef
    {
    public:
        typedef tibas_type Type;

        FieldDef();
        FieldDef(const std::string& fieldName, tibas_type fieldType);
        ~FieldDef();

        static FieldDef create(const std::string& fieldName, tibas_type fieldType);

        const tibasFieldDef& get() const;

        tibasFieldDef& get();

        std::string getName() const;
        
        Type getType() const;

        bool isNullable() const;

        FieldDef& setNullable(bool nullable);

        FieldDef& setEncrypted(bool secured);

        bool isEncrypted();

    private:
        SharedPtr<tibasFieldDef> m_fieldDef;
    };
}

#endif
