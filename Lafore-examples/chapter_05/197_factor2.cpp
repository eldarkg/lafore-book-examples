// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// factor2.cpp
// подсчет факториала числа с помощью рекурсии

#include <locale>
#include <iostream>
using namespace std;

unsigned long factfunc(unsigned long); // прототип функции

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int n;              // число, вводимое пользователем
	unsigned long fact; // факториал этого числа
	wcout << L"Введите целое число: ";
	wcin >> n;
	fact = factfunc(n);
	wcout << L"Факториал числа " << n << L" равен " << fact << endl;

	return 0;
}

// функция рекурсивно подсчитывает факториал числа
unsigned long factfunc(unsigned long n)
{
	if (n > 1)
		return n * factfunc(n - 1); // вызов самой себя
	else
		return 1;
}