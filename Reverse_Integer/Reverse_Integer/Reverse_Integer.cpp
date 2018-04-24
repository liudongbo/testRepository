// Reverse_Integer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "iostream"
using namespace std;


int reverse(int x);
int main()
{
	cout << reverse(1534236469) << endl;
					2147483648
    return 0;
}

int reverse(int x) {
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