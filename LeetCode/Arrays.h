#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//��дһ���㷨����M �� N������ĳ��Ԫ��Ϊ0���������ڵ����������㡣
void setZeroes(vector<vector<int>>& matrix) 
{
	set<int> row; // �������û�����
	set<int> col;// �������û�����
	for (size_t i = 0,length = matrix.size(); i < length; i++)
	{
		for (size_t j = 0,length = matrix[i].size(); j < length; j++)
		{
			if (matrix[i][j] == 0)
			{
				// ���ϱ��
				row.insert(i);
				col.insert(j);
			}
		}
	}
	// ����0
	for (auto i : row)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			matrix[i][j] = 0;
		}
	}
	// ����0
	for (auto j : col)
	{
		for (size_t i = 0; i < matrix.size(); i++)
		{
			matrix[i][j] = 0;
		}
	}
}

// �����ǰ׺
string longestCommonPrefix(vector<string>& strs) {
	string ret = "";
	if (strs.size()==0)
	{
		return ret;
	}
	// ����ַ�������
	size_t min_size = strs[0].size();
	//for (size_t i = 1,length = strs.size(); i < length; i++)
	//{
	//	if (min_size > strs[i].size())
	//	{
	//		min_size = strs[i].size();
	//	}
	//}
	
	min_size = (*min_element(strs.begin(), strs.end(), [](string& x, string& y) {return x.size() < y.size(); })).size();;
	size_t strs_size = strs.size();
	for (size_t j = 0; j < min_size; j++)
	{
		bool flag = true;
		for (size_t i = 1; i < strs_size; i++)
		{
			if (strs[i][j] != strs[0][j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ret += strs[0][j];
		}
		else
		{
			break;
		}
	}

	return ret;
}
// ������Ӵ�
string longestPalindrome(string s) {

}