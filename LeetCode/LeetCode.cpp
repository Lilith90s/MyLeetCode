// LeetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "LeetCode.h"
#include "MyQueueByStack.h"
template<typename T>
void debug(T arg)
{
#ifdef _DEBUG
	cout << arg << endl;
#endif // DEBUG
}
void test_inorderTraversal()
{
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	n1->right = n2;
	n2->left = n3;
	auto result = inorderTraversal(n1);
	for (auto e : result)
	{
		cout << e << endl;
	}
}
void test_MyQueueByStack()
{
	MyQueue test;
	test.push(1);
	test.push(2);
	debug(test.peek());
	debug(test.pop());
	test.empty();
}
void test_decodeString() { 
	string result = decodeString("3[a]2[bc]");
	cout << result << endl;
}
void test_pivoIndex() {
	vector<int> arg1{ 1,7,3,6,5,6 };
	vector<int> arg2{ -1,-1,-1,0,1,1};
	cout << pivoIndex(arg2) << endl;
}
int main()
{
	//test_inorderTraversal();
	//test_MyQueueByStack();
	// test_decodeString();
	test_pivoIndex();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
