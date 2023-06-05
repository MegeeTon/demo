/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * algorithm : [description]
 *
 * filename : algorithm.h
 * author   : tangmq(megee@initialsoft.com)
 * create   : 2023-02-20 06:15:49 UTC
 * modified : 2023-05-25 02:21:07 UTC
\******************************************************************************/

#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include <ctime>
#include <iostream>
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

class Algorithm
{
 public:
  Algorithm();
  ~Algorithm();

 public:
  //二叉树
  typedef struct _bitnode {
    int _data;
    struct _bitnode *_lchild, *_rchild;
  } _bitnode, *_bittree;

  _bittree* _tree = new _bittree;

 public:
  // hash表
#define HASHSIZE 12
#define NULLKEY -1

  typedef struct {
    int* _elem;
    int _count;
  } _hashtable;

  _hashtable* _hash = new _hashtable;

 public:
  static const int max_size = 100;

  clock_t start, end;
  // start = clock();
  // end = clock();
  // cout << "time: " << (double)(end - start)/ CLOCKS_PER_SEC << endl;

  /**************************数据结构*************************************/
  /**
   * 顺序表
   */
  void sqList();

  /**
   * 单链表
   */
  void linkList();

  /**
   * 顺序栈
   */
  void sqStack();

  /**
   * 链式栈
   */
  void linkStack();

  /**
   * 循环队列
   */
  void sqQueue();

  /**
   * 链式队列
   */
  void linkQueue();

  //创建二叉树
  void createBitTree(_bittree* t);

  //前序遍历
  void preOrderTraverse(_bittree* t);

  //中序遍历
  void inOrderTraverse(_bittree* t);

  //后序遍历
  void postOrderTraverse(_bittree* t);

  //二叉排序树插入
  bool insertBST(_bittree* t, int key);

  //二叉排序树删除
  bool deleteBST(_bittree* t, int key);

  //二叉排序树删除节点
  bool _delete(_bittree* p);

  //创建二叉排序树
  void createBST();

  //初始化hash表
  bool initHashTable(_hashtable* _hash);

  // hash函数
  int hash(int key);

  // hash表插值
  void insertHash(_hashtable* _hash, int key);

  /**************************基础算法************************************/
  /**
   * 斐波那契数列迭代
   */
  void fibonacci_iter();

  /**
   * 斐波那契数列递归
   * @param  count [description]
   * @return       [description]
   */
  int fibonacci_recur(int count);

  //哨兵查找
  int sequebtialSearch(int* a, int n, int key);

  /**
   * 二分查找
   */
  void binarySearch();

  //二叉排序树查找
  bool searchBST(_bittree t, int key, _bittree f, _bittree* p);

  // hsah表查找
  bool searchHash(_hashtable* _hash, int key, int* addr);

  //辗转相除法-求最大公约数
  int successiveDivision(int a, int b);

  //判断素数
  bool primeNum(int a);

  //鸡兔同笼
  void jitutonglong(int head, int leg);

  //冒泡排序
  void bubbleSort();

  //选择排序
  void selectSort();

  //插入排序
  void insertSort();

  //希尔排序-插排优化
  void shellSort();

  //快排
  void quickSort();

  //快排递归
  void QSort(int* a, int low, int high);

  //快排分割
  int partition(int* a, int low, int high);

  /*****************************功能***********************************/
  /**
   * c++字符串切割
   */
  vector<string> stringSplit(string str, const string& split);

  /**
   * 数值范围计算
   * @param length [description]
   * @param digits [description]
   */
  void rangeCac(string length, string digits);

  /**
   * 浮点数转经纬度
   * @param  position [description]
   * @return          [description]
   */
  string doubleToCoord(double position);

  /**
   * 经纬度转浮点数
   * @param  position [description]
   * @return          [description]
   */
  double coordToDouble(string position);

  //十进制转十六进制
  void detToHex(int dec);

  //加密
  void encryption();
};

////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __ALGORITHM_H__
////////////////////////////////// EOF /////////////////////////////////////////
