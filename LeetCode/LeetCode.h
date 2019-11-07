#pragma once
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

#include "Base.h"
using namespace std;
// Definition for a binary tree node.

vector<int> result;
vector<int> inorderTraversal(TreeNode* root) {
	// �ݹ����

	if (root == nullptr)
	{
		return result;
	}
	inorderTraversal(root->left);
	result.push_back(root->val);
	inorderTraversal(root->right);
	return result;


	// ��������

	vector<int> result;
	stack<TreeNode*> Stack;
	while (root != nullptr || !Stack.empty())
	{
		// �����ӽڵ�ȫ����ջ
		while (root != nullptr)
		{
			Stack.push(root);
			root = root->left;
		}
		if (!Stack.empty())
		{
			root = Stack.top(); // ȡջ��Ԫ��
			Stack.pop();  // ��ջ
			result.push_back(root->val);
			root = root->right;  
		}
	}
	return result;
}
string decodeString(string s) {
	// ����������
	// s = "3[a]2[bc]", ���� "aaabcbc".
	// s = "3[a2[c]]", ���� "accaccacc".
	// s = "2[abc]3[cd]ef", ���� "abcabccdcdcdef".
	string str;
	stack<string> substrs;
	stack<int>  times;
	bool start = false;
	for (size_t i = 0,length = s.size(); i < length; i++)
	{
		if (isdigit(s[i]))  // Ϊ������ѹ�����ջ
		{
			// �������ִ�С
			int num = s[i] - '0';
			i++;
			while (isdigit(s[i]))
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			i--;
			times.push(num);
		}
		else if (s[i] == '[') // Ϊ'['��ʼ��¼�ַ���������֮ǰ�Ĵ����ַ���ջ��
		{
			substrs.push(str);
			str.clear();
		}
		else if (s[i] == ']') // Ϊ']'���ߵ�����������ü���ջ��չ����ǰ�ַ���
		{
			string &newstr = substrs.top();
			// �ظ������Ż�
			for (size_t i = 0,length = times.top(); i < length; i++)
			{
				newstr += str;
			}
			str = newstr;
			substrs.pop();
			times.pop();
		}
		else

		{
			str += s[i];
		}
		
	}
	return str;
}


// ��������
int pivoIndex(vector<int>& nums)
{
	// ��ʼ��
	int left = 0, suml = 0;
	int right = nums.size() - 1, sumr = 0;
	int result = -1;
	int sum = 0;
	for (size_t i = 0, length = nums.size(); i < length; i++)
	{
		sum += nums[i];
	}
	for (size_t i = 0, length = nums.size(); i < length; i++)
	{
		// ����ܺͣ�����������ֵ
		if (i != 0)
		{
			suml += nums[i - 1];
		}
		// �ұ��ܺ�=�ܺͼ�ȥ����뱾��ֵ
		sumr = sum - suml - nums[i];
		if (suml == sumr)
		{
			return i;
		}
	}
	return -1;
}
ListNode * addTwoNumbers(ListNode * l1, ListNode * l2)
{
	ListNode* ret = new ListNode(0);
	ListNode* now = ret;
	// ��¼��ǰ�ڵ��ǰ��
	ListNode* pre = nullptr;
	int num1;
	int num2;
	// ��¼��λ
	bool carry = false;
	while (l1 != nullptr || l2 != nullptr)
	{
		// ȡֵ
		if (l1 == nullptr)
		{
			num1 = 0;
		}
		else
		{
			num1 = l1->val;
			l1 = l1->next;
		}
		if (l2 == nullptr)
		{
			num2 = 0;
		}
		else
		{
			num2 = l2->val;
			l2 = l2->next;
		}
		ListNode*nowNode = new ListNode(0);
		now->val = (num1 + num2 + carry) % 10;
		now->next = nowNode;
		pre = now;
		now = now->next;
		carry = (num1 + num2 + carry) / 10;
	}
	if (carry == true)
	{
		now->val = 1;
	}
	else
	{
		delete now;
		pre->next = nullptr;
	}
	return ret;
}