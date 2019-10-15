#pragma once
#include <stack>

/*基于栈实现队列的功能*/
using namespace std;
class MyQueue
{
public:
	stack<int> s;
	MyQueue() {};
	void push(int x) {
		s.push(x);
	}
	int pop() {
		stack<int> temp;
		// 反转
		while (!s.empty())
		{
			temp.push(s.top());
			s.pop();
		}
		// 取temp栈顶元素，即s栈底元素，即队列首部
		auto ret = temp.top();
		// 删除
		temp.pop();

		// 再反转一次
		while (!temp.empty())
		{
			s.push(temp.top());
			temp.pop();
		}
		return ret;
	}
	int peek() {
		stack<int> temp;
		// 反转
		while (!s.empty())
		{
			temp.push(s.top());
			s.pop();
		}
		// 取temp栈顶元素，即s栈底元素，即队列首部
		auto ret = temp.top();

		// 再反转一次
		while (!temp.empty())
		{
			s.push(temp.top());
			temp.pop();
		}
		return ret;
	}
	bool empty() {
		return s.empty();
	}
};

