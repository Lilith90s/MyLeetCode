#pragma once
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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