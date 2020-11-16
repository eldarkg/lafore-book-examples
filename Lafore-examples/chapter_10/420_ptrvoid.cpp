// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrvoid.cpp
// указатель на void

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int intvar;          // целочисленная переменная
	float flovar;        // вещественная переменная

	int* ptrint;         // указатель на int
	float* ptrflo;       // указатель на float
	void* ptrvoid;       // указатель на void
	
	ptrint = &intvar;    // так можно:  int* = int*
	// ptrint = &flovar; // так нельзя: int* = float*
	// ptrflo = &intvar; // так нельзя: float* = int*
	ptrflo = &flovar;    // так можно:  float* = float*
	
	ptrvoid = &intvar;   // так можно:  void* = int*
	ptrvoid = &flovar;   // так можно:  void* = float*

	return 0;
}