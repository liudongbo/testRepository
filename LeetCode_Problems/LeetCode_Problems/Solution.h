#pragma once
#include "stdafx.h"
class Solution
{
public:
	Solution();
	~Solution();
public:
	int findMin(vector<string>& strs);
//Easy +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
public:
	//Easy
	//1. Two Sum  
	vector<int> twoSum(vector<int>& nums, int target); 

	//Easy
	//7. Reverse Integer  
	int reverse(int x);

	//Medium
	//8. String to Integer (atoi)     
	int maxNums = 10;
	string strINT_MAX = "2147483647";
	string strINT_MIN = "2147483648";
	int CheckAndTurn(string strFinal, int zeroOrone, bool isPositive);
	int myAtoi(string str);

	//Easy
	//9. Palindrome Number
	bool isPalindrome(int x);

	//Easy
	//13. Roman to Integer  
	int romanToInt(string s);

	//Easy
	//14. Longest Common Prefix
	string longestCommonPrefix(vector<string>& strs);

	//Easy
	//20. Valid Parentheses
	bool isValid(string s);

	//Easy
	//21. Merge Two Sorted Lists
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

