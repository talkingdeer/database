#include "class.h"

string femaleFirstNames[] {"Мария", "Анастасия", "Ангелина", "Анна", "Теона", "Медина", "Амелия", "Ульяна", "Валерия", "Владислава", "Александра", "Мия", "Дарья", "Сабина", "Полина", "София", "Виктория", "Ирина", "Вероника", "Ксения", "Арина", "Вера", "Елизавета", "Варвара", "Екатерина", "Юлия", "Амира", "Милана", "Алиса", "Ярослава", "Любовь", "Софья", "Ника", "Сабрина", "Мадина", "Наталья", "Василиса", "Адель", "Ева", "Мирослава", "Пелагея", "Олеся", "Лилия", "Алёна", "Мелания", "Камила", "Нина", "Кира", "Людмила", "Сафия", "Амина", "Агата", "Маргарита", "Зоя", "Алина", "Ясмина", "Марина", "Диана", "Аиша", "Татьяна", "Таисия", "Ольга", "Кристина", "Стефания", "Майя", "Амалия", "Аглая", "Надежда", "Камилла", "Айлин", "Оливия", "Марьяна", "Элина", "Лидия", "Малика", "Светлана", "Мила", "Эмилия", "Яна", "Есения", "Дарина", "Антонина", "Агния", "Марианна", "Евгения", "Каролина", "Марьям", "Лея", "Анжелика", "Евангелина", "Алия", "Фатима", "Злата", "Эмма", "Карина", "Лиана", "Аделина", "Николь", "Елена", "Альбина"};
string femaleLastNames[] {"Щеглова", "Коновалова", "Еремеева", "Герасимова", "Орлова", "Лаврова", "Назарова", "Абрамова", "Николаева", "Ефимова", "Сорокина", "Румянцева", "Мартынова", "Румянцева", "Морозова", "Селезнева", "Дмитриева", "Николаева", "Моргунова", "Лебедева", "Леонова", "Астахова", "Петрова", "Краснова", "Кошелева", "Дмитриева", "Воронова", "Винокурова", "Васильева", "Белякова", "Родина", "Мухина", "Лаврова", "Завьялова", "Денисова", "Галкина", "Королева", "Еремина", "Зайцева", "Дмитриева", "Кузнецова", "Ефимова", "Калинина", "Лосева", "Уткина", "Павлова", "Ларина", "Гончарова", "Соловьева", "Кузнецова", "Свиридова", "Беляева", "Ефремова", "Кондратова", "Козлова", "Исаева", "Кузнецова", "Смирнова", "Петрова", "Белоусова", "Антонова", "Жилина", "Дорофеева", "Иванова", "Филимонова", "Филатова", "Николаева", "Жарова", "Ткачева", "Виноградова", "Романова", "Борисова", "Корнилова", "Козловская", "Устинова", "Островская", "Гончарова", "Козлова", "Тимофеева", "Балашова", "Смирнова", "Данилова", "Климова", "Абрамова", "Сафонова", "Юдина", "Леонова", "Гусева", "Сергеева", "Грачева", "Гончарова", "Петрова", "Попова", "Давыдова", "Калашникова", "Акимова", "Кузнецова", "Кузнецова", "Давыдова", "Нестерова"};
string femaleSurnames[] {"Ивановна", "Александровна", "Сергеевна", "Николаевна", "Дмитриевна", "Владимировна", "Андреевна", "Егоровна", "Артемовна", "Максимовна", "Ефимовна", "Аркадьевна", "Константиновна", "Павловна", "Валерьевна", "Ярославовна", "Тимофеевна", "Алексеевна", "Васильевна", "Федоровна", "Михайловна", "Даниловна", "Степановна", "Юрьевна", "Анатольевна", "Валентиновна", "Ильинична", "Робертовна", "Кирилловна", "Семёновна", "Александровна", "Аркадьевна", "Владленовна", "Руслановна", "Матвеевна", "Евгеньевна", "Всеволодовна", "Анисимовна", "Борисовна", "Георгиевна", "Кондратовна", "Тихоновна", "Григорьевна", "Станиславовна", "Давидовна", "Аркадьевна", "Егоровна", "Андреевна", "Захаровна", "Давидовна", "Львовна", "Марковна", "Кирилловна", "Тарасовна", "Нестровна", "Богдановна", "Никитична", "Савельевна", "Германовна", "Игоревна", "Авдеевна", "Святославовна", "Евсеевна", "Артемьевна", "Ильична", "Леонидовна", "Мироновна", "Ярославовна", "Лазаревна", "Созоновна", "Прохоровна", "Устиновна", "Артёмовна", "Демидовна", "Филимоновна", "Петровна", "Гавриловна", "Маратовна", "Леонтьевна", "Левовна", "Львовна", "Олеговна", "Кондратиевна", "Арсеньевна", "Зиновьевна", "Андриановна", "Аристарховна", "Иосифовна", "Марковна", "Леонардовна", "Малховна", "Валентиновна", "Пантелеймоновна", "Динховна", "Даздрапермовна", "Михайловна", "Иннокентьевна", "Даниловна", "Сергеевна", "Эзотовна"};
string maleFirstNames[] {"Иван", "Дмитрий", "Александр", "Михаил", "Артем", "Никита", "Сергей", "Максим", "Андрей", "Кирилл", "Павел", "Денис", "Антон", "Алексей", "Тимофей", "Владимир", "Игорь", "Степан", "Константин", "Григорий", "Ярослав", "Егор", "Марк", "Федор", "Даниил", "Владислав", "Тимур", "Яков", "Матвей", "Роман", "Арсений", "Борис", "Пётр", "Евгений", "Давид", "Леонид", "Илья", "Артур", "Эдуард", "Виктор", "Денис", "Станислав", "Руслан", "Савелий", "Мирон", "Макар", "Филипп", "Василий", "Семён", "Вадим", "Савва", "Игнат", "Прохор", "Анатолий", "Валентин", "Фёдор", "Святослав", "Мир", "Ростислав", "Валерий", "Всеволод", "Богдан", "Захар", "Валерий", "Аркадий", "Лев", "Марат", "Назар", "Олег", "Мирза", "Артём", "Самвел", "Карен", "Левон", "Тигран", "Ваган", "Арсен", "Армен", "Давид", "Гевор", "Эльман", "Руфат", "Ян", "Юрий", "Адам", "Эдгар", "Лазарь", "Константин", "Мирослав", "Мстислав", "Владимир", "Святополк", "Ярослав", "Святослав", "Борис", "Вячеслав", "Владислав", "Валентин", "Геннадий", "Вениамин"};
string maleLastNames[] {"Иванов", "Петров", "Смирнов", "Сергеев", "Михайлов", "Федоров", "Волков", "Николаев", "Козлов", "Павлов", "Морозов", "Зайцев", "Соловьев", "Васильев", "Попов", "Алексеев", "Лебедев", "Григорьев", "Степанов", "Семёнов", "Павлов", "Богданов", "Андреев", "Козлов", "Никитин", "Сысоев", "Фёдоров", "Макаров", "Артемьев", "Леонтьев", "Свиридов", "Тимофеев", "Гурьев", "Горбунов", "Филатов", "Краснов", "Куприянов", "Тарасов", "Беляков", "Калинин", "Комаров", "Галкин", "Сорокин", "Лукин", "Медведев", "Цветков", "Афанасьев", "Королев", "Миронов", "Фадеев", "Трофимов", "Мартынов", "Евсеев", "Яковлев", "Панов", "Родин", "Шестаков", "Кондратьев", "Капустин", "Жаров", "Ларин", "Фокин", "Масленников", "Ефимов", "Орлов", "Ларионов", "Константинов", "Вишняков", "Миронов", "Ермаков", "Колесников", "Лыткин", "Афонин", "Тимофеев", "Пестов", "Свищев", "Ломакин", "Луговой", "Мещеряков", "Харитонов", "Абрамов", "Ковалёв", "Костин", "Карпов", "Попов", "Бирюков", "Герасимов", "Казаков", "Тюрин", "Прокопов", "Щербаков", "Ларин", "Чернов", "Львов", "Дубров", "Косухин", "Берия", "Леонтьев", "Ягода", "Джугашвили"};
string maleSurnames[] {"Иванович", "Петрович", "Сергеевич", "Михайлович", "Александрович", "Андреевич", "Владимирович", "Дмитриевич", "Николаевич", "Васильевич", "Алексеевич", "Егорович", "Данилович", "Олегович", "Семёнович", "Павлович", "Викторович", "Федорович", "Максимович", "Тимофеевич", "Константинович", "Станиславович", "Ярославович", "Артёмович", "Никитович", "Евгеньевич", "Львович", "Давидович", "Кириллович", "Борисович", "Степанович", "Игоревич", "Витальевич", "Ильич", "Матвеевич", "Денисович", "Яковлевич", "Романович", "Арсеньевич", "Миронович", "Савельевич", "Владленович", "Леонидович", "Миланович", "Кириллович", "Эдуардович", "Игнатьевич", "Ефимович", "Маркович", "Вадимович", "Григорьевич", "Аполлонович", "Саввич", "Филиппович", "Вениаминович", "Михайлович", "Валерьевич", "Гаврилович", "Русланович", "Климович", "Геннадьевич", "Трофимович", "Кондратович", "Лукич", "Святополкович", "Ярославович", "Степанович", "Филимонович", "Давыдович", "Ярославович", "Измайлович", "Казимирович", "Фирсович", "Мэлсович", "Дамирович", "Фёдорович", "Карпович", "Федотович", "Леонтьевич", "Лазаревич", "Леонидович", "Глебович", "Тарасович", "Владиславович", "Никифорович", "Ларионович", "Онуфриевич", "Лаврович", "Андронович", "Абдулович", "Фомич", "Платонович", "Маркович", "Александрович", "Макарович", "Тарасович", "Львович", "Искандерович", "Тимурович", "Рамзанович"};
string citizenship[] {"РФ", "Украина", "Белорусь", "Казахстан", "Монголия"};

