﻿// исходный текст программы сохранен в кодировке UTF-8 с сигнатурой

// 608_project14_headtwo.h

struct foo      // определение структуры
{
	int member;
};

// В учебнике Лафоре здесь вместо структуры определена глобальная переменная,
// но ранее сам автор не рекомендовал определять глобальные переменные в заголовочных
// файлах, так как возникнет ошибка множественного определения, если такой заголовочный
// файл будет включен в несколько исходных файлов многофайловой программы. Поэтому
// я решил здесь определить структуру.