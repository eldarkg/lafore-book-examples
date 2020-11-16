// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// assign.cpp
// применение арифметических операций с присваиванием

#include <locale>
#include <iostream>
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	int ans = 27;
	ans += 10; // то же самое, что ans = ans + 10;
	wcout << ans << L", ";
	ans -=  7; // то же самое, что ans = ans - 7;
	wcout << ans << L", ";
	ans *=  2; // то же самое, что ans = ans * 2;
	wcout << ans << L", ";
	ans /=  3; // то же самое, что ans = ans / 3;
	wcout << ans << L", ";
	ans %=  3; // то же самое, что ans = ans % 3;
	wcout << ans << endl;

	return 0;
}
