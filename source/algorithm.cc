/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * algorithm : [description]
 *
 * filename : algorithm.cc
 * author   : tangmq(megee@initialsoft.com)
 * create   : 2023-02-20 06:15:49 UTC
 * modified : 2023-05-08 05:40:28 UTC
\******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
// Headers
//
#include "algorithm.h"

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//

////////////////////////////////////////////////////////////////////////////////
// Inner Scope Objects
//

////////////////////////////////////////////////////////////////////////////////
// Classes
//

Algorithm::Algorithm()
{
    *_tree = NULL;
    createBST();
    preOrderTraverse(_tree);
    inOrderTraverse(_tree);
    postOrderTraverse(_tree);
}

Algorithm::~Algorithm() {}

////////////////////////////////////////////////////////////////////////////////
// Functions
//

void Algorithm::sqList()
{
    typedef struct _list {
        int _data[max_size];
        int _length;
    } _sqList;

    //creat
    _sqList* s = new _sqList;
    s->_data[0] = 100;
    s->_length = 1;
    for (int i = 0; i < 8; i++)
    {
        s->_length++;
        s->_data[s->_length-1] = s->_length + 99;
    }
    cout << "顺序表第一个数据：" << s->_data[0] << endl;
    cout << "顺序表第二个数据：" << s->_data[1] << endl;
    cout << "顺序表第三个数据：" << s->_data[2] << endl;
    cout << endl;

    //push
    int pos = 2;
    if (s->_length == max_size)
        return;
    if (pos<1 || pos>s->_length)
        return;
    for (int i = s->_length - 1; i >= pos - 1; i--)
    {
        s->_data[i + 1] = s->_data[i];
    }
    s->_data[pos - 1] = 666;
    s->_length++;
    cout << "顺序表第一个数据：" << s->_data[0] << endl;
    cout << "顺序表第二个数据：" << s->_data[1] << endl;
    cout << "顺序表第三个数据：" << s->_data[2] << endl;
    cout << endl;
    
    //pop
    if (s->_length == 0)
        return;
    if (pos<1 || pos>s->_length)
        return;
    for (int i = pos-1; i <=s->_length-1; i++)
    {
        s->_data[i] = s->_data[i + 1];
    }
    s->_length--;
    cout << "顺序表第一个数据：" << s->_data[0] << endl;
    cout << "顺序表第二个数据：" << s->_data[1] << endl;
    cout << "顺序表第三个数据：" << s->_data[2] << endl;
    cout << endl;
}

void Algorithm::linkList()
{
  typedef struct node {
    int _data;
    node* _next;
  } _node;

  //creat
  typedef _node* _linkList;
  int length = 10;
  _node* node = new _node;
  _linkList* l = new _linkList;
  *l           = node;
  for (int i = 0; i < length; i++) {
    _node* p    = new _node;
    p->_data = i + 100;
    node->_next = p;
    node        = p;
  }
  node->_next = NULL;
  cout << "单链表第一个数据：" << (*l)->_next->_data << endl;
  cout << "单链表第二个数据：" << (*l)->_next->_next->_data << endl;
  cout << "单链表第三个数据：" << (*l)->_next->_next->_next->_data << endl;
  cout << endl;

  // push
  _node* nodetmp = new _node;
  nodetmp        = *l;
  for (int i = 0; i < 1; i++) { nodetmp = nodetmp->_next; }
  if (!nodetmp) 
      return;
  _node* node1   = new _node;
  node1->_data   = 666;
  node1->_next   = nodetmp->_next;
  nodetmp->_next = node1;
  cout << "单链表第一个数据：" << (*l)->_next->_data << endl;
  cout << "单链表第二个数据：" << (*l)->_next->_next->_data << endl;
  cout << "单链表第三个数据：" << (*l)->_next->_next->_next->_data << endl;
  cout << endl;

  // pop
  nodetmp = *l;

  for (int i = 0; i < 1; i++) { nodetmp = nodetmp->_next; }
  if (!nodetmp->_next) 
      return;
  _node* nodedelete = new _node;
  nodedelete        = nodetmp->_next;
  nodetmp->_next    = nodedelete->_next;
  delete (nodedelete);
  cout << "单链表第一个数据：" << (*l)->_next->_data << endl;
  cout << "单链表第二个数据：" << (*l)->_next->_next->_data << endl;
  cout << "单链表第三个数据：" << (*l)->_next->_next->_next->_data << endl;
  cout << endl;
}

void Algorithm::sqStack()
{
    typedef struct _stack {
        int _data[max_size];
        int _top;
    } _sqStack;

    //creat
    _sqStack* s = new _sqStack;
    s->_top = 0;
    s->_data[s->_top] = 100;
    for (int i = 0; i < 80; i++)
    {
        s->_top++;
        s->_data[s->_top] = s->_top + 100;
    }
    cout << "栈顶元素：" << s->_data[s->_top] << endl;
    cout << endl;

    //push
    if (s->_top == max_size-1)
        return;
    s->_top++;
    s->_data[s->_top] = 666;
    cout << "栈顶元素：" << s->_data[s->_top] << endl;
    cout << endl;

    //pop
    if (s->_top == -1)
        return;
    s->_top--;
    cout << "栈顶元素：" << s->_data[s->_top] << endl;
    cout << endl;

}

