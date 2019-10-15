#pragma once
#include <vector>
#include <stack>
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