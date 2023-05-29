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


int NIUKE::duplicate(vector<int>& numbers) {
    int length = numbers.size();
    unordered_map<int, int> map;
    for (int i = 0; i < length; i++)
    {
        if (map.count(numbers[i]))
            return numbers[i];
        else
            map.insert(pair<int, int>(numbers[i], i));
    }
    return -1;
}

string NIUKE::replaceSpace(string s) {
    // write code here
    const char* tmp = "%20";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            s.replace(i, 1, tmp);
        }
    }
    return s;
}

void NIUKE::push(int node) {
    stack1.push(node);
}

int NIUKE::pop() {
    int rslt;
    if (stack2.empty())
    {
        int size = stack1.size();
        for (int i = 0; i < size; i++)
        {
            int tmp = stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        rslt = stack2.top();
        stack2.pop();
    }
    else {
        rslt = stack2.top();
        stack2.pop();
    }
    return rslt;
}




////////////////////////////////// EOF /////////////////////////////////////////
