// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// width1.cpp
// демонстрирует необходимость применения манипулятора setw

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	long pop1 = 4789426, pop2 = 274124, pop3 = 9761;
	wcout << L"Город " << L"Нас." << endl
		  << L"Москва " << pop1 << endl
		  << L"Киров " << pop2 << endl
		  << L"Угрюмовка " << pop3 << endl;

	return 0;
}
