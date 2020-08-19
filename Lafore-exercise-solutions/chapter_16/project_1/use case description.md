Диаграмма прецедентов:

![](use case diagram.png)

Описание прецедента «Запуск программы»:

Пользователь запускает программу | Программа запрашивает у пользователя длину дистанции в фурлонгах (число от 1 до 12 включительно) и количество лошадей, участвующих в скачке (от 1 до 7 включительно).

Программа рисует трек длиной в заданное количество фурлонгов и шириной, способной вместить заданное количество лошадей. Слева от стартовой линии трека отображаются лошади. (Длина трека параллельна ширине экрана, а ширина трека параллельна высоте экрана.)

После этого лошади сразу стартуют, двигаясь вправо, к финишной линии трека. Скорость каждой лошади во время скачки много раз меняется случайным образом.

По достижении каждой лошадью финишной линии трека лошадь останавливается, а справа от нее выводится надпись «Время = 0:00», в которой вместо «0:00» указывается время в минутах и секундах, за которое данная лошадь преодолела заданную дистанцию. (Продолжительность минут и секунд в симуляции может не совпадать с продолжительностью реальных минут и секунд.)
--- | ---
После начала движения лошадей пользователь нажимает любую клавишу на клавиатуре | Если лошади еще движутся, симуляция останавливается, происходит выход из программы.

Если все лошади достигли финиша, выход из программы не происходит автоматически, программа всё равно ожидает от пользователя нажатия любой клавиши на клавиатуре.

В любом случае после выхода из программы всё, нарисованное программой на экране, остается на экране (не стирается).