string word;

list<string> commands;
bool flag;
string error;
string answer;

void execute(int i, char* buf, list<Person>& base, fstream& f){
	try{
		srand(time(NULL));
		error = "Seems like your command is unknown or missing arguments\n";
		flag = true;
		commands.clear();
		string line(buf);
		stringstream s(line);
		while(s >> word){
			commands.push_back(word);
		}
		auto it = commands.begin();
		if(*it == "?"){
			if(++it != commands.end()){
				flag = false;
				error = "There are too much arguments. Type ? to see the list of commands again\n";
			} else {
				answer = "List of commands: \n1. Exit\n2. Print\n3. Generate [number of people]\n4. Save\n5. Load\n6. Add [first name, last name, surname, date of birth, citizenship, exit permit, rating]\n7. Remove [last name]\n8. Find lastname [name] || exitpermit [exitpermit] || rating [< or > smth] || date [date] (or multiple options using && between them)\n9. Size\n";
				writeToClient(i, answer.data());
			}
		} else if (*it == "Exit"){
			if(++it != commands.end()){
				flag = false;
				error = "There are too much arguments. Type ? to see the list of commands again\n";
			}
		} else if (*it == "Print"){
			if(++it != commands.end()){
				flag = false;
				error = "There are too much arguments. Type ? to see the list of commands again\n";
			} else {
				writeToClient(i, print(i, base));
			}
		} else if (*it == "Generate"){
			if(++it == commands.end()){
				flag = false;
				error = "Error. Command expects number of people\n";
			} else {
				if(!check_int(*it)) {
					flag = false;
					error = "Error. Number of people should be integer\n";
				} else {
					int number = stoi(*it);
					if(++it != commands.end()){
						flag = false;
						error = "There are too much arguments. Type ? to see the list of commands again\n";
					} else {
						if(generate(base, number)) {
							answer = "Successfully generated!\n";
							writeToClient(i, answer.data());
						}
						save(f, base);
					}
				}
			}
		} else if (*it == "Save"){
			if(++it != commands.end()){
				flag = false;
				error = "There are too much arguments. Type ? to see the list of commands again\n";
			} else {
				writeToClient(i, save(f, base));
			}
		} else if (*it == "Load"){
			if(++it != commands.end()){
				flag = false;
				error = "There are too much arguments. Type ? to see the list of commands again\n";
			} else {
				writeToClient(i, load(f, base));
			}
		} else if (*it == "Size"){
			if(++it != commands.end()){
				flag = false;
				error = "There are too much arguments. Type ? to see the list of commands again\n";
			} else {
				int k = base.size();
				if(k == 1) {
					answer = "\nDatabase contains " + to_string(base.size()) + " person\n";
					writeToClient(i, answer.data());
				} else {
					answer = "\nDatabase contains " + to_string(base.size()) + " people\n";
					writeToClient(i, answer.data());
				}
			}
		} else if (*it == "Add"){
			string lastname;
			string firstname;
			string surname;
			Date dateofbirth;
			string citizenship;
			bool exitpermit;
			double rating;
			if(++it == commands.end()){
				flag = false;
			} else {
				lastname = *(it);
				if(++it == commands.end()){
					flag = false;
				} else {
				firstname = *(it);
				if(++it == commands.end()){
					flag = false;
				} else {
				surname = *(it);
				if(++it == commands.end()){
					flag = false;
				} else {
				if(check_date(*it)){
					dateofbirth = stodate(*(it));
				} else {
					flag = false;
					error = "Date format is incorrect\n";
				}
				if(++it == commands.end()){
					flag = false;
				} else {
				citizenship = *(it);
				if(++it == commands.end()){
					flag = false;
				} else {
				exitpermit = stoi(*(it));
				if(++it == commands.end()){
					flag = false;
				} else rating = stof(*(it));
			}}}}}}
			if((++it != commands.end()) && flag) {
				flag = false;
				error = "There are too much arguments. Type ? to see the list of commands again\n";
			}
			if(flag){
				writeToClient(i, add(base, lastname, firstname, surname, dateofbirth, citizenship, exitpermit, rating));
			}
		} else if (*it == "Find"){
			if(++it == commands.end()){
				flag = false;
			} else {
				string lastname = "";
				bool is_lastname = false;
				double rating_greater = 0;
				double rating_less = 0;
				Date date;
				bool is_date = false;
				bool is_rating = false;
				bool is_greater = false;
				bool is_less = false;
				bool exitPermit = 0;
				bool is_exitPermit = false;
				do{
					if(*it == "lastname"){
						if(++it == commands.end()) {
							flag = false;
							break;
						} else {
							lastname = *(it);
							is_lastname = true;
						}
					} else if(*it == "rating"){
						if(++it == commands.end()){
							flag = false;
							break;
						} else {
								if(*it != "<" && *it != ">"){
									flag = false;
									break;
								} else {
									if(*it == ">") {
										if(++it == commands.end()){
											flag = false;
											break;
										}
										if(check_double(*it)){
											rating_greater = stof(*(it));
											if(rating_greater > 1 || rating_greater < 0){
												flag = false;
												error = "Rating is a real number between 0 and 1\n";
											} else is_greater = true;
										} else {
											flag = false;
											error = "Incorrect rating\n";
											break;
										}
										
									} else{
										if(++it == commands.end()){
											flag = false;
											break;
										}
										if(check_double(*it)){
											rating_less = stof(*(it));
											if(rating_less > 1 || rating_less < 0){
												flag = false;
												error = "Rating is a real number between 0 and 1\n";
											} else is_less = true;
										} else {
											flag = false;
											error = "Incorrect rating\n";
											break;
										}
									}
									is_rating = true;
								}
							}
					} else if(*it == "date"){
						if(++it == commands.end()){
							flag = false;
							break;
						} else {
							if(check_date(*it)) {
								date = *it;
								is_date = true;
							} else {
								flag = false;
								error = "Date format is incorrect\n";
								break;
							}
						}
					} else if(*it == "exitpermit"){
						if(++it == commands.end()){
							flag = false;
							break;
						} else {
							if(check_bool(*it)){
								exitPermit = stoi(*(it));
								is_exitPermit = true;
							} else {
								flag = false;
								error = "Exitpermit can only be 0 or 1\n";
								break;
							}
						}
					} else {
						flag = false;
						break;
					}
					if(++it == commands.end()) break;
					if(*(it) != "&&") {
						flag = false;
						break;
					}
					it++;
				} while(1);
				if(flag){
					if(!find(i, base, lastname, is_lastname, rating_greater, rating_less, is_rating, is_greater, is_less, exitPermit, is_exitPermit, date, is_date)){
						answer = "Person hasn't found\n";
						writeToClient(i, answer.data());
					}
				} 
			}
		} else if (*it == "Remove"){
			if(++it == commands.end()){
				flag = false;
			} else {
				string _lastName = *it;
				if(++it != commands.end()){
					flag = false;
					error = "There are too much arguments. Type ? to see the list of commands again\n";
				} else {
					writeToClient(i, remove(base, _lastName));
				}
			}
		} else {
			flag = false;
		}
		if(!flag) writeToClient(i, error.data());
	}
	catch (invalid_argument const& ex){
		answer = "Incorrect number\n";
		writeToClient(i, answer.data());
    }
}

