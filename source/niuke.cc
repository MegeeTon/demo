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

NIUKE::TreeNode* NIUKE::reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    int len = vin.size();

    vector<int> pre_left, pre_right, vin_left, vin_right;

    if (len == 0)
        return nullptr;

    TreeNode* head = new TreeNode(pre[0]);

    int root;
    for (int i = 0; i < len; i++)
    {
        if (vin[i] == pre[0])
        {
            root = i;
            break;
        }
    }
    for (int i = 0; i < root; i++)
    {
        pre_left.push_back(pre[i + 1]);
        vin_left.push_back(vin[i]);
    }
    for (int i = root + 1; i < len; i++)
    {
        pre_right.push_back(pre[i]);
        vin_right.push_back(vin[i]);
    }
    head->left = reConstructBinaryTree(pre_left, vin_left);
    head->right = reConstructBinaryTree(pre_right, vin_right);
    return head;
}


////////////////////////////////// EOF /////////////////////////////////////////
