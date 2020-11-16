// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// increm.cpp
// применение операции инкрементирования

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int count = 10;
	wcout << L"count=" << count   << endl; // вывод числа 10
	wcout << L"count=" << ++count << endl; // вывод числа 11 (префиксная форма)
	wcout << L"count=" << count   << endl; // вывод числа 11
	wcout << L"count=" << count++ << endl; // вывод числа 11 (постфиксная форма)
	wcout << L"count=" << count   << endl; // вывод числа 12

	return 0;
}