void Algorithm::linkStack()
{
  typedef struct _node {
    int _data;
    _node* _next;
  } _stackNode;

  typedef struct _list {
    _stackNode* top;
    int count;
  } _linkStack;

  //creat
  _linkStack* s = new _linkStack;
  _stackNode* node  = new _stackNode;
  node->_data       = 100;
  node->_next       = nullptr;
  s->top            = node;
  s->count          = 1;
  cout << "栈顶元素：" << s->top->_data << endl;
  cout << endl;

  // push
  _stackNode* node1 = new _stackNode;
  node1->_data      = 200;
  node1->_next      = s->top;
  s->top            = node1;
  s->count++;
  cout << "栈顶元素：" << s->top->_data << endl;
  cout << endl;

  // pop
  _stackNode* node2 = new _stackNode;
  node2             = s->top;
  s->top            = s->top->_next;
  s->count--;
  delete node2;
  cout << "栈顶元素：" << s->top->_data << endl;
  cout << endl;
}

void Algorithm::sqQueue()
{
    typedef struct _queue {
        int _data[max_size];
        int _front;
        int _rear;
    }_sqQueue;

    //creat
    _sqQueue* s = new _sqQueue;
    s->_front = 0;
    s->_rear = 0;
    s->_data[s->_rear] = 100;
    s->_rear = (s->_rear + 1) % 10;

    //push
    if ((s->_rear + 1) % max_size == s->_front)
        return;
    s->_data[s->_rear] = 200;
    s->_rear = (s->_rear + 1) % max_size;
    cout << "队头数据：" << s->_data[s->_front] << endl;
    cout << "队列长度：" << (s->_rear - s->_front + max_size) % max_size << endl;

    //pop
    s->_front = (s->_front + 1) % max_size;
    cout << "队头数据：" << s->_data[s->_front] << endl;
    cout << "队列长度：" << (s->_rear - s->_front + max_size) % max_size << endl;
}

void Algorithm::linkQueue()
{
  typedef struct _node {
    int _data;
    _node* _next;
  } _queueNode;

  typedef struct _list {
    _queueNode* _front;
    _queueNode* _rear;
  } _linkQueue;

  //creat
  _linkQueue* q = new _linkQueue;
  _queueNode* first = new _queueNode;
  first->_next = NULL;
  q->_rear = first;
  q->_front = first;

  //push
  _queueNode* s = new _queueNode;
  if (!s)
      return;
  s->_data = 100;
  s->_next = NULL;
  q->_rear->_next = s;
  q->_rear = s;
  _queueNode* s2 = new _queueNode;
  s2->_data = 200;
  s2->_next = NULL;
  q->_rear->_next = s2;
  q->_rear = s2;
  cout << "队头数据：" << q->_front->_next->_data << endl;

  //pop
  if (q->_front->_next == q->_rear)
      return;
  _queueNode* tmp = new _queueNode;
  tmp = q->_front->_next;
  q->_front->_next = tmp->_next;
  cout << "队头数据：" << q->_front->_next->_data << endl;
  delete(tmp);
}

void Algorithm::createBitTree(_bittree *t)
{
    static int tmp_data = 1;
    if (tmp_data > 10)
        return;
    if (tmp_data % 3 == 0||tmp_data ==4)
    {
        *t = NULL;
        tmp_data++;
    }
    else
    {
        *t = new _bitnode;
        if (!*t)
            return;
        (*t)->_data = tmp_data++;
        (*t)->_lchild = (*t)->_rchild = NULL;
        createBitTree(&(*t)->_lchild);
        createBitTree(&(*t)->_rchild);
    }
}

void Algorithm::preOrderTraverse(_bittree *t)
{
    if (*t==NULL)
        return;
    cout << (*t)->_data << "  ";
    preOrderTraverse(&(*t)->_lchild);
    preOrderTraverse(&(*t)->_rchild);
}

void Algorithm::inOrderTraverse(_bittree *t)
{
    if (*t == NULL)
        return;
    inOrderTraverse(&(*t)->_lchild);
    cout << (*t)->_data << "  ";
    inOrderTraverse(&(*t)->_rchild);
}

void Algorithm::postOrderTraverse(_bittree *t)
{
    if (*t == nullptr)
        return;
    postOrderTraverse(&(*t)->_lchild);
    postOrderTraverse(&(*t)->_rchild);
    cout << (*t)->_data << "  ";
}

bool Algorithm::searchBST(_bittree t, int key, _bittree f, _bittree* p)
{
    if (!t)
    {
        *p = f;
        return false;
    }
    else if(key == t->_data)
    {
        *p = t;
        return true;
    }
    else if (key < t->_data)
    {
        return searchBST(t->_lchild, key, t, p);
    }
    else
    {
        return searchBST(t->_rchild, key, t, p);
    }
}

