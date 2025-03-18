#include "Sort.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

Sort::Sort(int n, int minim, int maxim)
{
	nr = n;
	
	for (int i = 0; i < n; i++)
		list[i] = minim + (rand() % (maxim - minim + 1));
}

Sort::Sort(int vector[100], int n)
{
	nr = n;
	for (int i = 0; i < nr; i++)
		list[i] = vector[i];
}

Sort::Sort(int n, ...)
{
	va_list args;
	va_start(args, n);
	nr = n;
	int i = 0;
	while (n)
	{
		list[i] = va_arg(args, int);
		i++;
		n--;
	}
	va_end(args);
}

Sort::Sort(const char string[100])
{
	nr = 0;
	int lungime = strlen(string);
	int i = 0;
	int aux = 0;
	while (i < lungime)
	{
		if (string[i] != ',')
			aux = aux * 10 + (string[i] - '0');
		else
		{
			list[nr] = aux;
			nr++;
			aux = 0;
		}
		i++;
	}
	list[nr] = aux;
	nr++;
}

void Sort::InsertSort(bool ascendent) // compar fiecare element i cu elementul j si il mut
{
	int aux, j;
	for (int i = 1; i < nr; i++)
	{
		aux = list[i];
		j = i - 1;

		while (j >= 0 && (ascendent ? list[j] > aux : list[j] < aux))
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = aux;
	}
}

int partitie(int list[], int left, int right, bool ascendent)
{
	int pivot = list[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
		if (ascendent ? list[j] < pivot : list[j] > pivot)
			swap(list[++i], list[j]);
	swap(list[i + 1], list[right]);
	return i + 1;
}

void DoQuickSort(int list[], int left, int right, bool ascendent)
{
	if (left < right) {
		int mij = partitie(list, left, right, ascendent);
		DoQuickSort(list, left, mij - 1, ascendent);
		DoQuickSort(list, mij + 1, right, ascendent);
	}
}

void Sort::QuickSort(bool ascendent) // alegem pivotul si comparam asa pe fiecare
{
	DoQuickSort(list, 0, nr - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent) // ducem cel mai mare la final
{
	for (int i = 0; i < nr - 1; i++)
		for (int j = 0; j < nr - i - 1; j++)
			if (ascendent ? list[j] > list[j + 1] : list[j] < list[j + 1])
				swap(list[j], list[j + 1]);
	ascendent = true;
}

void Sort::Print()
{
	for (int i = 0; i < nr; i++)
		cout << list[i] << " ";
}

int Sort::GetElementsCount() // nr de elemente din lista
{
	return nr;
}

int Sort::GetElementFromIndex(int index) // elementul de pe pozitia index
{
	return list[index];
}
