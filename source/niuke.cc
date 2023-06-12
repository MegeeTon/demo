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

#include <iostream>

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
	test();
}

NIUKE::~NIUKE() {}
////////////////////////////////////////////////////////////////////////////////
// Functions
//

void NIUKE::test()
{
	string a = "0123456789";
	cout << a[1] << endl;

}

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

NIUKE::TreeNode* NIUKE::Mirror(TreeNode* pRoot) {
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

bool NIUKE::intree(TreeNode* left, TreeNode* right)
{
	if (left == nullptr && right == nullptr)
		return true;
	if (left == nullptr || right == nullptr || left->val != right->val)
		return false;

	return intree(left->left, right->right) && intree(left->right, right->left);
}


bool NIUKE::isSymmetrical(TreeNode* pRoot) {
	if (!pRoot)
		return true;

	return intree(pRoot->left, pRoot->right);
}

vector<int> NIUKE::printMatrix(vector<vector<int> > matrix) {
	if (matrix.empty())
		return vector<int>(NULL);

	int virx = matrix.size() - 1;
	int horx = matrix[0].size() - 1;
	int virn = 0;
	int horn = 0;

	vector<int> rslt;

	while (virn <= virx && horn <= horx)
	{
		for (int i = horn; i <= horx; i++)
			rslt.push_back(matrix[virn][i]);
		virn++;
		if (virn > virx)
			break;

		for (int i = virn; i <= virx; i++)
			rslt.push_back(matrix[i][horx]);
		horx--;
		if (horn > horx)
			break;

		for (int i = horx; i >= horn; i--)
			rslt.push_back(matrix[virx][i]);
		virx--;
		if (virn > virx)
			break;

		for (int i = virx; i >= virn; i--)
			rslt.push_back(matrix[i][horn]);
		horn++;
		if (horn > horx)
			break;
	}
	return rslt;
}



void NIUKE::push1(int value) {
	mstack.push(value);

	if (minstack.empty() || minstack.top() > value)
		minstack.push(value);
	else if (minstack.top() <= value)
		minstack.push(minstack.top());
}
void NIUKE::pop1() {
	mstack.pop();
	minstack.pop();
}
int NIUKE::top() {
	return mstack.top();
}
int NIUKE::minu() {
	return minstack.top();
}

vector<int> NIUKE::PrintFromTopToBottom(TreeNode* root) {
	queue<TreeNode*> mqueue;
	vector<int> rslt;

	if (!root)
		return rslt;

	mqueue.push(root);
	rslt.push_back(root->val);

	while (!mqueue.empty())
	{
		if (mqueue.front()->left)
		{
			mqueue.push(mqueue.front()->left);
			rslt.push_back(mqueue.front()->left->val);
		}
		if (mqueue.front()->right)
		{
			mqueue.push(mqueue.front()->right);
			rslt.push_back(mqueue.front()->right->val);
		}
		mqueue.pop();
	}
	return rslt;
}

int NIUKE::MoreThanHalfNum_Solution(vector<int> numbers) {
	int size = numbers.size();
	if (size == 0)
		return -1;
	unordered_map<int, int> tmp;
	for (int i = 0; i < size; i++)
		tmp[numbers[i]]++;
	for (int i = 0; i < size; i++)
	{
		if (tmp[numbers[i]] > size / 2)
			return numbers[i];
	}
	return -1;
}

int NIUKE::FindGreatestSumOfSubArray(vector<int> array) {

	int size = array.size();
	if (size == 1)
		return array[0];
	vector<int> max_array(size,0);
	int rslt = array[0];
	max_array[0] = array[0];
	for (int i = 1; i < size; i++)
	{
		if (max_array[i - 1] > 0)
			max_array[i] = max_array[i - 1] + array[i];
		else
			max_array[i] = array[i];
		rslt = max(max_array[i], rslt);
	}
	return rslt;
}

int NIUKE::findNthDigit(int n) {
	// write code here
	if (n < 10)
		return n;

	long long weishu = 1;
	long long geshu = 1;
	long long count = 9;
	while (n > count)
	{
		n -= count;
		weishu *= 10;
		geshu++;
		count = 9 * (weishu) * (geshu);
	}
	long long num = weishu + (n - 1) / geshu;
	long long rslt_weishu = (n - 1) % geshu;
	return to_string(num)[rslt_weishu] - '0';
}

////////////////////////////////// EOF /////////////////////////////////////////
