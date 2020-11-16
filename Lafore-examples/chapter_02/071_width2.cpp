// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// width2.cpp
// применение манипулятора setw

#include <locale>
#include <iostream>
#include <iomanip> // для использования setw
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	long pop1 = 8425785, pop2 = 47, pop3 = 9761;
	wcout << setw(9) << L"Город" << setw(12) << L"Население" << endl
	      << setw(9) << L"Москва" << setw(12) << pop1 << endl
		  << setw(9) << L"Киров" << setw(12) << pop2 << endl
		  << setw(9) << L"Угрюмовка" << setw(12) << pop3 << endl;

	return 0;
}
