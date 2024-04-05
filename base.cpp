#include "class.h"

string femaleFirstNames[] {"Мария", "Анастасия", "Ангелина", "Анна", "Теона", "Медина", "Амелия", "Ульяна", "Валерия", "Владислава", "Александра", "Мия", "Дарья", "Сабина", "Полина", "София", "Виктория", "Ирина", "Вероника", "Ксения", "Арина", "Вера", "Елизавета", "Варвара", "Екатерина", "Юлия", "Амира", "Милана", "Алиса", "Ярослава", "Любовь", "Софья", "Ника", "Сабрина", "Мадина", "Наталья", "Василиса", "Адель", "Ева", "Мирослава", "Пелагея", "Олеся", "Лилия", "Алёна", "Мелания", "Камила", "Нина", "Кира", "Людмила", "Сафия", "Амина", "Агата", "Маргарита", "Зоя", "Алина", "Ясмина", "Марина", "Диана", "Аиша", "Татьяна", "Таисия", "Ольга", "Кристина", "Стефания", "Майя", "Амалия", "Аглая", "Надежда", "Камилла", "Айлин", "Оливия", "Марьяна", "Элина", "Лидия", "Малика", "Светлана", "Мила", "Эмилия", "Яна", "Есения", "Дарина", "Антонина", "Агния", "Марианна", "Евгения", "Каролина", "Марьям", "Лея", "Анжелика", "Евангелина", "Алия", "Фатима", "Злата", "Эмма", "Карина", "Лиана", "Аделина", "Николь", "Елена", "Альбина"};
string femaleLastNames[] {"Щеглова", "Коновалова", "Еремеева", "Герасимова", "Орлова", "Лаврова", "Назарова", "Абрамова", "Николаева", "Ефимова", "Сорокина", "Румянцева", "Мартынова", "Румянцева", "Морозова", "Селезнева", "Дмитриева", "Николаева", "Моргунова", "Лебедева", "Леонова", "Астахова", "Петрова", "Краснова", "Кошелева", "Дмитриева", "Воронова", "Винокурова", "Васильева", "Белякова", "Родина", "Мухина", "Лаврова", "Завьялова", "Денисова", "Галкина", "Королева", "Еремина", "Зайцева", "Дмитриева", "Кузнецова", "Ефимова", "Калинина", "Лосева", "Уткина", "Павлова", "Ларина", "Гончарова", "Соловьева", "Кузнецова", "Свиридова", "Беляева", "Ефремова", "Кондратова", "Козлова", "Исаева", "Кузнецова", "Смирнова", "Петрова", "Белоусова", "Антонова", "Жилина", "Дорофеева", "Иванова", "Филимонова", "Филатова", "Николаева", "Жарова", "Ткачева", "Виноградова", "Романова", "Борисова", "Корнилова", "Козловская", "Устинова", "Островская", "Гончарова", "Козлова", "Тимофеева", "Балашова", "Смирнова", "Данилова", "Климова", "Абрамова", "Сафонова", "Юдина", "Леонова", "Гусева", "Сергеева", "Грачева", "Гончарова", "Петрова", "Попова", "Давыдова", "Калашникова", "Акимова", "Кузнецова", "Кузнецова", "Давыдова", "Нестерова"};
string femaleSurnames[] {"Ивановна", "Александровна", "Сергеевна", "Николаевна", "Дмитриевна", "Владимировна", "Андреевна", "Егоровна", "Артемовна", "Максимовна", "Ефимовна", "Аркадьевна", "Константиновна", "Павловна", "Валерьевна", "Ярославовна", "Тимофеевна", "Алексеевна", "Васильевна", "Федоровна", "Михайловна", "Даниловна", "Степановна", "Юрьевна", "Анатольевна", "Валентиновна", "Ильинична", "Робертовна", "Кирилловна", "Семёновна", "Александровна", "Аркадьевна", "Владленовна", "Руслановна", "Матвеевна", "Евгеньевна", "Всеволодовна", "Анисимовна", "Борисовна", "Георгиевна", "Кондратовна", "Тихоновна", "Григорьевна", "Станиславовна", "Давидовна", "Аркадьевна", "Егоровна", "Андреевна", "Захаровна", "Давидовна", "Львовна", "Марковна", "Кирилловна", "Тарасовна", "Нестровна", "Богдановна", "Никитична", "Савельевна", "Германовна", "Игоревна", "Авдеевна", "Святославовна", "Евсеевна", "Артемьевна", "Ильична", "Леонидовна", "Мироновна", "Ярославовна", "Лазаревна", "Созоновна", "Прохоровна", "Устиновна", "Артёмовна", "Демидовна", "Филимоновна", "Петровна", "Гавриловна", "Маратовна", "Леонтьевна", "Левовна", "Львовна", "Олеговна", "Кондратиевна", "Арсеньевна", "Зиновьевна", "Андриановна", "Аристарховна", "Иосифовна", "Марковна", "Леонардовна", "Малховна", "Валентиновна", "Пантелеймоновна", "Динховна", "Даздрапермовна", "Михайловна", "Иннокентьевна", "Даниловна", "Сергеевна", "Эзотовна"};
string maleFirstNames[] {"Иван", "Дмитрий", "Александр", "Михаил", "Артем", "Никита", "Сергей", "Максим", "Андрей", "Кирилл", "Павел", "Денис", "Антон", "Алексей", "Тимофей", "Владимир", "Игорь", "Степан", "Константин", "Григорий", "Ярослав", "Егор", "Марк", "Федор", "Даниил", "Владислав", "Тимур", "Яков", "Матвей", "Роман", "Арсений", "Борис", "Пётр", "Евгений", "Давид", "Леонид", "Илья", "Артур", "Эдуард", "Виктор", "Денис", "Станислав", "Руслан", "Савелий", "Мирон", "Макар", "Филипп", "Василий", "Семён", "Вадим", "Савва", "Игнат", "Прохор", "Анатолий", "Валентин", "Фёдор", "Святослав", "Мир", "Ростислав", "Валерий", "Всеволод", "Богдан", "Захар", "Валерий", "Аркадий", "Лев", "Марат", "Назар", "Олег", "Мирза", "Артём", "Самвел", "Карен", "Левон", "Тигран", "Ваган", "Арсен", "Армен", "Давид", "Гевор", "Эльман", "Руфат", "Ян", "Юрий", "Адам", "Эдгар", "Лазарь", "Константин", "Мирослав", "Мстислав", "Владимир", "Святополк", "Ярослав", "Святослав", "Борис", "Вячеслав", "Владислав", "Валентин", "Геннадий", "Вениамин"};
string maleLastNames[] {"Иванов", "Петров", "Смирнов", "Сергеев", "Михайлов", "Федоров", "Волков", "Николаев", "Козлов", "Павлов", "Морозов", "Зайцев", "Соловьев", "Васильев", "Попов", "Алексеев", "Лебедев", "Григорьев", "Степанов", "Семёнов", "Павлов", "Богданов", "Андреев", "Козлов", "Никитин", "Сысоев", "Фёдоров", "Макаров", "Артемьев", "Леонтьев", "Свиридов", "Тимофеев", "Гурьев", "Горбунов", "Филатов", "Краснов", "Куприянов", "Тарасов", "Беляков", "Калинин", "Комаров", "Галкин", "Сорокин", "Лукин", "Медведев", "Цветков", "Афанасьев", "Королев", "Миронов", "Фадеев", "Трофимов", "Мартынов", "Евсеев", "Яковлев", "Панов", "Родин", "Шестаков", "Кондратьев", "Капустин", "Жаров", "Ларин", "Фокин", "Масленников", "Ефимов", "Орлов", "Ларионов", "Константинов", "Вишняков", "Миронов", "Ермаков", "Колесников", "Лыткин", "Афонин", "Тимофеев", "Пестов", "Свищев", "Ломакин", "Луговой", "Мещеряков", "Харитонов", "Абрамов", "Ковалёв", "Костин", "Карпов", "Попов", "Бирюков", "Герасимов", "Казаков", "Тюрин", "Прокопов", "Щербаков", "Ларин", "Чернов", "Львов", "Дубров", "Косухин", "Берия", "Леонтьев", "Ягода", "Джугашвили"};
string maleSurnames[] {"Иванович", "Петрович", "Сергеевич", "Михайлович", "Александрович", "Андреевич", "Владимирович", "Дмитриевич", "Николаевич", "Васильевич", "Алексеевич", "Егорович", "Данилович", "Олегович", "Семёнович", "Павлович", "Викторович", "Федорович", "Максимович", "Тимофеевич", "Константинович", "Станиславович", "Ярославович", "Артёмович", "Никитович", "Евгеньевич", "Львович", "Давидович", "Кириллович", "Борисович", "Степанович", "Игоревич", "Витальевич", "Ильич", "Матвеевич", "Денисович", "Яковлевич", "Романович", "Арсеньевич", "Миронович", "Савельевич", "Владленович", "Леонидович", "Миланович", "Кириллович", "Эдуардович", "Игнатьевич", "Ефимович", "Маркович", "Вадимович", "Григорьевич", "Аполлонович", "Саввич", "Филиппович", "Вениаминович", "Михайлович", "Валерьевич", "Гаврилович", "Русланович", "Климович", "Геннадьевич", "Трофимович", "Кондратович", "Лукич", "Святополкович", "Ярославович", "Степанович", "Филимонович", "Давыдович", "Ярославович", "Измайлович", "Казимирович", "Фирсович", "Мэлсович", "Дамирович", "Фёдорович", "Карпович", "Федотович", "Леонтьевич", "Лазаревич", "Леонидович", "Глебович", "Тарасович", "Владиславович", "Никифорович", "Ларионович", "Онуфриевич", "Лаврович", "Андронович", "Абдулович", "Фомич", "Платонович", "Маркович", "Александрович", "Макарович", "Тарасович", "Львович", "Искандерович", "Тимурович", "Рамзанович"};
string citizenship[] {"РФ", "Украина", "Белорусь", "Казахстан", "Монголия"};

