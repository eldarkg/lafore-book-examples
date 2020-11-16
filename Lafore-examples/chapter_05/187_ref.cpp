// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// ref.cpp
// применение ссылочного механизма передачи аргументов

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	// переключение стандартного потока ввода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	void intfrac(float, float&, float&); // прототип

	float number, intpart, fracpart;
	
	do {
		wcout << L"Введите вещественное число: "; wcin >> number;
		intfrac(number, intpart, fracpart);       // нахождение целой и дробной части
		wcout << L"Целая часть равна " << intpart // вывод результатов
			  << L", дробная часть равна " << fracpart << endl;
	} while(number != 0.0);                       // выход из цикла, если введен ноль

	return 0;
}

// функция intfrac()
// вычисляет целую и дробную часть вещественного числа
void intfrac(float n, float& intp, float& fracp)
{
	long temp = static_cast<long>(n); // преобразование к типу long
	intp = static_cast<float>(temp);  // и обратно во float
	fracp = n - intp;                 // вычитаем целую часть
}