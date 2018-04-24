#pragma once
class Algorithms
{
public:
	Algorithms();
	~Algorithms();
public:
	int Find_Max_InThree(int a, int b, int c);

	void Insert_Sort(int *array, int length);

	int Find_Max_Crossing_Subarray(int *a, int low, int mid, int high);

};