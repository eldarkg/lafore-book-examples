﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ferrors.cpp
// проверка на ошибки при открытии файла

// В книге Лафоре в этой программе используется путь к файлу "a:тест.dat".
// Я заменил его на "g:\\тест.dat". Книга писалась много лет назад, когда
// буква "a" в настольных компьютерах была обычно занята под дисковод для дискет.
// Я попытался заменить на "c", которая обычно обозначает основной жесткий диск
// с операционной системой, но это неудобно, потому что для записи файла на этот
// диск программа в Windows должна обладать правами администратора. Поэтому
// я выбрал букву "g", по которой у меня к компьютеру подключен через USB внешний
// жесткий диск. Это удобно еще и для тестирования — я могу отключить этот диск
// и тогда программа должна сообщить об ошибке при попытке открытия файла для
// записи.

// Обратную косую черту (\) пришлось написать двойной (\\), так как ее можно
// изобразить только такой управляющей последовательностью в строке.

#include <locale>
#include <fstream>   // для файлового ввода/вывода
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	const wchar_t* filename = L"g:\\тест.dat";
	ifstream file;
	file.open(filename);

	if (!file)
		wcout << L"Не получается открыть \"" << filename << L"\".";
	else
		wcout << L"Файл открыт успешно.";

	wcout << L"\n\nfile = " << static_cast<bool>(file);
	wcout << L"\nКод ошибки = " << file.rdstate();
	wcout << L"\ngood() = " << file.good();
	wcout << L"\neof() = " << file.eof();
	wcout << L"\nfail() = " << file.fail();
	wcout << L"\nbad() = " << file.bad() << endl;

	file.close();

	return 0;
}