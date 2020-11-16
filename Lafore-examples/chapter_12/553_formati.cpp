﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// formati.cpp
// чтение форматированного вывода из файла с помощью операции извлечения (>>)
// (слово «вывод» здесь употреблено потому, что в предыдущем примере (552_formato.cpp)
// в файл были выведены данные, эти данные тут мы называем «форматированным выводом»,
// хотя для данного примера они уже становятся «форматированным вводом»)

// я добавил в программу две строки для работы с локалью, чтобы можно было
// читать русские буквы из файла в кодировке UTF-8

#include <locale>
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
#include <string>    // для работы с классом wstring
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали
// #include <locale> // не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при чтении из файла в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	wchar_t ch;
	int j;
	double d;
	wstring str1;
	wstring str2;

	wifstream infile(L"файл с данными.txt"); // создать объект класса wifstream
	infile.imbue(utf8_locale);               // связываем наш поток с нужной локалью
	                                         
	infile >> ch >> j >> d >> str1 >> str2;  // извлечь (прочесть) из него данные
	
	wcout << ch << endl                      // вывести данные на экран
	      << j << endl
	      << d << endl
	      << str1 << endl
	      << str2 << endl;

	return 0;
}