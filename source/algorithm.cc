/*******************************************************************************
 * Copyright (c) 2023, Initialsoft, Inc.
 * All rights reserved.
 *
 * algorithm : [description]
 *
 * filename : algorithm.cc
 * author   : tangmq(megee@initialsoft.com)
 * create   : 2023-02-20 06:15:49 UTC
 * modified : 2023-05-25 02:21:53 UTC
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


}

Algorithm::~Algorithm() {}

////////////////////////////////////////////////////////////////////////////////
// Functions
//

/**************************数据结构*************************************/

void Algorithm::sqList()
{
	typedef struct _list {
		int _data[max_size];
		int _length;
	} _sqList;

	// creat
	_sqList* s = new _sqList;
	s->_data[0] = 100;
	s->_length = 1;
	for (int i = 0; i < 8; i++) {
		s->_length++;
		s->_data[s->_length - 1] = s->_length + 99;
	}
	cout << "顺序表第一个数据：" << s->_data[0] << endl;
	cout << "顺序表第二个数据：" << s->_data[1] << endl;
	cout << "顺序表第三个数据：" << s->_data[2] << endl;
	cout << endl;

	// push
	int pos = 2;
	if (s->_length == max_size) return;
	if (pos < 1 || pos > s->_length) return;
	for (int i = s->_length - 1; i >= pos - 1; i--) {
		s->_data[i + 1] = s->_data[i];
	}
	s->_data[pos - 1] = 666;
	s->_length++;
	cout << "顺序表第一个数据：" << s->_data[0] << endl;
	cout << "顺序表第二个数据：" << s->_data[1] << endl;
	cout << "顺序表第三个数据：" << s->_data[2] << endl;
	cout << endl;

	// pop
	if (s->_length == 0) return;
	if (pos < 1 || pos > s->_length) return;
	for (int i = pos - 1; i <= s->_length - 1; i++) {
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

	// creat
	typedef _node* _linkList;
	int length = 10;
	_node* node = new _node;
	_linkList* l = new _linkList;
	*l = node;
	for (int i = 0; i < length; i++) {
		_node* p = new _node;
		p->_data = i + 100;
		node->_next = p;
		node = p;
	}
	node->_next = NULL;
	cout << "单链表第一个数据：" << (*l)->_next->_data << endl;
	cout << "单链表第二个数据：" << (*l)->_next->_next->_data << endl;
	cout << "单链表第三个数据：" << (*l)->_next->_next->_next->_data << endl;
	cout << endl;

	// push
	_node* nodetmp = new _node;
	nodetmp = *l;
	for (int i = 0; i < 1; i++) { nodetmp = nodetmp->_next; }
	if (!nodetmp) return;
	_node* node1 = new _node;
	node1->_data = 666;
	node1->_next = nodetmp->_next;
	nodetmp->_next = node1;
	cout << "单链表第一个数据：" << (*l)->_next->_data << endl;
	cout << "单链表第二个数据：" << (*l)->_next->_next->_data << endl;
	cout << "单链表第三个数据：" << (*l)->_next->_next->_next->_data << endl;
	cout << endl;

	// pop
	nodetmp = *l;

	for (int i = 0; i < 1; i++) { nodetmp = nodetmp->_next; }
	if (!nodetmp->_next) return;
	_node* nodedelete = new _node;
	nodedelete = nodetmp->_next;
	nodetmp->_next = nodedelete->_next;
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

	// creat
	_sqStack* s = new _sqStack;
	s->_top = 0;
	s->_data[s->_top] = 100;
	for (int i = 0; i < 80; i++) {
		s->_top++;
		s->_data[s->_top] = s->_top + 100;
	}
	cout << "栈顶元素：" << s->_data[s->_top] << endl;
	cout << endl;

	// push
	if (s->_top == max_size - 1) return;
	s->_top++;
	s->_data[s->_top] = 666;
	cout << "栈顶元素：" << s->_data[s->_top] << endl;
	cout << endl;

	// pop
	if (s->_top == -1) return;
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

	// creat
	_linkStack* s = new _linkStack;
	_stackNode* node = new _stackNode;
	node->_data = 100;
	node->_next = nullptr;
	s->top = node;
	s->count = 1;
	cout << "栈顶元素：" << s->top->_data << endl;
	cout << endl;

	// push
	_stackNode* node1 = new _stackNode;
	node1->_data = 200;
	node1->_next = s->top;
	s->top = node1;
	s->count++;
	cout << "栈顶元素：" << s->top->_data << endl;
	cout << endl;

	// pop
	_stackNode* node2 = new _stackNode;
	node2 = s->top;
	s->top = s->top->_next;
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
	} _sqQueue;

	// creat
	_sqQueue* s = new _sqQueue;
	s->_front = 0;
	s->_rear = 0;
	s->_data[s->_rear] = 100;
	s->_rear = (s->_rear + 1) % 10;

	// push
	if ((s->_rear + 1) % max_size == s->_front) return;
	s->_data[s->_rear] = 200;
	s->_rear = (s->_rear + 1) % max_size;
	cout << "队头数据：" << s->_data[s->_front] << endl;
	cout << "队列长度：" << (s->_rear - s->_front + max_size) % max_size << endl;

	// pop
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

	// creat
	_linkQueue* q = new _linkQueue;
	_queueNode* first = new _queueNode;
	first->_next = NULL;
	q->_rear = first;
	q->_front = first;

	// push
	_queueNode* s = new _queueNode;
	if (!s) return;
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

	// pop
	if (q->_front->_next == q->_rear) return;
	_queueNode* tmp = new _queueNode;
	tmp = q->_front->_next;
	q->_front->_next = tmp->_next;
	cout << "队头数据：" << q->_front->_next->_data << endl;
	delete (tmp);
}

