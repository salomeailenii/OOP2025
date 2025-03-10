#include "Student.h"

void Student::setName (const string& n)
{
	nume = n;
}

string Student::getName() const
{
	return nume;
}

bool Student::setNotaMate(float nota)
{
	if(nota < 1.0f || nota > 10.0f)
		return false;
	notaMate = nota;
}

float Student::getNotaMate() const
{
	return notaMate;
}

bool Student::setNotaEngl(float nota)
{
	if (nota < 1.0f || nota > 10.0f)
		return false;
	notaEngl = nota;

}

float Student::getNotaEngl() const
{
	return notaEngl;
}

bool Student::setNotaIsto(float nota)
{
	if (nota < 1.0f || nota > 10.0f)
		return false;
	notaIsto = nota;

}

float Student::getNotaIsto() const
{
	return notaIsto;
}

float Student::getMedie() const
{
	return (notaMate + notaEngl + notaIsto)/3;
}
