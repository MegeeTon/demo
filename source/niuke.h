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
//剑指offer算法题

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

    //有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，
    //即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，求数组中的最小值。
    int minNumberInRotateArray(vector<int> rotateArray);

    //输入一个整数 n ，输出该数32位二进制表示中1的个数。其中负数用补码表示。
    int  NumberOf1(int n);//或按位与flag = 1<<i

    //输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，
    //则打印出 1、2、3 一直到最大的 3 位数 999。
    vector<int> printNumbers(int n);

    //给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
    //返回删除后的链表的头节点。
    ListNode* deleteNode(ListNode* head, int val);

    //输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。
    //如果该链表长度小于k，请返回一个长度为 0 的链表。
    ListNode* FindKthToTail(ListNode* pHead, int k);

    //给定一个单链表的头结点pHead(该头节点是有值的，比如在下图，它的val是1)，长度为n
    //，反转该链表后，返回新链表的表头。
    ListNode* ReverseList(ListNode* pHead);

    //输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2);

    //操作给定的二叉树，将其变换为源二叉树的镜像。
    TreeNode* Mirror(TreeNode* pRoot);
};
////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __NIUKE_H__
////////////////////////////////// EOF /////////////////////////////////////////