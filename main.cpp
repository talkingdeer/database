#include "class.h"

int main()
{
	cout<< "\nThis is database of Migration Service. Type ? for more info.\n";
	string line, word;
	list<Person> base;
	list<string> commands;
	fstream f;
	srand(time(NULL));
	
	try{
		if(load(f, base)){
		cout << "Database has loaded automatically.\n";
		} else {
			cout << "Couldn't load database from database.txt\n";
		}
		while(1){
			bool flag = true;
			commands.clear();
			getline(cin, line);
			stringstream s(line);
			while(s >> word){
				commands.push_back(word);
			}
			list<string>::const_iterator it = commands.begin();
			if(*it == "?"){
				if(++it != commands.end()){
					flag = false;
				} else {
					cout << "List of commands: \n1. Exit\n2. Print\n3. Generate [number of people]\n4. Save\n5. Load\n6. Add [first name, last name, surname, date of birth, citizenship, exit permit, rating]\n7. Remove [last name]\n8. Find lastname [name] || exitpermit [exitpermit] || rating [< or > smth] (or multiple options using && between them)\n9. Size\n";
				}
			} else if (*it == "Exit"){
				if(++it != commands.end()){
					flag = false;
				} else {
					break;
				}
			} else if (*it == "Print"){
				if(++it != commands.end()){
					flag = false;
				} else {
					print(base);
				}
			} else if (*it == "Generate"){
				if(++it == commands.end()){
					flag = false;
				} else {
					int number = stoi(*it);
					if(++it != commands.end()){
						flag = false;
					} else {
						if(generate(base, number)) cout << "Successfully generated!\n";
						save(f, base);
					}
				}
			} else if (*it == "Save"){
				if(++it != commands.end()){
					flag = false;
				} else {
					if(save(f, base)) cout << "Successfully saved!\n";
				}
			} else if (*it == "Load"){
				if(++it != commands.end()){
					flag = false;
				} else {
					if(load(f, base)) cout << "Successfully loaded!\n";
				}
			} else if (*it == "Size"){
				if(++it != commands.end()){
					flag = false;
				} else {
					int k = base.size();
					if(k == 1) {
						cout << "...\nDatabase contains " << base.size() << " person.\n";
					} else {
						cout << "...\nDatabase contains " << base.size() << " people.\n";
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
					dateofbirth = stodate(*(it));
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
				if(++it != commands.end()) flag = false;
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
					bool is_rating = false;
					bool is_greater = false;
					bool is_less = false;
					bool exitPermit = 0;
					bool is_exitPermit = false;
					if(*it == "lastname"){
						if(++it == commands.end()) {
							flag = false;
						} else {
							lastname = *(it);
							is_lastname = true;
						}
					} else if(*it == "rating"){
						if(++it == commands.end()){
							flag = false;
						} else {
							if(*it != "<" && *it != ">"){
								flag = false;
							} else {
								if(*it == ">") is_greater = true;
								if(*it == "<") is_less = true;
								if(++it == commands.end()){
									flag = false;
								} else {
									if(is_greater) {
										rating_greater = stof(*(it));
									} else {
										rating_less = stof(*(it));
									}
									is_rating = true;
								}
							}
						}
					} else if(*it == "exitpermit"){
						if(++it == commands.end()){
							flag = false;
						} else {
							int _exitPermit = stoi(*(it));
							if(_exitPermit == 0 || _exitPermit == 1){
								exitPermit = _exitPermit;
								is_exitPermit = true;
							} else {
								flag = false;
							}
						}
					} else {
						flag = false;
					}
					
					
					if(++it != commands.end()) {
						while(1){
							if(*(it++) != "&&"){
								flag = false;
								break;
							}
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
											is_greater = true;
											rating_greater = stof(*(it));
										} else{
											if(++it == commands.end()){
												flag = false;
												break;
											}
											is_less = true;
											rating_less = stof(*(it));
										}
										is_rating = true;
									}
								}
							} else if(*it == "exitpermit"){
								if(++it == commands.end()){
									flag = false;
									break;
								} else {
									int _exitPermit = stoi(*(it));
									if(_exitPermit == 0 || _exitPermit == 1){
										exitPermit = _exitPermit;
										is_exitPermit = true;
									} else {
										flag = false;
										break;
									}
								}
							} else {
								flag = false;
								break;
							}
							if(++it == commands.end()) break;
						}	
					}
					if(flag) if(!find(base, lastname, is_lastname, rating_greater, rating_less, is_rating, is_greater, is_less, exitPermit, is_exitPermit)) cout << "Person hasn't found.\n";
				}
			} else if (*it == "Remove"){
				if(++it == commands.end()){
					flag = false;
				} else {
					string _lastName = *it;
					if(++it != commands.end()){
						flag = false;
					} else {
						if(remove(base, _lastName)) {
						cout << "Successfully removed!\n";
						} else {
							cout << "There are no people with such name.\n";
						}
					}
				}
			} else {
				flag = false;
			}
			if(!flag) cout << "Unknown command. Please, try again.\n";
		}
	}
	catch (invalid_argument const& ex){
		cout << "Incorrect number: " << ex.what() << '\n';
    }
	return 0;
}