bool Algorithm::insertBST(_bittree* t, int key)
{
    _bittree p = new _bitnode;
    _bittree s = new _bitnode;
    if (!searchBST(*t, key, NULL, &p))
    {
        s = new _bitnode;
        s->_data = key;
        s->_lchild = s->_rchild = NULL;
        if (!p)
            *t = s;
        else if (key < p->_data)
            p->_lchild = s;
        else
            p->_rchild = s;
        return true;
    }
    else
        return false;
}

void Algorithm::createBST()
{
    int a[10] = { 62,88,58,47,35,28,18,99,37,9 };
    for (int i = 0; i < 10; i++)
        insertBST(_tree, a[i]);
}

bool Algorithm::_delete(_bittree* p)
{
    _bittree q = new _bitnode;
    _bittree s = new _bitnode;

    if ((*p)->_rchild == NULL)
    {
        q = *p;
        *p = (*p)->_lchild;
        delete q;
    }
    else if ((*p)->_lchild == NULL)
    {
        q = *p;
        *p = (*p)->_rchild;
        delete q;
    }
    else
    {
        q = *p;
        s = (*p)->_lchild;
        while (s->_rchild)
        {
            q = s;
            s = s->_rchild;
        }
        (*p)->_data = s->_data;
        if (q != *p)
            q->_rchild = s->_lchild;
        else
            q->_lchild = s->_lchild;
        delete s;
    }
    return true;
}

bool Algorithm::deleteBST(_bittree* t, int key)
{
    if (!*t)
        return false;
    else
    {
        if (key == (*t)->_data)
            return _delete(t);
        else if (key < (*t)->_data)
            return deleteBST(&(*t)->_lchild, key);
        else
            return deleteBST(&(*t)->_rchild, key);
    }
}

void Algorithm::fibonacci_iter()
{
    int a[41];
    a[0] = 0;
    a[1] = 1;

    for (int i = 2; i < 41; i++) { a[i] = a[i - 1] + a[i - 2]; }

    cout << a[40] << endl;
}

int Algorithm::fibonacci_recur(int count)
{
    if (count < 2 && count >= 0) {
        return count == 0 ? 0 : 1;
    }
    else {
        return fibonacci_recur(count - 1) + fibonacci_recur(count - 2);
    }
}

vector<string> Algorithm::stringSplit(string str, const string& split)
{
  vector<string> strlist;
  strlist.clear();

  if (str == "") return strlist;
  string strs = str + split;
  size_t pos  = str.find(split);
  int steps   = split.size();

  while (pos != strs.npos) {
    string temp = strs.substr(0, pos);
    strlist.push_back(temp);
    strs = strs.substr(pos + steps, strs.size());
    pos  = strs.find(split);
  }
  return strlist;
}

void Algorithm::rangeCac(string length, string digits)
{
  auto rel = to_string(pow(10, 
      atoi(length.c_str()) - atoi(digits.c_str()))
    - pow(0.1, atoi(digits.c_str())));
}

string Algorithm::doubleToCoord(double position)
{
  string rslt;
  int du = (int) position;
  rslt += to_string(du);
  int fen  = (int) ((position - du) * 60);
  rslt     = rslt + "°" + to_string(fen) + "′";
  int miao = (int) (((position - du) * 60 - fen) * 60);
  rslt     = rslt + to_string(miao) + "″";
  return rslt;
}

double Algorithm::coordToDouble(string position)
{
  double rslt;
  string tmp  = position.substr(1, position.size() - 1);
  string tmp1 = stringSplit(tmp, "°").at(0);
  cout << tmp1 << endl;
  rslt = stod(tmp1);
  tmp1 = stringSplit(tmp, "°").at(1);
  tmp1 = stringSplit(tmp1, "′").at(0);
  cout << tmp1 << endl;
  rslt += stod(tmp1) / 60;
  tmp1 = stringSplit(tmp, "′").at(1);
  tmp1 = stringSplit(tmp1, "″").at(0);
  cout << tmp1 << endl;
  rslt += stod(tmp1) / 3600;
  return rslt;
}

void Algorithm::binarySearch()
{
    //data
    int _a[10] = {0,1,16,24,35,44,56,72,88,91};
    int _size = 10;
    int _key = 88;

    //search
    int _low = 1;
    int _high = _size;
    int _mid;
    while (_low <= _high)
    {
        //二分法，顺序数列
        _mid = (_high + _low) / 2;
        //插值法，适用于分部均匀的数列
        //_mid = (_high - _low) * (_key - _a[_low]) / (_a[_high] - _a[_low]);
        if (_key < _a[_mid])
            _high = _mid - 1;
        else if (_key > _a[_mid])
            _low = _mid + 1;
        else
        {
            cout << _mid << endl;
            return;
        }
    }
    cout << "无";
}

////////////////////////////////// EOF /////////////////////////////////////////
