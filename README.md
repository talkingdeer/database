# database
 Migration Service
 
Данный код представляет собой реализацию основного цикла программы для работы с базой данных. Вот краткий обзор функционала, реализованного в коде:

1. Начальное приветствие и инициализация переменных, таких как список base для хранения данных Person и файловый поток fstream f.

2. Попытка загрузить базу данных из файла с помощью функции load(f, base). В случае успешной загрузки выводится сообщение об успехе, в противном случае - сообщение об ошибке.

3. Запуск бесконечного цикла, в котором программа ожидает пользовательского ввода и обрабатывает его в соответствии с введенной командой.

4. Поддерживаемые команды включают:
   - ? : Отображение списка доступных команд.
   - Print : Вывод содержимого базы данных.
   - Generate [Number]: Генерация определенного количества пользователей и добавление их в базу данных. Через пробел указывается количество.
   После генерации информация сразу переносится в файл.
   - Save : Сохранение базы данных в файл.
   - Load : Загрузка базы данных из файла.
   - Add : Добавление нового человека в базу данных. Через пробел указывается все данные о человеке. Есть проверка на количество полей, для успешной записи их должно быть в точности,
   сколько и требуется.
   - Remove [lastname]: Удаление человека из базы данных. Через пробел указывается фамилия.
   - Find [rating > number] && [exitpermit 1] && [lastname lastname] && [date]: Поиск людей в базе данных по имени, разрешению на выезд или рейтингу. Для комбинированного запроса используется &&.
   Примеры команд:
   
   Find lastname Берлиоз && rating > 0.9
   Find rating > 0.5 && rating < 0.6
   Find date 01.04.1873 && lastname Рахманинов && rating > 0.88
   
   В случае, если команда содержит дублирующие указания, будет выбрано последнее. Пример:
   
   Find exitpermit 1 && exitpermit 0
   Здесь выведется с 0.
   
   - Size : Вывод количества записей в базе данных.
   
	Все команды проверяются на корректность ввода. Например, при вызове 

	Generate 10 метрополия
	Generate

	будет выведено сообщение о некорректности команды.

	В случае ввода некорректного числа либо выдается сообщение об ошибке и запрос команд продолжается, либо вызывается исключение и программа останавливается. 
	Пример:

	Find rating > Совхоз
	
	Будет выведено Incorrect rating

5. В 4-ом этапе был реализован сценарий взаимодействия клиента и сервера посредством сокетов.
Сначала запускается сервер, затем (в отдельном терминале) клиент. Клиент находится в ожидании команды. Далее она посылается на сервер, обрабатывается и клиент получает ответ.
Сервер не выдает ошибок ни при каких сколь угодно произвольно введенных командах от клиента.

6. Для пятого этапа добавлена поддержка 8 клиентов, которые в разное время посылают случайные (на выбор из 10) запросы серверу.