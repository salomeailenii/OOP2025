#pragma once
class Sort
{
	int list[100], nr;

public:
	Sort(int n, int minim, int maxim); //create the list that needs to be sorted out of random values within a specific interval (min, max) O
	Sort(int vector[100], int n); //create the list that needs to be sorted from an existing vector O
	Sort(int n,...); //create the list that needs to be sorted using variadic parameters O
	Sort(const char string[100]); //create the list that needs to be sorted from a string O

	void InsertSort(bool ascendent = false); // O
	void QuickSort(bool ascendent = false); // O
	void BubbleSort(bool ascendent = false); // O
	void Print(); // O
	int GetElementsCount(); // O
	int GetElementFromIndex(int index); // O
};

