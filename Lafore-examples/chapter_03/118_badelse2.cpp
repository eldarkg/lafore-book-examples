// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// badelse2.cpp
// неправильное сопоставление else и if во вложенных ветвлениях (исправлено)

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int a, b, c;
	wcout << L"Введите числа a, b и с: \n";
	wcin >> a >> b >> c;
	if (a == b)
	{
		if (b == c)
			wcout << L"a, b, и с равны\n";
	}
	else // после заключения второго if в фигурные скобки
		 // этот блок else теперь относится к первому if
		wcout << L"а и b не равны\n";

	return 0;
}