/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef _FieldDefList_h
#define _FieldDefList_h

#include <string>
#include "tibas.h"
#include "Exception.h"
#include "FieldDef.h"
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API FieldDefList
    {
    public:
        FieldDefList();
        ~FieldDefList();

        const tibasFieldDefList& get() const;

        tibasFieldDefList& get();

        FieldDef get(int index);

        int size() const;
        
    private:
        SharedPtr<tibasFieldDefList> m_fieldDefList;
    };
}

#endif
