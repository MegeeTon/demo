/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * algorithm : [description]
 *
 * filename : algorithm.h
 * author   : tangmq(megee@initialsoft.com)
 * create   : 2023-02-20 06:15:49 UTC
 * modified : 2023-05-11 09:15:27 UTC
\******************************************************************************/

#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

////////////////////////////////////////////////////////////////////////////////
// Headers
//
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
	typedef struct _bitnode
	{
		int _data;
		struct _bitnode* _lchild, * _rchild;
	}_bitnode ,*_bittree;

	_bittree* _tree = new _bittree;

 public:
  static const int max_size = 100;

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

  /**
   * 二分查找
   */
  void binarySearch();
};

////////////////////////////////////////////////////////////////////////////////
// Functions
//

#endif  // __ALGORITHM_H__
////////////////////////////////// EOF /////////////////////////////////////////
