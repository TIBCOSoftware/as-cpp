/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#ifndef __SpaceResultList__
#define __SpaceResultList__

#include "tibas.h"
#include "SpaceResult.h"
#include "ResultList.h"
#include "Types.h"
#include <vector>
#include "SharedPtr.h"

namespace ASApi
{
    class AS_CPP_API SpaceResultList : public ResultList
    {
    public:
        explicit SpaceResultList(const SharedPtr<tibasSpaceResultList>& spaceResultList);
        ~SpaceResultList();
        
        bool hasError() const;
        
        Exception getError(int index) const;
        
        Status getStatus(int index) const;
        
        Tuple getTuple(int index) const;
        
        int size() const;
        
        void getTuples(std::vector<Tuple>& tuples) const;
        
    private:
        SharedPtr<tibasSpaceResultList> m_spaceResultList;
    };
}


#endif