void Algorithm::createBitTree(_bittree* t)
{
	static int tmp_data = 1;
	if (tmp_data > 10) return;
	if (tmp_data % 3 == 0 || tmp_data == 4) {
		*t = NULL;
		tmp_data++;
	}
	else {
		*t = new _bitnode;
		if (!*t) return;
		(*t)->_data = tmp_data++;
		(*t)->_lchild = (*t)->_rchild = NULL;
		createBitTree(&(*t)->_lchild);
		createBitTree(&(*t)->_rchild);
	}
}

void Algorithm::preOrderTraverse(_bittree* t)
{
	if (*t == NULL) return;
	cout << (*t)->_data << "  ";
	preOrderTraverse(&(*t)->_lchild);
	preOrderTraverse(&(*t)->_rchild);
}

void Algorithm::inOrderTraverse(_bittree* t)
{
	if (*t == NULL) return;
	inOrderTraverse(&(*t)->_lchild);
	cout << (*t)->_data << "  ";
	inOrderTraverse(&(*t)->_rchild);
}

void Algorithm::postOrderTraverse(_bittree* t)
{
	if (*t == nullptr) return;
	postOrderTraverse(&(*t)->_lchild);
	postOrderTraverse(&(*t)->_rchild);
	cout << (*t)->_data << "  ";
}

bool Algorithm::searchBST(_bittree t, int key, _bittree f, _bittree* p)
{
	if (!t) {
		*p = f;
		return false;
	}
	else if (key == t->_data) {
		*p = t;
		return true;
	}
	else if (key < t->_data) {
		return searchBST(t->_lchild, key, t, p);
	}
	else {
		return searchBST(t->_rchild, key, t, p);
	}
}

