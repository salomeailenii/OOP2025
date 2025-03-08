#include <iostream>
#include "Student.h"
#include "Compara.h"

using namespace std;

int main()
{
	Student x1, x2;
	x1.setName("Adela Nicoleta");
	x1.setNotaMate(9.5f);
	x1.setNotaEngl(8.0f);
	x1.setNotaIsto(8.0f);

	x2.setName("Andrei Matei");
	x2.setNotaMate(7.5f);
	x2.setNotaEngl(7.0f);
	x2.setNotaIsto(8.0f);

	cout << x1.getName() <<" "<< x1.getMedie() << endl;
	cout << x2.getName() <<" "<< x2.getMedie() << endl;

	cout << comparaNume(x1, x2) << endl;
	cout << comparaMate(x1, x2) << endl;
	cout << comparaEngl(x1, x2) << endl;
	cout << comparaIsto(x1, x2) << endl;
	cout << comparaMedie(x1, x2) << endl;


}