// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// merge.cpp
// объединяет два контейнера в третий

#include <locale>
#include <iostream>
#include <algorithm> // для алгоритма merge
using namespace std;

int src1[] = { 2, 3, 4, 6, 8 }; // первый исходный контейнер
int src2[] = { 1, 3, 5 };       // второй исходный контейнер
int dest[8];                    // принимающий контейнер-результат

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	merge(src1, src1 + 5, src2, src2 + 3, dest); // выполнить объединение

	for (int j = 0; j < 8; j++)                  // вывести результат на экран
		wcout << dest[j] << L' ';
	wcout << endl;
	
	return 0;
}