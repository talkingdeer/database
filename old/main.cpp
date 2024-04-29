#include "class.h"

int main()
{
	cout<< "\nThis is database of Migration Service. Type ? for more info\n";
	string line, word;
	list<Person> base;
	list<string> commands;
	bool flag;
	string error;
	fstream f;
	srand(time(NULL));
	
	try{
		if(load(f, base)){
		cout << "Database has loaded automatically\n";
		} else {
			cout << "Couldn't load database from database.txt\n";
		}
		while(1){
			error = "Seems like your command is unknown or missing arguments\n";
			flag = true;
			commands.clear();
			getline(cin, line);
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
					cout << "List of commands: \n1. Exit\n2. Print\n3. Generate [number of people]\n4. Save\n5. Load\n6. Add [first name, last name, surname, date of birth, citizenship, exit permit, rating]\n7. Remove [last name]\n8. Find lastname [name] || exitpermit [exitpermit] || rating [< or > smth] || date [date] (or multiple options using && between them)\n9. Size\n";
				}
			} else if (*it == "Exit"){
				if(++it != commands.end()){
					flag = false;
					error = "There are too much arguments. Type ? to see the list of commands again\n";
				} else {
					break;
				}
			} else if (*it == "Print"){
				if(++it != commands.end()){
					flag = false;
					error = "There are too much arguments. Type ? to see the list of commands again\n";
				} else {
					print(base);
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
							if(generate(base, number)) cout << "Successfully generated!\n";
							save(f, base);
						}
					}
				}
			} else if (*it == "Save"){
				if(++it != commands.end()){
					flag = false;
					error = "There are too much arguments. Type ? to see the list of commands again\n";
				} else {
					if(save(f, base)) cout << "Successfully saved!\n";
				}
			} else if (*it == "Load"){
				if(++it != commands.end()){
					flag = false;
					error = "There are too much arguments. Type ? to see the list of commands again\n";
				} else {
					if(load(f, base)) cout << "Successfully loaded!\n";
				}
			} else if (*it == "Size"){
				if(++it != commands.end()){
					flag = false;
					error = "There are too much arguments. Type ? to see the list of commands again\n";
				} else {
					int k = base.size();
					if(k == 1) {
						cout << "...\nDatabase contains " << base.size() << " person\n";
					} else {
						cout << "...\nDatabase contains " << base.size() << " people\n";
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
					if(add(base, lastname, firstname, surname, dateofbirth, citizenship, exitpermit, rating)) cout << "Successfully added!\n";
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
					if(flag) if(!find(base, lastname, is_lastname, rating_greater, rating_less, is_rating, is_greater, is_less, exitPermit, is_exitPermit, date, is_date)) cout << "Person hasn't found.\n";
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
						if(remove(base, _lastName)) {
						cout << "Successfully removed!\n";
						} else {
							cout << "There are no people with such name\n";
						}
					}
				}
			} else {
				flag = false;
			}
			if(!flag) cout << error;
		}
	}
	catch (invalid_argument const& ex){
		cout << "Incorrect number: " << ex.what() << '\n';
    }
	return 0;
}