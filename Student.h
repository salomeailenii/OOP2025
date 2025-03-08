#pragma once
#include <string>
using namespace std;

class Student
{
	string nume;
	float notaMate, notaEngl, notaIsto;
public:
	void setName(const string& n);
	string getName() const;
	bool setNotaMate(float nota);
	float getNotaMate() const;
	bool setNotaEngl(float nota);
	float getNotaEngl() const;
	bool setNotaIsto(float nota);
	float getNotaIsto() const;
	float getMedie() const;
};

