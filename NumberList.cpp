#include "NumberList.h"
#include <iostream>
#include <algorithm>

using namespace std;

void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count++] = x;
	return true;
	
}

void NumberList::Sort()
{
	/*
	for( int i = 1; i < count; i++)
		for( int j = i+1; j <= count ; j++)
			if (numbers[j] < numbers[i])
			{
				int aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
	*/
	sort(numbers, numbers + count);
}

void NumberList::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << numbers[i]<< " ";
	}
}
