// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// linesin.cpp
// ввод нескольких строк

#include <locale>
#include <iostream>
using namespace std;

const int MAX = 2000; // максимальная длина строки
wchar_t str[MAX];     // сама строка

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// ввод строки
	wcout << L"Введите строку:\n";
	wcin.get(str, MAX, L'$');
	
	// показ результата
	wcout << L"Вы ввели:\n" << str << endl;

	return 0;
}