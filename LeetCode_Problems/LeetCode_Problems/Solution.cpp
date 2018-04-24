#include "stdafx.h"
#include "Solution.h"


Solution::Solution()
{
}


Solution::~Solution()
{
}


int Solution::findMin(vector<string>& strs)
{
	int min = INT_MAX;
	for (int i = 0; i < strs.size(); i++)
	{
		if (strs[i].size() < min)
			min = strs[i].size();
	}
	return min;
}
//1. Two Sum
vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	vector<int> results;
	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums.at(i) + nums.at(j) == target)
			{
				results.push_back(i);
				results.push_back(j);
				return results;
			}
		}
	}
	return results;
}
//7. Reverse Integer
int Solution::reverse(int x) {
	int temp = x;
	int results = 0;
	bool isPositive = true;
	vector<int > input;
	if (temp < 0)
	{
		isPositive = false;
		temp *= (-1);
	}
	while (temp != 0)
	{
		input.push_back(temp % 10);
		temp /= 10;
	}
	for (int i = 0; i < input.size(); i++)
	{
		results += input[i] * pow(10, input.size() - i - 1);
		if (results < 0)
			return 0;
	}
	input.clear();
	if (isPositive) return results;
	else return (-1) * results;
}
//8. String to Integer (atoi)
int Solution::CheckAndTurn(string strFinal, int zeroOrone, bool isPositive)
{
	int i;
	int Sum = 0;
	if (strFinal.size() == maxNums + zeroOrone)
	{
		i = zeroOrone;
		if (isPositive)
		{
			while (i < maxNums + zeroOrone)
			{
				if (strFinal[i] > strINT_MAX[i - zeroOrone])
					return INT_MAX;
				else if (strFinal[i] < strINT_MAX[i - zeroOrone])
					break;
				else
					i++;
			}
		}
		else {
			while (i < maxNums + zeroOrone)
			{
				if (strFinal[i] > strINT_MIN[i - zeroOrone])
					return INT_MIN;
				else if (strFinal[i] < strINT_MIN[i - zeroOrone])
					break;
				else
					i++;
			}
		}
	}
	for (i = zeroOrone; i < strFinal.size(); i++)
	{
		int u = 1;
		int j = strFinal.size() - i - 1;
		while (j != 0)
		{
			u *= 10;
			j--;
		}
		Sum += (strFinal[i] - '0') * u;
	}
	if (isPositive)
		return Sum;
	else
		return (-1) * Sum;
}
int Solution::myAtoi(string str) {
	if (str.size() == 0) return 0;
	else {
		int i = 0;
		int Sum = 0;
		bool isPositive = true;
		int coutAddSub = 0;
		string strFinal = "";
		while (i < str.size())
		{
			if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-') && str[i] != ' ')
				return 0;
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
			{
				strFinal += str[i++];
				if (str[i] == '+' || str[i] == '-')
					coutAddSub++;
				break;
			}
			i++;
		}
		while (i < str.size())
		{
			//if( !((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-') )
			//	break;

			if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
			{
				if (str[i] == '+' || str[i] == '-')
					coutAddSub++;
				if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
					strFinal += str[i];
				i++;
			}
			else
				break;
		}
		if (coutAddSub > 1) return 0;
		if (strFinal[0] == '+')
		{
			if (strFinal.size() > maxNums + 1)
				return INT_MAX;
			else if (strFinal.size() > 1 && strFinal.size() <= maxNums + 1)
				return CheckAndTurn(strFinal, 1, isPositive);
			else
				return 0;
		}
		else if (strFinal[0] == '-')
		{
			if (strFinal.size() > maxNums + 1)
				return INT_MIN;
			else if (strFinal.size() > 1 && strFinal.size() <= maxNums + 1)
				return CheckAndTurn(strFinal, 1, !isPositive);
			else
				return 0;
		}
		else
		{
			if (strFinal.size() > maxNums)
				return INT_MAX;
			else if (strFinal.size() > 0 && strFinal.size() <= maxNums)
				return CheckAndTurn(strFinal, 0, isPositive);
			else
				return 0;
		}
	}
}

//9. Palindrome Number
bool Solution::isPalindrome(int x) {
	if (x < 0)
		return false;
	string input = to_string(x);
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] != input[input.size() - i - 1])
			return false;
	}
	return true;
}
//13. Roman to Integer
int Solution::romanToInt(string s)
{
	int result = 0;
	map<char, int> dict;
	dict['I'] = 1;
	dict['V'] = 5;
	dict['X'] = 10;
	dict['L'] = 50;
	dict['C'] = 100;
	dict['D'] = 500;
	dict['M'] = 1000;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (i + 1 < s.size() && dict[s[i]] < dict[s[i+1]])
		{
			result += (dict[s[i + 1]] - dict[s[i]]);
			i++;
		}
		else {
			result += dict[s[i]];
		}
	}
	return result;
}

//14. Longest Common Prefix
string Solution::longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
		return "";
	string prefix = "";
	int commCount = 0;
	int minLen = findMin(strs);
	bool flag = true;
	for (size_t i = 0; i < minLen; i++)
	{
		for (size_t j = 0; j < strs.size() - 1; j++)
		{
			if (strs[j][i] != strs[j + 1][i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			commCount++;
	}
	return strs[0].substr(0, commCount);
}

//20. Valid Parentheses
bool Solution::isValid(string s)
{
	if (s.empty())
		return true;
	vector<char> input;
	input.push_back(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (input.empty())
			input.push_back(s[i]);
		else if (abs(s[i] - input[input.size() - 1]) <= 2 && abs(s[i] - input[input.size() - 1]) > 0)
			input.pop_back();
		else
			input.push_back(s[i]);
	}
	if (input.empty())
		return true;
	return false;
}

ListNode * Solution::mergeTwoLists(ListNode * l1, ListNode * l2)
{
	if (l1 == NULL && l2 == NULL)
		return NULL;
	else if (l1 == NULL && l2 != NULL)
		return l2;
	else
		return l1;

	for (int )
	{
	}
	
}