Date stodate(string a){
	stringstream str(a);
	string s;
	int d, m, y;
	getline(str, s, '.');
	d = stoi(s);
	getline(str, s, '.');
	m = stoi(s);
	getline(str, s);
	y = stoi(s);
	Date date(d, m, y);
	return date;
}

bool check_date(string s){
	stringstream stream(s);
	string w;
	int number;
	getline(stream, w, '.');
	if(!check_int(w)) return false;
	number = stoi(w);
	if(number < 1 || number > 31) return false;
	getline(stream, w, '.');
	if(!check_int(w)) return false;
	number = stoi(w);
	if(number < 1 || number > 12) return false;
	getline(stream, w);
	if(!check_int(w)) return false;
	number = stoi(w);
	if(number < 1924 || number > 2024) return false;
	return true;
}

bool check_int(string s){
	int size = s.size();
	if(size == 0) return false;
	if((s[0] < '0' || s[0] > '9') && (s[0] != '-') && (s[0] != '+')) return false;
	for(int i = 1; i < size; i++){
		if(s[i] < '0' || s[i] > '9') return false;
	}
	return true;
}

bool check_bool(string s){
	int size = s.size();
	if(size != 1) return false;
	if(s[0] == '0' || s[0] == '1') return true;
	return false;
}

bool check_double(string s){
	int size = s.size();
	for(int i = 0; i < size; i++){
		if((s[i] < '0' || s[i] > '9') && s[i] != '.') return false;
	}
	return true;
}

