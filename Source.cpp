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
    char l[256];
    int suma = 0;

    fptr = fopen("in.txt", "r");

    while (fgets(l, sizeof(l), fptr))
    {
        int sum = 0;
        char* p = l;

        while (*p)
        {
            if (*p >= '0' && *p <= '9')
            {
                sum += numar(p);
                while (*p >= '0' && *p <= '9')
                    p++; 
            }
            else
            {
                p++;
            }
        }
        suma += sum;
    }

    fclose(fptr);

    printf("%d\n", suma);
    return 0;

}

// problema 2

int nrLitere(char* cuv)
{
    int nr = 0;
    while (cuv[nr] != '\0')
        nr++;
    return nr;
}

int main()
{
    char text[256];
    char* aux[20];
    int lg[20], nr = 0;
    scanf(" %[^\n]", text);
    char* p = strtok(text, " ");
    while (p) {
        aux[nr] = p;
        lg[nr] = nrLitere(p);
        nr++;
        p = strtok(NULL, " ");
    }

    for( int i = 0; i < nr -1; i++)
        for (int j = i + 1; j < nr; j++) {
            if (lg[i] < lg[j])
            {
                int auxx = lg[i];
                lg[i] = lg[j];
                lg[j] = auxx;
                char* auxcuv = aux[i];
                aux[i] = aux[j];
                aux[j] = auxcuv;
            }
        }
    for (int i = 0; i < nr; i++)
        printf("%s\n", aux[i]);
}

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
