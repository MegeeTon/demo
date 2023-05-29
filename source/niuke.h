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
#include <unordered_map>
#include <stack>

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

    stack<int> stack1;
    stack<int> stack2;


public:
    //输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。
    vector<int> printListFromTailToHead(ListNode* head);
   
    //给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回
    //它的头结点。
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);

    //在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重
    //复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组
    //中任意一个重复的数字。
    int duplicate(vector<int>& numbers);

    //请实现一个函数，将一个字符串s中的每个空格替换成“ % 20”。
    string replaceSpace(string s);

    //用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部
    //插入整数(push)和n次在队列头部删除整数(pop)的功能。
    void push(int node);

    int pop();




};
////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __NIUKE_H__
////////////////////////////////// EOF /////////////////////////////////////////