bool if_empty(fstream& f){
	return f.peek() == ifstream::traits_type::eof();
}

bool load(fstream& f, list<Person>& base)
{
	cout << "...\n";
	f.open("database.txt", ios_base::in);
	if(if_empty(f)){
		cout << "Database.txt is empty.\n";
		f.close();
		return true;
	}
	base.clear();
	string s;
	bool b;
	Date date;
	double rating;
	Person one;
	while(!f.eof())
	{
		Person one;
		f >> s;
		one.pushLastName(s);
		f >> s;
		one.pushFirstName(s);
		f >> s;
		one.pushSurname(s);
		f >> date;
		one.pushDateOfBirth(date);
		f >> s;
		one.pushCitizenship(s);
		f >> b;
		one.pushExitPermit(b);
		f >> rating;
		one.pushRating(rating);
		base.push_back(one);
	}
	f.close();
	return true;
}

bool add(list<Person>& base)
{
	cout << "...\n";
	string s;
	bool b;
	Date date;
	double rating;
	Person one;
	cin >> s;
	one.pushLastName(s);
	cin >> s;
	one.pushFirstName(s);
	cin >> s;
	one.pushSurname(s);
	cin >> date;
	one.pushDateOfBirth(date);
	cin >> s;
	one.pushCitizenship(s);
	cin >> b;
	one.pushExitPermit(b);
	cin >> b;
	one.pushExitPermit(b);
	cin >> rating;
	one.pushRating(rating);
	base.push_back(one);
	return true;
}

