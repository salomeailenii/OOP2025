#include <iostream>
#include "Canva.h"

int main() {
    Canvas myCanvas(20, 10);

    myCanvas.DrawRect(2, 2, 15, 7, '#');

    myCanvas.FillRect(4, 3, 13, 6, '*');

    myCanvas.DrawCircle(10, 5, 3, 'O');

    myCanvas.FillCircle(17, 5, 2, '@');

    myCanvas.DrawLine(1, 1, 18, 8, '+');

    myCanvas.SetPoint(5, 5, '@');

    myCanvas.Print();
	return 0;
}