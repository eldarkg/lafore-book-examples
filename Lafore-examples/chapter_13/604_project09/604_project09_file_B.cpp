﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 604_project09_file_B.cpp

static int add(int a, int b) // определение функции
	{ return a + b; }        // (включает тело функции)

// служебное слово static ограничивает область видимости этой функции
// текущим файлом

// несмотря на то, что в файле_A и в текущем файле_B определены идентичные функции,
// конфликта (ошибки) не происходит, так как благодаря служебному слову static
// область видимости обеих функций ограничена теми файлами, в которых они
// определены

int main()
{
	int answer = add(3, 2); // вызов функции
}