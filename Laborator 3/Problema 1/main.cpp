#include <iostream>
#include "Math.h"

using namespace std;

int main() {
	Math x;
	cout << x.Add(3, 5) << endl;
	cout << x.Add(3, 5, 2) << endl;
	cout << x.Add(3.5, 5.1) << endl;
	cout << x.Add(3.3, 5.1, 2.2) << endl;
	cout << x.Mul(3, 5) << endl;
	cout << x.Mul(3, 5, 2) << endl;
	cout << x.Mul(3.5, 5.1) << endl;
	cout << x.Mul(3.5, 5.1, 2.2) << endl;
	cout << x.Add(7, 2, 3, 4, 5, 6, 7, 3) << endl;
	cout << x.Add("3", "5") << endl;
	return 0;
}