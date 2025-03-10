#include "Math.h"
#include <iostream>
#include <stdarg.h>
#include <string.h>

int Math::Add(int number1, int number2) {
	return number1 + number2;
}
int Math::Add(int number1, int number2, int number3) {
	return number1 + number2 + number3;
}
double Math::Add(double number1, double number2) {
	return number1 + number2;
}
double Math::Add(double number1, double number2, double number3) {
	return number1 + number2 + number3;
}
int Math::Mul(int number1, int number2) {
	return number1 * number2;
}
int Math::Mul(int number1, int number2, int number3) {
	return number1 * number2 * number3;
}
double Math::Mul(double number1, double number2) {
	return number1 * number2;
}
double Math::Mul(double number1, double number2, double number3) {
	return number1 * number2 * number3;
}


int Math::Add(int count, ...) {
	int suma = 0;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
	{
		suma = suma + va_arg(vl, int);
	}
	va_end(vl);
	return suma;
}

char* Math::Add(const char* sir1, const char* sir2) {
	if (sir1 == nullptr or sir2 == nullptr)
		return nullptr;
	int i;
	i = strlen(sir1) + strlen(sir2) + 1;
	char* buffer = (char*)malloc(i); // alocam memorie dinamic
	// void *memcpy( void *destination, const void * source, size_t num)
	if (buffer == nullptr)
		return nullptr;
	memcpy(buffer, sir1, strlen(sir1));
	memcpy(buffer + strlen(sir1), sir2, strlen(sir2));
	buffer[strlen(sir1) + strlen(sir2)] = '\0';
	return buffer;

}
