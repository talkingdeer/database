#include "class.h"

int main()
{
	cout<< "\nThis is database of Migration Service. Type ? for more info.\n";
	string line;
	list<Person> base;
	fstream f;
	srand(time(NULL));
	
	if(load(f, base)){
		cout << "Database has loaded automatically.\n";
	} else {
		cout << "Couldn't load database from database.txt\n";
	}
	
	while(1){
		cin >> line;
	if(line == "?") cout << "List of commands: \n1. Exit\n2. Print\n3. Generate [number of people]\n4. Save\n5. Load\n6. Add [first name, last name, surname, date of birth, citizenship, exit permit, rating]\n7. Remove [full name]\n8. Find name [name] || date [date] || rating [< or > smth]\n9. Size\n";
		else if (line == "Exit"){
			break;
		}
		else if (line == "Print"){
			print(base);
		}
		else if (line == "Generate"){
			if(generate(base)) cout << "Successfully generated!\n";
		}
		else if (line == "Save"){
			if(save(f, base)) cout << "Successfully saved!\n";
		}
		else if (line == "Load"){
			if(load(f, base)) cout << "Successfully loaded!\n";
		}
		else if (line == "Add"){
			if(add(base)) cout << "Successfully added!\n";
		}
		else if (line == "Remove"){
			if(remove(base)) {
				cout << "Successfully removed!\n";
			} else {
				cout << "There are no people with such name.\n";
			}
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
		} else if (line == "Size"){
			cout << "...\nDatabase contains " << base.size() << " people.\n";
		} else {
			cout << "Unknown command. Please, try again.\n";
		}
	}
	return 0;
}