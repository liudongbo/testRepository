// Introduction_To_Algorithms.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Algorithms.h"

int main()
{
	int a[] = { 6,5,4,67,8,2,21,10 };
	int gujia[16] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	Algorithms algo;
	//algo.Insert_Sort(a,8);
	int test[] = { -2,-8,-1,-5,-9 };
	cout <<algo.Find_Max_Crossing_Subarray(test, 0, 2, 4);
    return 0;
}

