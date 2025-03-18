#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
    Sort test1(5, 9, 20); // Sort(int n, int minim, int maxim)
    test1.Print();
    cout << endl;
    test1.BubbleSort(false);
    test1.Print();
    cout << endl;

    int v[] = { 10, 3, 7, 2, 11, 5 }; 
    Sort test2(v, 6); // Sort(int vector[100], int n)
    cout << endl;
    test2.Print();
    cout << endl;
    test2.InsertSort(false);
    test2.Print();
    cout << endl;

    Sort test3(5, 2, 3, 10, 1, 9); // Sort(int n,...)
    cout << endl;
    test3.Print();
    cout << endl;
    test3.QuickSort(false);
    test3.Print();
    cout << endl;

    Sort test4("10,40,100,5,70"); // Sort(const char string[100])
    cout << endl;
    test4.Print();
    cout << endl;
    test4.InsertSort(false);
    test4.Print();
    cout << endl;
}