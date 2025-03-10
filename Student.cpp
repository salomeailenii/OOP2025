#include "Student.h"

void Student::setName (const string& n)
{
	nume = n;
}

string Student::getName()
{
	return nume;
}

bool Student::setNotaMate(float nota)
{
	if(nota < 1.0f || nota > 10.0f)
		return false;
	notaMate = nota;
}

float Student::getNotaMate()
{
	return notaMate;
}

bool Student::setNotaEngl(float nota)
{
	if (nota < 1.0f || nota > 10.0f)
		return false;
	notaEngl = nota;

}

float Student::getNotaEngl()
{
	return notaEngl;
}

bool Student::setNotaIsto(float nota)
{
	if (nota < 1.0f || nota > 10.0f)
		return false;
	notaIsto = nota;

}

float Student::getNotaIsto()
{
	return notaIsto;
}

float Student::getMedie()
{
	return (notaMate + notaEngl + notaIsto)/3;
}
