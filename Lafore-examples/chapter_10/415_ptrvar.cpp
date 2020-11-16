// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ptrvar.cpp
// указатели (переменные, содержащие адреса)

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int var1 = 11;              // две целочисленные переменные
	int var2 = 22;

	wcout << &var1 << endl      // выведем на экран адреса этих переменных
	      << &var2 << endl << endl;

	int* ptr;                   // это переменная-указатель на целое

	ptr = &var1;                // присвоим ей значение адреса var1
	wcout << ptr << endl;       // и покажем на экране

	ptr = &var2;                // теперь присвоим ей значение адреса var2
	wcout << ptr << endl;       // и покажем на экране

	return 0;
}