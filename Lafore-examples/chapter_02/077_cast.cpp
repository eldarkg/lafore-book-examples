// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// cast.cpp
// работа со знаковыми и беззнаковыми переменными

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int intVar = 1500000000; // 1 500 000 000
	intVar = (intVar * 10) / 10; // слишком большой результат
	wcout << L"Значение intVar равно " << intVar << endl; // неверный результат
	
	intVar = 1500000000;
	intVar = (static_cast<double>(intVar) * 10) / 10; // приведение к типу double
	wcout << L"Значение intVar равно " << intVar << endl; // верный результат

	return 0;
}
