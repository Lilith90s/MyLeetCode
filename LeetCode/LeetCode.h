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
	// 递归遍历

	if (root == nullptr)
	{
		return result;
	}
	inorderTraversal(root->left);
	result.push_back(root->val);
	inorderTraversal(root->right);
	return result;


	// 迭代遍历

	vector<int> result;
	stack<TreeNode*> Stack;
	while (root != nullptr || !Stack.empty())
	{
		// 将左子节点全部入栈
		while (root != nullptr)
		{
			Stack.push(root);
			root = root->left;
		}
		if (!Stack.empty())
		{
			root = Stack.top(); // 取栈顶元素
			Stack.pop();  // 出栈
			result.push_back(root->val);
			root = root->right;  
		}
	}
	return result;
}
string decodeString(string s) {
	// 测试用例：
	// s = "3[a]2[bc]", 返回 "aaabcbc".
	// s = "3[a2[c]]", 返回 "accaccacc".
	// s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
	string str;
	stack<string> substrs;
	stack<int>  times;
	bool start = false;
	for (size_t i = 0,length = s.size(); i < length; i++)
	{
		if (isdigit(s[i]))  // 为数字则压入计数栈
		{
			// 计算数字大小
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
		else if (s[i] == '[') // 为'['则开始记录字符串，并将之前的存入字符串栈中
		{
			substrs.push(str);
			str.clear();
		}
		else if (s[i] == ']') // 为']'或者到达结束，则用计数栈顶展开当前字符串
		{
			string &newstr = substrs.top();
			// 重复，可优化
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

// 中心索引
int pivoIndex(vector<int>& nums)
{
	// 初始化
	int left = 0,suml = 0;
	int right = nums.size() - 1, sumr = 0;
	int result = -1;
	int sum = 0;
	for (size_t i = 0,length = nums.size(); i < length; i++)
	{
		sum += nums[i];
	}
	for (size_t i = 0,length = nums.size(); i < length; i++)
	{
		// 左边总和，不包含本次值
		if (i != 0)
		{
			suml += nums[i-1];
		}
		// 右边总和=总和减去左边与本次值
		sumr = sum - suml - nums[i];
		if (suml == sumr)
		{
			return i;
		}
	}
	return -1;
}