bool Algorithm::insertBST(_bittree* t, int key)
{
	_bittree p = new _bitnode;
	_bittree s = new _bitnode;
	if (!searchBST(*t, key, NULL, &p)) {
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
	int a[10] = { 62, 88, 58, 47, 35, 28, 18, 99, 37, 9 };
	for (int i = 0; i < 10; i++) insertBST(_tree, a[i]);
}

bool Algorithm::_delete(_bittree* p)
{
	_bittree q = new _bitnode;
	_bittree s = new _bitnode;

	if ((*p)->_rchild == NULL) {
		q = *p;
		*p = (*p)->_lchild;
		delete q;
	}
	else if ((*p)->_lchild == NULL) {
		q = *p;
		*p = (*p)->_rchild;
		delete q;
	}
	else {
		q = *p;
		s = (*p)->_lchild;
		while (s->_rchild) {
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
	else {
		if (key == (*t)->_data)
			return _delete(t);
		else if (key < (*t)->_data)
			return deleteBST(&(*t)->_lchild, key);
		else
			return deleteBST(&(*t)->_rchild, key);
	}
}

bool Algorithm::initHashTable(_hashtable* _hash)
{
	_hash->_count = HASHSIZE;
	_hash->_elem = new int[HASHSIZE];
	for (int i = 0; i < HASHSIZE; i++) { _hash->_elem[i] = NULLKEY; }
	return true;
}

int Algorithm::hash(int key)
{
	return key % HASHSIZE;
}

void Algorithm::insertHash(_hashtable* _hash, int key)
{
	int addr = hash(key);
	while (_hash->_elem[addr] != NULLKEY) addr = (addr + 1) % HASHSIZE;
	_hash->_elem[addr] = key;
}

bool Algorithm::searchHash(_hashtable* _hash, int key, int* addr)
{
	*addr = hash(key);
	while (_hash->_elem[*addr] != key) {
		*addr = (*addr + 1) % HASHSIZE;
		if (*addr = (*addr + 1) == NULLKEY || *addr == hash(key)) return false;
	}
	return true;
}

/**************************算法************************************/

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

int Algorithm::sequebtialSearch(int* a, int n, int key)
{
	a[0] = key;
	int i = n;
	while (a[i] != key) { i--; }
	return i;
}

void Algorithm::binarySearch()
{
	// data
	int _a[10] = { 0, 1, 16, 24, 35, 44, 56, 72, 88, 91 };
	int _size = 10;
	int _key = 88;

	// search
	int _low = 1;
	int _high = _size;
	int _mid;
	while (_low <= _high) {
		//二分法，顺序数列
		_mid = (_high + _low) / 2;
		//插值法，适用于分部均匀的数列
		//_mid = (_high - _low) * (_key - _a[_low]) / (_a[_high] - _a[_low]);
		if (_key < _a[_mid])
			_high = _mid - 1;
		else if (_key > _a[_mid])
			_low = _mid + 1;
		else {
			cout << _mid << endl;
			return;
		}
	}
	cout << "无";
}

int Algorithm::successiveDivision(int a, int b)
{
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

bool Algorithm::primeNum(int a)
{
	int i = 2;
	for (; i < a; i++) {
		if (a % i == 0) return false;
	}
	if (i == a) return true;
}

void Algorithm::jitutonglong(int head, int leg)
{
	if (leg % 2 != 0)
		cout << "cuowu" << endl;
	else {
		int tuzi = leg / 2 - head;
		int ji = 2 * head - leg / 2;
		if (tuzi < 0 || ji < 0)
			cout << "cuowu" << endl;
		else
			cout << ji << "  " << tuzi << endl;
	}

	/**************************************/
	int i = 0;
	for (; i <= head; i++) {
		if (2 * i + 4 * (head - i) == leg) {
			cout << i << "  " << head - i << endl;
			break;
		}
	}
	if (i > head) cout << "cuowu" << endl;
}

void Algorithm::bubbleSort()
{
	int a[10] = { 9, 1, 5, 8, 3, 7, 4, 6, 2 };
	int length = 9;
	bool flag = true;  //优化

	for (int i = 0; i < length && flag; i++) {
		flag = false;  //优化
		for (int j = length - 1; j > i; j--) {
			if (a[j - 1] > a[j]) {
				int tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
				flag = true;  //优化
			}
		}
	}

	for (int i = 0; i < length; i++) { cout << a[i] << endl; }
}

void Algorithm::selectSort()
{
	int a[10] = { 9, 1, 5, 8, 3, 7, 4, 6, 2 };
	int length = 9;
	int min = 0;

	for (int i = 0; i < length; i++) {
		min = i;
		for (int j = i + 1; j < length; j++) {
			if (a[min] > a[j]) min = j;
		}
		if (min != i) {
			int tmp = a[i];
			a[i] = a[min];
			a[min] = tmp;
		}
	}
	for (int i = 0; i < length; i++) { cout << a[i] << endl; }
}

void Algorithm::insertSort()
{
	int a[11] = { 0, 9, 1, 5, 8, 3, 7, 4, 6, 2 };  // 0为新增哨兵
	int length = 10;
	int i, j;

	for (i = 2; i < length; i++) {
		if (a[i - 1] > a[i]) {
			a[0] = a[i];
			for (j = i - 1; a[j] > a[0]; j--) a[j + 1] = a[j];
			a[j + 1] = a[0];
		}
	}

	for (int i = 1; i < length; i++) { cout << a[i] << endl; }
}

void Algorithm::shellSort()
{
	int a[11] = { 0, 9, 1, 5, 8, 3, 7, 4, 6, 2 };  // 0为新增哨兵
	int length = 10;
	int i, j;

	int increment = length;  //增量

	while (increment > 1) {
		increment = increment / 3 + 1;
		for (i = increment + 1; i < length; i++) {
			if (a[i] < a[i - increment]) {
				a[0] = a[i];
				for (j = i - increment; j > 0 && a[0] < a[j]; j -= increment)
					a[j + increment] = a[j];
				a[j + increment] = a[0];
			}
		}
	}

	for (int i = 1; i < length; i++) { cout << a[i] << endl; }
}

void Algorithm::quickSort()
{
	int a[10] = { 9, 1, 5, 8, 3, 7, 4, 6, 2 };
	int length = 9;

	QSort(a, 0, length - 1);

	for (int i = 0; i < length; i++) { cout << a[i] << endl; }
}

void Algorithm::QSort(int* a, int low, int high)
{
	int pivot;
	if (low < high)  //优化，当数组较小是可以采用插值排序，加以判断
	{
		pivot = partition(a, low, high);
		QSort(a, low, pivot - 1);
		QSort(a, pivot + 1, high);
	}
}

int Algorithm::partition(int* a, int low, int high)
{
	int pivot_key;

	/***************优化pivot_key选择*******************/
	// int m = low + (high - low) / 2;
	// if (a[low] > a[high])
	//{
	//     int tmp1 = a[low];
	//     a[low] = a[high];
	//     a[high] = tmp1;
	// }
	// if (a[m] > a[high])
	//{
	//     int tmp1 = a[m];
	//     a[m] = a[high];
	//     a[high] = tmp1;
	// }
	// if (a[low] < a[m])
	//{
	//     int tmp1 = a[low];
	//     a[low] = a[m];
	//     a[m] = tmp1;
	// }

	pivot_key = a[low];
	// a[0] = pivot_key;//插值优化
	while (low < high) {
		while (low < high && a[high] >= pivot_key) high--;
		int tmp1 = a[low];
		a[low] = a[high];
		a[high] = tmp1;
		/*******************优化这里可以采用插值法替换，而不是交换**********************/
		//备份a[0]后 a[low] = a[high]; a[low] = a[0];
		while (low < high && a[low] <= pivot_key) low++;
		int tmp2 = a[low];
		a[low] = a[high];
		a[high] = tmp2;
	}
	return low;
}

/*****************************功能***********************************/

vector<string> Algorithm::stringSplit(string str, const string& split)
{
	vector<string> strlist;
	strlist.clear();

	if (str == "") return strlist;
	string strs = str + split;
	size_t pos = str.find(split);
	int steps = split.size();

	while (pos != strs.npos) {
		string temp = strs.substr(0, pos);
		strlist.push_back(temp);
		strs = strs.substr(pos + steps, strs.size());
		pos = strs.find(split);
	}
	return strlist;
}

void Algorithm::rangeCac(string length, string digits)
{
	auto rel = to_string(pow(10, atoi(length.c_str()) - atoi(digits.c_str()))
		- pow(0.1, atoi(digits.c_str())));
}

string Algorithm::doubleToCoord(double position)
{
	string rslt;
	int du = (int)position;
	rslt += to_string(du);
	int fen = (int)((position - du) * 60);
	rslt = rslt + "°" + to_string(fen) + "′";
	int miao = (int)(((position - du) * 60 - fen) * 60);
	rslt = rslt + to_string(miao) + "″";
	return rslt;
}

double Algorithm::coordToDouble(string position)
{
	double rslt;
	string tmp = position.substr(1, position.size() - 1);
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

void Algorithm::detToHex(int dec)
{
	int j = 0;
	int tmp = dec;
	string hex;
	while (dec)
	{
		dec /= 16;
		j++;
	}
	for (int i = 0; i < j; i++)
	{
		int rem = tmp % 16;
		tmp /= 16;

		if (rem >= 0 && rem <= 9)
		{
			hex.insert(0, 1, rem + '0');
		}
		else if (rem >= 10 && rem <= 15)
		{
			hex.insert(0, 1, rem + 'A' - 10);
		}
	}
	cout << hex << endl;
}

void Algorithm::encryption()
{
	string txt;
	cin >> txt;

	if (!txt.empty())
	{
		for (int i = 0; i < txt.size(); i++)
		{
			txt[i] ^= 3;
		}
	}
	cout << txt << endl;
}

void Algorithm::mapAndUnmap()
{
	map<int, int> p1;
	unordered_map<int, int> p2;
	p1[0] = 1;
	p1[4] = 5;
	p1[3] = 4;
	p2[0] = 1;
	p2[4] = 5;
	p2[3] = 4;

	p1[4] = 2;
	p2[4] = 2;

	map<int, int>::iterator it1 = p1.begin();
	unordered_map<int, int>::iterator it2 = p2.begin();
	while (it1 != p1.end()) {
		cout << it1->first << " " << it1->second << endl;
		it1++;
	}
	while (it2 != p2.end()) {
		cout << it2->first << " " << it2->second << endl;
		it2++;
	}


}

////////////////////////////////// EOF /////////////////////////////////////////
