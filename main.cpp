#include "class.h"

int main()
{
	cout<< "\nThis is database of Migration Service. Type ? for more info.\n";
	string line, word;
	list<Person> base;
	list<string> commands;
	fstream f;
	srand(time(NULL));
	
	if(load(f, base)){
		cout << "Database has loaded automatically.\n";
	} else {
		cout << "Couldn't load database from database.txt\n";
	}
	
	while(1){
		commands.clear();
		getline(cin, line);
		stringstream s(line);
		while(s >> word){
			commands.push_back(word);
		}
		list<string>::const_iterator it = commands.begin();
		if(*it == "?"){
			if(++it != commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				cout << "List of commands: \n1. Exit\n2. Print\n3. Generate [number of people]\n4. Save\n5. Load\n6. Add [first name, last name, surname, date of birth, citizenship, exit permit, rating]\n7. Remove [last name]\n8. Find lastname [name] || exitpermit [exitpermit] || rating [< or > smth] (or multiple options using && between them)\n9. Size\n";
			}
		} else if (*it == "Exit"){
			if(++it != commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				break;
			}
		} else if (*it == "Print"){
			if(++it != commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				print(base);
			}
		} else if (*it == "Generate"){
			if(++it == commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				int number = stoi(*it);
				if(++it != commands.end()){
					cout << "Unknown command. Please, try again.\n";
				} else {
					if(generate(base, number)) cout << "Successfully generated!\n";
				}
			}
		} else if (*it == "Save"){
			if(++it != commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				if(save(f, base)) cout << "Successfully saved!\n";
			}
		} else if (*it == "Load"){
			if(++it != commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				if(load(f, base)) cout << "Successfully loaded!\n";
			}
		} else if (*it == "Size"){
			if(++it != commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				cout << "...\nDatabase contains " << base.size() << " people.\n";
			}
		} else if (*it == "Add"){
			if(++it == commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				if(add(base, it)) cout << "Successfully added!\n";
			}
		} else if (*it == "Find"){
			if(++it == commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				string lastname = "";
				bool is_lastname = false;
				double rating = 0;
				bool is_rating = false;
				bool is_greater = false;
				bool exitPermit = 0;
				bool is_exitPermit = false;
				bool flag = true;
				if(*it == "lastname"){
						lastname = *(++it);
						is_lastname = true;
						it++;
				} else if(*it == "rating"){
					it++;
					if(*it != "<" && *it != ">"){
						cout << "Unknown command. Please, try again.\n";
						break;
					}
					if(*it == ">") is_greater = true;
					rating = stof(*(++it));
					is_rating = true;
					it++;
				} else if(*it == "exitpermit"){
					exitPermit = stoi(*(++it));
					is_exitPermit = true;
					it++;
				} else {
					cout << "Unknown command. Please, try again.\n";
					flag = false;
				}
				
				while(it != commands.end() && flag){
					if(*(it++) != "&&"){
						cout << "Unknown command. Please, try again.\n";
						break;
					} else if(*it == "lastname"){
						lastname = *(++it);
						is_lastname = true;
						it++;
					} else if(*it == "rating"){
						it++;
						if(*it != "<" && *it != ">"){
							cout << "Unknown command. Please, try again.\n";
							break;
						}
						if(*it == ">") is_greater = true;
						if(++it == commands.end()){
							cout << "Unknown command. Please, try again.\n";
							break;
						}
						rating = stof(*(it));
						is_rating = true;
						it++;
					} else if(*it == "exitpermit"){
						exitPermit = stoi(*(++it));
						is_exitPermit = true;
						it++;
					} else if(*it == "&&"){
						continue;
					} else {
						break;
					}
				}
				if(is_lastname || is_rating || is_exitPermit) {
					if(!find(base, lastname, is_lastname, rating, is_rating, is_greater, exitPermit, is_exitPermit)) cout << "Person hasn't found.\n";
				}
			}
		} else if (*it == "Remove"){
			if(++it == commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				if(remove(base, *it)) {
					cout << "Successfully removed!\n";
				} else {
					cout << "There are no people with such name.\n";
				}
			}
		} else {
			cout << "Unknown command. Please, try again.\n";
		}
	}
	return 0;
}