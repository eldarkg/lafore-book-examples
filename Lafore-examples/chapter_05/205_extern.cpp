// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// extern.cpp
// демонстрирует работу с глобальными переменными

#include <locale>
#include <iostream>
// #include <conio.h> // для функции _getwch не понадобился
using namespace std;

wchar_t ch = L'a'; // глобальная переменная ch

void getachar();   // прототипы функций
void putachar();

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	while (ch != L'\r') // функция main() использует значение ch
	{
		getachar();
		putachar();
	}
	wcout << endl;

	return 0;
}

void getachar()
{
	ch = _getwch(); // функция getachar() использует значение ch
}

void putachar()
{
	wcout << ch;    // функция putachar() использует значение ch
}