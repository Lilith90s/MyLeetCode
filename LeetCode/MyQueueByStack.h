#pragma once
#include <stack>

/*����ջʵ�ֶ��еĹ���*/
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
		// ��ת
		while (!s.empty())
		{
			temp.push(s.top());
			s.pop();
		}
		// ȡtempջ��Ԫ�أ���sջ��Ԫ�أ��������ײ�
		auto ret = temp.top();
		// ɾ��
		temp.pop();

		// �ٷ�תһ��
		while (!temp.empty())
		{
			s.push(temp.top());
			temp.pop();
		}
		return ret;
	}
	int peek() {
		stack<int> temp;
		// ��ת
		while (!s.empty())
		{
			temp.push(s.top());
			s.pop();
		}
		// ȡtempջ��Ԫ�أ���sջ��Ԫ�أ��������ײ�
		auto ret = temp.top();

		// �ٷ�תһ��
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

