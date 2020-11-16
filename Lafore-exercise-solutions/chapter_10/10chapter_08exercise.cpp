﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 10chapter_08exercise.cpp
// Имеется программа 447_linklist.cpp из этой (10-й) главы. Требуется
// переработать метод additem класса linklist (связный список) так, чтобы
// он добавлял новый элемент списка не в его начало, как сделано в программе
// 447_linklist.cpp, а в его конец.

#include <locale>
#include <iostream>
using namespace std;

struct link     // элемент списка
{
	int data;   // данные
	link* next; // указатель на следующий элемент списка
};

class linklist            // класс, представляющий связный список
{
private:
	link* first;          // указатель на первый элемент списка
public:
	linklist()            // конструктор без аргументов
		{ first = NULL; } // первого элемента пока нет
	void additem(int d);  // добавление элемента списка
	void display();       // вывод на экран данных из всех элементов списка
};

void linklist::additem(int d) // добавление элемента списка в его конец
{
	link* newlink = new link; // выделяем память под новый элемент списка
	newlink->data = d;        // сохраняем в него данные
	newlink->next = NULL;     // новый элемент — последний в списке
	
	// найдем конец списка, чтобы добавить в него новый элемент
	if (first)                       // если список не пуст,
	{
		link* current = first;       // начинаем поиск с первого элемента
		while (current->next)        // если текущий элемент не является последним,
			current = current->next; // переходим в цикле к следующему элементу списка
		current->next = newlink;     // вставляем в конец списка новый элемент
	}
	else                             // иначе, если список пуст
		first = newlink;             // вставляем новый элемент первым в списке
}

void linklist::display() // вывод на экран данных из всех элементов списка
{
	link* current = first;              // начинаем с первого элемента
	while (current)                     // пока указатель на текущий элемент
	{                                   // не равен NULL (что означает конец списка)
		wcout << current->data << endl; // выводим данные
		current = current->next;        // переходим к следующему элементу
	}
}

int main()
{
	// переключение стандартного потока вывода в формат Юникода
	locale::global(locale("ru_RU.UTF-8"));

	linklist li;    // создаем связный список

	li.additem(25); // добавляем четыре элемента в список
	li.additem(36);
	li.additem(49);
	li.additem(64);

	li.display();   // выводим весь список

	return 0;
}