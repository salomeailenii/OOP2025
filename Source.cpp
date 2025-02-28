#include <iostream>
#include <stdio.h>
using namespace std;

// problema 1

int numar(char* x)
{
    int r = 0, i;
    while (x[i] += '0' && x[i] <= '9')
    {
        r = r * 10 + (x[i] - '0');
        i++;
    }
    return r;

}

int main()
{
    FILE* fptr;
    fptr = fopen("ini.txt", "r");
    while 



}

// problema 2

// problema 3

bool isPrime(int n)
{
    for (int tr = 2; tr < n / 2; tr++)
        if ((n % tr) == 0)
            return false;
    return true;
}
int main()
{
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;
    if (isPrime(n))
        std::cout << n << " is prime !";
    else
        std::cout << n << " is NOT prime !";
    return 0;
}