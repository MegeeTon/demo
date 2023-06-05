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


int NIUKE::minNumberInRotateArray(vector<int> rotateArray) {
    int mid, low = 0;
    int high = rotateArray.size() - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (rotateArray[mid] < rotateArray[high])
            high = mid;
        else if (rotateArray[mid] > rotateArray[high])
            low = mid + 1;
        else
            high -= 1;
    }
    return rotateArray[low];
}



int  NIUKE::NumberOf1(int n) {
    int rslt = 0;
    if (n < 0)
    {
        n = 2147483648 + n;
        rslt = 1;
    }
    while (n)
    {
        int tmp = n % 2;
        n = n / 2;
        if (tmp == 1)
            rslt++;
    }
    return rslt;
}


vector<int> NIUKE::printNumbers(int n) {
    // write code here
    vector<int> rslt;
    int size = pow(10, n);
    for (int i = 1; i < size; i++)
    {
        rslt.push_back(i);
    }
    return rslt;
}

NIUKE::ListNode* NIUKE::deleteNode(ListNode* head, int val) {
    // write code here
    ListNode* tmp = head;
    if (head->val == val)
    {

        if (head->next == nullptr)
            head = nullptr;
        else
            head = head->next;
    }
    while (tmp->next != nullptr)
    {
        if (tmp->next->val == val)
        {
            if (tmp->next->next == nullptr)
                tmp->next = nullptr;
            else
                tmp->next = tmp->next->next;
        }
        tmp = tmp->next;
    }
    return head;
}

NIUKE::ListNode* NIUKE::FindKthToTail(ListNode* pHead, int k) {
    // write code here
    ListNode* rslt = nullptr;
    ListNode* tmp = pHead;
    tmp = pHead;
    int i = 0;

    if (pHead == nullptr || k <= 0)
        return rslt;

    while (i < k - 1)
    {
        if (tmp->next == nullptr)
            return rslt;
        tmp = tmp->next;
        i++;
    }

    rslt = pHead;
    while (tmp->next != nullptr)
    {
        rslt = rslt->next;
        tmp = tmp->next;
    }

    return rslt;

}

NIUKE::ListNode* NIUKE::ReverseList(ListNode* pHead) {
    if (pHead == nullptr)
        return nullptr;

    ListNode* first = pHead;
    ListNode* rslt = pHead->next;
    ListNode* tmp;

    while (rslt != nullptr)
    {
        tmp = first;
        first = rslt;
        rslt = rslt->next;
        first->next = tmp;
    }
    pHead->next = nullptr;
    return first;
}

NIUKE::ListNode* NIUKE::Merge(ListNode* pHead1, ListNode* pHead2) {
    auto* rslt = new ListNode(-1);
    ListNode* tmp1 = rslt;
    if (pHead1 == nullptr || pHead2 == nullptr)
        return pHead1 == nullptr ? pHead2 : pHead1;
    while (pHead1 != nullptr && pHead2 != nullptr)
    {
        if (pHead1->val <= pHead2->val)
        {
            tmp1->next = pHead1;
            pHead1 = pHead1->next;
        }
        else {
            tmp1->next = pHead2;
            pHead2 = pHead2->next;
        }
        tmp1 = tmp1->next;
    }
    if (pHead1 == nullptr)
        tmp1->next = pHead2;
    else
        tmp1->next = pHead1;
    return rslt->next;
}

NIUKE::TreeNode* Mirror(NIUKE::TreeNode* pRoot) {
    // write code here
    if (!pRoot)
        return pRoot;   

    NIUKE::TreeNode* tmp;
    if (pRoot)
    {
        tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        pRoot->left = Mirror(pRoot->left);
        pRoot->right = Mirror(pRoot->right);
    }
    return pRoot;
}

////////////////////////////////// EOF /////////////////////////////////////////
