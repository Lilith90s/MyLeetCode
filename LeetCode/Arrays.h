#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
void setZeroes(vector<vector<int>>& matrix) 
{
	set<int> row; // 标记行有没有清空
	set<int> col;// 标记列有没有清空
	for (size_t i = 0,length = matrix.size(); i < length; i++)
	{
		for (size_t j = 0,length = matrix[i].size(); j < length; j++)
		{
			if (matrix[i][j] == 0)
			{
				// 加上标记
				row.insert(i);
				col.insert(j);
			}
		}
	}
	// 行置0
	for (auto i : row)
	{
		for (size_t j = 0; j < matrix[i].size(); j++)
		{
			matrix[i][j] = 0;
		}
	}
	// 列置0
	for (auto j : col)
	{
		for (size_t i = 0; i < matrix.size(); i++)
		{
			matrix[i][j] = 0;
		}
	}
}

// 最长公共前缀
string longestCommonPrefix(vector<string>& strs) {
	string ret = "";
	if (strs.size()==0)
	{
		return ret;
	}
	// 最短字符串长度
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
// 最长回文子串
string longestPalindrome(string s) {

}