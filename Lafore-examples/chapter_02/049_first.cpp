// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// first.cpp
// самый простой пример программы на языке C++

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	wcout << L"У каждой эпохи свой язык\n";
	return 0;
}
