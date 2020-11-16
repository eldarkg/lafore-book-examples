// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// find_if.cpp
// ищет в массиве строк первое вхождение строки "Дмитрий"

#include <locale>
#include <iostream>
// #include <string> // для класса wstring не понадобился
#include <algorithm> // для алгоритма find_if
using namespace std;

// предикат: возвращает true, если name == "Дмитрий"
bool isDmitry(wstring name)
{
	return name == L"Дмитрий";
}

// тестовый массив строк
wstring names[] = { L"Сергей", L"Татьяна", L"Елена", L"Дмитрий",
                    L"Михаил", L"Владимир" };

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	wstring* ptr;

	ptr = find_if(names, names + 6, isDmitry);
	
	if (ptr == names + 6)
		wcout << L"Дмитрия нет в списке.\n";
	else
		wcout << L"Дмитрий записан в позиции " << (ptr - names) << L" списка.\n";
	
	return 0;
}