// Palindrome_Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include <iostream>
using namespace std;
bool isPalindrome(int x);
int main()
{
    return 0;
}

bool isPalindrome(int x) {
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