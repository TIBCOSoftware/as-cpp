/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __SpaceDefListener__
#define __SpaceDefListener__

#include "tibas.h"
#include "SpaceDef.h"
#include "ListenerBase.h"
#include <memory>

namespace ASApi
{
    class AS_CPP_API SpaceDefListener : public ListenerBase<tibasListener>
    {
    public:
        SpaceDefListener();
        virtual ~SpaceDefListener();
        
        virtual void onDefine(const SpaceDef& spaceDef) { }
        static void onSpaceDefine(tibasSpaceDef spaceDef, void* closure);

        virtual void onAlter(const SpaceDef& oldSpaceDef, const SpaceDef& newSpaceDef) { }
        static void onSpaceAlter(tibasSpaceDef oldSpaceDef, tibasSpaceDef newSpaceDef, void* closure);
        
        virtual void onDrop(const SpaceDef& spaceDef) { }
        static void onSpaceDrop(tibasSpaceDef spaceDef, void* closure);
        
        void create();
    };
}

#endif
