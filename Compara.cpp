#include "Compara.h"
#include <string>

int comparaNume(const Student& x1, const Student& x2)
{
    if (x1.getName() == x2.getName())
        return 0;
    if (x1.getName() > x2.getName())
        return 1;
    else
        return -1;
}

int comparaMate(const Student& x1, const Student& x2)
{
    if (x1.getNotaMate() == x2.getNotaMate())
        return 0;
    if (x1.getNotaMate() > x2.getNotaMate())
        return 1;
    else
        return -1;
}

int comparaEngl(const Student& x1, const Student& x2)
{
    if (x1.getNotaEngl() == x2.getNotaMate())
        return 0;
    if (x1.getNotaEngl() > x2.getNotaEngl())
        return 1;
    else
        return -1;
}

int comparaIsto(const Student& x1, const Student& x2)
{
    if (x1.getNotaIsto() == x2.getNotaIsto())
        return 0;
    if (x1.getNotaIsto() > x2.getNotaIsto())
        return 1;
    else
        return -1;
}

int comparaMedie(const Student& x1, const Student& x2)
{
    if (x1.getMedie() == x2.getMedie())
        return 0;
    if (x1.getMedie() > x2.getMedie())
        return 1;
    else
        return -1;
}