bool print(list<Person>& base)
{
	cout << "...\n";
	if(base.empty()) {
		cout << "Database is empty.\n";
	} else {
		for(auto it = base.begin(); it != base.end(); it++){
			(*it).print();
		}
	}
	return true;
}

bool save(fstream& f, list<Person>& base)
{
	cout << "...\n";
	f.open("database.txt", ios_base::out);
	auto it = base.begin();
	(*it).print(f);
	it++;
	for(; it != base.end(); it++){
		f << endl;
		if(it != base.begin())
		(*it).print(f);
	}
	f.close();
	return true;
}

bool generate(list<Person>& base, int k)
{
	cout << "...\n";
	base.clear();
	for(int i = 0; i < k; i++){
		if(rand() % 2){
			Date d;
			Person one(femaleLastNames[rand() % 100], femaleFirstNames[rand() % 100], femaleSurnames[rand() % 100], d, citizenship[rand() % 5], rand() % 2, (double)rand() / RAND_MAX);
			base.push_back(one);
		} else {
			Date d;
			Person one(maleLastNames[rand() % 100], maleFirstNames[rand() % 100], maleSurnames[rand() % 100], d, citizenship[rand() % 5], rand() % 2, (double)rand() / RAND_MAX);
			base.push_back(one);
		}
	}
	return true;
}

bool remove(list<Person>& base, string line)
{
	bool fl = false;
	cout << "...\n";
	for(auto it = base.begin(); it != base.end(); it++){
		if((*it).getLastName() == line){
			it = base.erase(it);
			it--;
			fl = true;
		}
	}
	return fl;
}

bool findName(string name, list<Person>& base)
{
	bool fl = false;
	cout << "...\n";
	for(auto it = base.begin(); it != base.end(); it++){
		if((*it).getFirstName() == name){
			(*it).print();
			fl = true;
		}
	}
	
	return fl;
}

bool findDate(Date d, list<Person>& base)
{
	bool fl = false;
	cout << "...\n";
	for(auto it = base.begin(); it != base.end(); it++){
		if((*it).getDate() == d){
			(*it).print();
			fl = true;
		}
	}
	return fl;
}

bool findRating(double r, bool sign, list<Person>& base)
{
	bool fl = false;
	cout << "...\n";
	if(sign){
		for(auto it = base.begin(); it != base.end(); it++){
			if((*it).getRating() > r){
				(*it).print();
				fl = true;
			}
		}
	} else {
		for(auto it = base.begin(); it != base.end(); it++){
			if((*it).getRating() < r){
				(*it).print();
				fl = true;
			}
		}
	}
	return fl;
}