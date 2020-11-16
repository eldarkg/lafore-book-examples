// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// sstrio.cpp
// ввод/вывод для строк стандартного класса string

#include <locale>
#include <iostream>
#include <string> // для стандартного класса string в языке C++
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	wstring full_name, nickname, address;
	wstring greeting(L"Здравствуйте, ");
	
	// тут можно ввести фамилию, имя и отчество,
	// а так как они отделяются пробелами, то используем функцию getline
	wcout << L"Введите ваше имя: ";
	getline(wcin, full_name);
	wcout << L"Ваше имя: " << full_name << endl;

	// предполагается, что псевдоним состоит из одного слова (т.е. без пробелов),
	// поэтому используем при получении строки от пользователя
	// обычный оператор извлечения из потока (>>)
	wcout << L"Введите ваш псевдоним: ";
	wcin >> nickname;

	greeting += nickname;
	wcout << greeting << endl;

	// в адресе могут быть пробелы, поэтому используем функцию getline
	wcout << L"Введите ваш адрес в несколько строк\n";
	wcout << L"(окончание ввода символ '$'):\n";
	getline(wcin, address, L'$');
	wcout << L"Ваш адрес: " << address << endl;

	return 0;
}