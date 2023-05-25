/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * niuke : [description]
 *
 * filename : niuke.h
 * author   : tangmq(tangmq@initialsoft.com)
 * create   : 2023-05-25 02:08:58 UTC
 * modified : 2023-05-25 02:24:57 UTC
\******************************************************************************/

#ifndef __NIUKE_H__
#define __NIUKE_H__

////////////////////////////////////////////////////////////////////////////////
// Headers
// #include <iostream>
#include <ctime>
#include <string>
#include <utility>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//
class NIUKE
{
public:
    NIUKE();
    ~NIUKE();

public:

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

public:
    // hash表
#define HASHSIZE 12
#define NULLKEY -1

    typedef struct {
        int* _elem;
        int _count;
    } _hashtable;

    _hashtable* _hash = new _hashtable;

    typedef struct ListNode {
        int val;
        struct ListNode* next;
        ListNode(int x)
            : val(x)
            , next(NULL)
        {}
    }*_list;


public:
    //输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。
    vector<int> printListFromTailToHead(ListNode* head);
    //给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);

};
////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __NIUKE_H__
////////////////////////////////// EOF /////////////////////////////////////////