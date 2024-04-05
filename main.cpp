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
		auto it = commands.begin();
		if(*it == "?"){
			if(++it != commands.end()){
				cout << "Unknown command. Please, try again.\n";
			} else {
				cout << "List of commands: \n1. Exit\n2. Print\n3. Generate [number of people]\n4. Save\n5. Load\n6. Add [first name, last name, surname, date of birth, citizenship, exit permit, rating]\n7. Remove [last name]\n8. Find name [name] || date [date] || rating [< or > smth]\n9. Size\n";
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
		/*
		
		
		else if (line == "Add"){
			if(add(base)) cout << "Successfully added!\n";
		}
		
		else if (line == "Find"){
			cin >> line;
			if(line == "name"){
				string name;
				cin >> name;
				if(!findName(name, base)) cout << "Person hasn't found.\n";
			}
			if(line == "date"){
				Date d;
				cin >> d;
				if(!findDate(d, base)) cout << "There are no people that were born in " << d << "\n";
			}
			if(line == "rating"){
				string sign;
				double r;
				cin >> sign;
				cin >> r;
				if(r > 1 || r < 0) cout << "Rating is a real number between 0 and 1.\n";
				if(!sign.compare("<")){
					if(!findRating(r, 0, base)) cout << "There are no people rated less than " << r << "\n";
				} else {
					if(!findRating(r, 1, base)) cout << "There are no people rated greater than " << r << "\n";
				}
			}
		} 
	}*/
	return 0;
}