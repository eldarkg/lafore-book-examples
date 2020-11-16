// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 02chapter_02exercise.cpp
// вывести заданную таблицу с выровненными столбцами

#include <locale>
#include <iostream>
#include <iomanip> // для манипулятора setw
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	wcout << setw(4) << 1990 << setw(6) << 135 << endl
		  << setw(4) << 1991 << setw(6) << 7290 << endl
		  << setw(4) << 1992 << setw(6) << 11300 << endl
		  << setw(4) << 1993 << setw(6) << 16200 << endl;

	return 0;
}
