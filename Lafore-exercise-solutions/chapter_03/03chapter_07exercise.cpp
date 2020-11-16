// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 03chapter_07exercise.cpp
// Программа для расчета суммы денег, получаемой от вложения начальной суммы
// в банк на вклад с фиксированной процентной ставкой дохода на определенное количество лет.
// Пользователь вводит начальную сумму вклада, процентную ставку и число лет.

#include <locale>
#include <iostream>
#include <iomanip> // для манипулятора setprecision
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	double Sum;  // сумма вклада
	int Years;   // число лет
	double Rate; // процентная ставка

	wcout << L"Введите начальный вклад в рублях: "; wcin >> Sum;
	wcout << L"Введите число лет: "; wcin >> Years;
	wcout << L"Введите ставку в процентах: "; wcin >> Rate;

	for (int i=1; i <= Years; i++) // цикл лет
	{
		Sum = Sum + Sum * Rate / 100;
	}

	wcout << L"Через " << Years << L" лет вы получите "
		  << fixed << setprecision(2) << Sum << L" руб." << endl;

	return 0;
}