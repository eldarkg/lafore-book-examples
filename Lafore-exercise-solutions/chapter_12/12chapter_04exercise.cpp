﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 12chapter_04exercise.cpp
// Требуется в цикле запрашивать у пользователя имена, отчества, фамилии и номера
// работников и с помощью форматированного вывода записывать эти данные в поток
// класса wofstream, связанный с файлом. После окончания получения данных от
// пользователя требуется закрыть этот поток. Затем открыть поток класса wifstream,
// связанный с тем же файлом, прочитать из него данные и показать их на экране.

#include <io.h>      // для функции _setmode
#include <fcntl.h>   // для константы _O_U16TEXT
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
//#include <string>  // для работы с классом wstring не понадобился
#include <codecvt>   // для работы с фасетом codecvt_utf8 локали
// #include <locale> // не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	_setmode(_fileno(stdout), _O_U16TEXT);
	// переключение стандартного потока ввода в формат Юникода
	_setmode(_fileno(stdin), _O_U16TEXT);
	
	// создаем константу, содержащую локаль с нужным фасетом для
	// преобразования символов при записи в файл (и чтении из файла) в кодировке UTF-8
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());

	wstring name, middle, surname; // имя, отчество, фамилия
	unsigned long empnum;          // номер работника
	wchar_t ch;                    // для ответа пользователя (д/н)
	
	wofstream outfile(L"файл с данными.txt"); // выходной поток
	outfile.imbue(utf8_locale);               // связываем наш поток с нужной локалью

	// получим данные от пользователя и запишем в файл
	do {
		// получаем от пользователя данные работника
		wcout << L"Введите номер работника: ";
		wcin >> empnum;
		wcout << L"Введите имя, отчество и фамилию работника: "; // через пробел
		wcin >> name >> middle >> surname;
		// записываем полученные данные в файл
		outfile << empnum << name << L' ' << middle << L' ' << surname << L' ';
		// запрашиваем пользователя об окончании ввода
		wcout << L"\nПродолжить ввод (д/н)? ";
		wcin >> ch; wcout << endl;
	} while (ch == L'д'); // выход по 'н'

	// закроем выходной поток
	outfile.close();

	wifstream infile(L"файл с данными.txt"); // входной поток
	infile.imbue(utf8_locale);               // связываем наш поток с нужной локалью

	// прочтем данные из файла и покажем на экране
	while (infile >> empnum >> name >> middle >> surname)
		wcout << L"Работник " << empnum << L": "
			<< name << L' ' << middle << L' ' << surname << endl;

	return 0;
}