#include "stdafx.h"
#include "Algorithms.h"


Algorithms::Algorithms()
{
}


Algorithms::~Algorithms()
{
}

int Algorithms::Find_Max_InThree(int a, int b, int c)
{
	if (a >= b && a >= c)
		return a;
	else if (b >= a && b >= c)
		return b;
	else return c;
}

void Algorithms::Insert_Sort(int * array,int length)
{
	for (int i = 1; i < length; i++)
	{
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

int Algorithms::Find_Max_Crossing_Subarray(int * a, int low, int mid, int high)
{
	int left_sum = INT_MIN;
	int sum = 0;
	int max_left = mid;
	for (int i = mid; i >= low; i--)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = INT_MIN;
	sum = 0;
	int max_right = mid + 1;
	for (int i = mid+1; i <= high; i++)
	{
		sum += a[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	return Find_Max_InThree(left_sum, right_sum, left_sum + right_sum);
}