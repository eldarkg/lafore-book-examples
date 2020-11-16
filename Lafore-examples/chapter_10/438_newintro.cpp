// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// newintro.cpp
// знакомство с оператором new

// для использования небезопасной функции wcscpy
#define _CRT_SECURE_NO_WARNINGS

#include <locale>
#include <iostream>
// #include <cstring> // для функций wcslen, wcscpy не понадобился
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	const wchar_t* str = L"Дурная голова ногам покоя не дает.";
	int len = wcslen(str);      // вычислим длину строки str

	wchar_t* ptr;               // создадим указатель на строку
	ptr = new wchar_t[len + 1]; // выделим память: строка + нулевой символ

	wcscpy(ptr, str);           // скопируем строку str в ptr

	wcout << L"ptr = " << ptr << endl; // покажем строку, на которую указывает ptr

	delete[] ptr;               // освободим выделенную память

	return 0;
}