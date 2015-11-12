/*
 * Copyright (c) 2014-2015 TIBCO Software Inc.
 * All rights reserved.
 * For more information, please contact:
 * TIBCO Software Inc., Palo Alto, California, USA
 */

#include "GetOptions.h"
#include "options.h"
#include "Exception.h"

using namespace std;
using namespace ASApi;


GetOptions::GetOptions()
: SpaceOptions<ASApi::GetOptions, tibasGetOptions>(tibasGetOptions_Initialize)
{
    
}


