#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList x;
	x.Init();
	x.Add(7);
	x.Add(2);
	x.Add(9);
	x.Add(4);
	x.Sort();
	cout << "Lista sortata: ";
	x.Print();


	return 0;
}