bool if_empty(fstream& f){
	return f.peek() == ifstream::traits_type::eof();
}

char* load(fstream& f, list<Person>& base)
{
	f.open("database.txt", ios_base::in);
	if(if_empty(f)){
		f.close();
		return (char*)"Database.txt is empty\n";
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
	return (char*)"Successfully loaded!\n";
}

char* add(list<Person>& base, string lastname, string firstname, string surname, Date dateofbirth, string citizenship, bool exitpermit, double rating)
{
	Person one;
	one.pushLastName(lastname);
	one.pushFirstName(firstname);
	one.pushSurname(surname);
	one.pushDateOfBirth(dateofbirth);
	one.pushCitizenship(citizenship);
	one.pushExitPermit(exitpermit);
	one.pushRating(rating);
	base.push_back(one);
	return (char*)"Successfully added!";
}

char* print(int i, list<Person>& base)
{
	string answer;
	if(base.empty()) {
		return (char*)"Database is empty\n";
	} else {
		for(auto it = base.begin(); it != base.end(); it++){
			(*it).print(i);
		}
	}
	return (char*)"Successfully printed!";
}

char* save(fstream& f, list<Person>& base)
{
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
	return (char*)"Successfully saved!";
}

bool generate(list<Person>& base, int k)
{
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

char* remove(list<Person>& base, string line)
{
	bool fl = false;
	for(auto it = base.begin(); it != base.end(); it++){
		if((*it).getLastName() == line){
			it = base.erase(it);
			it--;
			fl = true;
		}
	}
	if(fl) return (char*)"Successfully removed!\n";
	return (char*)"There are no people with such name\n";
}

bool find(int i, list<Person>& base, string lastname, bool is_lastname, double rating_greater, double rating_less, bool is_rating, bool is_greater, bool is_less, bool exitPermit, bool is_exitPermit, Date date, bool is_date)
{
	bool fl = false;
	for(auto it = base.begin(); it != base.end(); it++){
		if(((is_lastname && (*it).getLastName() == lastname) || !is_lastname)  && ((is_exitPermit && (*it).getExitPermit() == exitPermit) || !is_exitPermit) && ((is_date && (*it).getDateOfBirth() == date) || !is_date)) {
			if(is_rating){
				if(is_greater){
					if((*it).getRating() <= rating_greater) continue;
				}
				if(is_less){
					if((*it).getRating() >= rating_less) continue;
				}
			}
			(*it).print(i);
			fl = true;
		}
	}
	return fl;
}

string person_to_str(Person p){
	stringstream s;
	s << p.getLastName() << " " << p.getFirstName() << " " << p.getSurname() << " " << p.getDateOfBirth() << " " << p.getCitizenship() << " " << p.getExitPermit() << " " << p.getRating();
	return s.str();
}