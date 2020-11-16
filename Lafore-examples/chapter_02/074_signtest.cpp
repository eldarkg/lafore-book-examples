// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// signtest.cpp
// работа со знаковыми / беззнаковыми переменными

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int signedVar          = 1500000000; // знаковая переменная
	unsigned int unsignVar = 1500000000; // беззнаковая переменная
	signedVar = (signedVar *2) / 3; // выход за границы диапазона
	unsignVar = (unsignVar *2) / 3; // вычисления внутри диапазона
	wcout << L"Знаковая переменная равна "    << signedVar << endl; // вывод правильного результата
	wcout << L"Беззнаковая переменная равна " << unsignVar << endl; // вывод некорректного результата

	return 0;
}
