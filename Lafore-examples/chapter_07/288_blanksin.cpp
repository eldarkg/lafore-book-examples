// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// blanksin.cpp
// ввод строки с пробелами

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	const int MAX = 80; // максимальная длина строки
	wchar_t str[MAX];   // сама строка

	// ввод строки
	wcout << L"Введите строку: ";
	wcin.get(str, MAX);
	
	// показ результата
	wcout << L"Вы ввели: " << str << endl;

	return 0;
}