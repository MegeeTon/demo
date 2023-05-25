/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * niuke : [description]
 *
 * filename : niuke.cc
 * author   : tangmq(tangmq@initialsoft.com)
 * create   : 2023-05-25 02:08:58 UTC
 * modified : 2023-05-25 02:18:02 UTC
\******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include "niuke.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Inner Scope Objects
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//
NIUKE::NIUKE()
{
	
}

NIUKE::~NIUKE() {}
////////////////////////////////////////////////////////////////////////////////
// Functions
//

vector<int> NIUKE::printListFromTailToHead(ListNode* head) {
    vector<int> rslt;
    while (head)
    {
        rslt.insert(rslt.begin(), head->val);
        head = head->next;
    }
    return rslt;
}



////////////////////////////////// EOF /////////////////////////////////////////
