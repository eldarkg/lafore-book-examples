// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// deque.cpp
// демонстрирует методы push_back, push_front и оператор []
// для двусторонней очереди (deque)

#include <locale>
#include <iostream>
#include <deque>     // для работы с контейнером deque
using namespace std;

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));
	
	deque<int> deq;

	deq.push_back(30);           // добавляем элементы в конец очереди
	deq.push_back(40);
	deq.push_back(50);
	deq.push_front(20);          // добавляем элементы в начало очереди
	deq.push_front(10);

	deq[2] = 33;                 // изменяем произвольный элемент контейнера

	for (int j = 0; j < deq.size(); j++)
		wcout << deq[j] << L' '; // выводим на экран все элементы

	wcout << endl;
	
	return 0;
}