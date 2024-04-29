#pragma once
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <list>
#include <sstream>
using namespace std;

int readFromClient(int fd, char *buf);
void writeToClient (int fd, char *buf);

class Date;
class Person;
Date stodate(string a);
bool check_date(string s);
bool check_int(string s);
bool check_bool(string s);
bool check_double(string s);
char* load(fstream& f, list<Person>& base);
char* add(list<Person>& base, string lastname, string firstname, string surname, Date dateofbirth, string citizenship, bool exitpermit, double rating);
char* print(int i, list<Person>& base);
char* save(fstream& f, list<Person>& base);
bool generate(list<Person>& base, int k);
char* remove(list<Person>& base, string line);
bool find(int i, list<Person>& base, string lastname, bool is_lastname, double rating_greater, double rating_less, bool is_rating, bool is_greater, bool is_less, bool exitPermit, bool is_exitPermit, Date date, bool is_date);
void execute(int i, char* buf, list<Person>& base, fstream& f);
string person_to_str(Person person);

class Date
{
	int day;
	int month;
	int year;
	
public:
	Date(){
		month = rand() % 12 + 1 ;
		year =  rand() % 100 + 1924;
		if(month == 2) {
			day = rand() % 28 + 1;
		} else if(month == 4 || month == 6 || month == 9 || month == 11) {
			day = rand() % 30 + 1;
		} else {
			day = rand() % 31 + 1;
		}
		
	}
	Date(int day, int month, int year){
		this -> day = day;
		this -> month = month;
		this -> year = year;
	}
	Date(const Date& date){
		this -> day = date.day;
		this -> month = date.month;
		this -> year = date.year;
	}
	friend ostream& operator<<(ostream& stream, const Date& date)
	{
		if(date.day < 10){
			stream << 0 << date.day;
		} else {
			stream << date.day;
		}
		stream << '.';
		if(date.month < 10){
			stream << 0 << date.month;
		} else {
			stream << date.month;
		}
		stream << '.';
		stream << date.year;
		return stream;
	}
	friend fstream& operator>>(fstream& stream, Date& date)
	{
		string s;
		getline(stream, s, '.');
		date.day = stoi(s);
		getline(stream, s, '.');
		date.month = stoi(s);
		stream >> s;
		date.year = stoi(s);
		return stream;
	}
	
	friend istream& operator>>(istream& stream, Date& date)
	{
		string s;
		getline(stream, s, '.');
		date.day = stoi(s);
		getline(stream, s, '.');
		date.month = stoi(s);
		stream >> s;
		date.year = stoi(s);
		return stream;
	}
	
	friend bool operator==(const Date& date1, const Date& date2)
	{
		if(date1.day == date2.day && date1.month == date2.month && date1.year == date2.year) return true;
		return false;
	}
	
	Date& operator=(const Date& date)
	{
		day = date.day;
		month = date.month;
		year = date.year;
		return *this;
	}
	
	Date& operator=(const string& date)
	{
		stringstream stream(date);
		string s;
		getline(stream, s, '.');
		day = stoi(s);
		getline(stream, s, '.');
		month = stoi(s);
		stream >> s;
		year = stoi(s);
		return *this;
	}
};

class Person
{
	string lastName;
	string firstName;
	string surname;
	Date dateOfBirth;
	string citizenship;
	bool exitPermit;
	double rating;
	
public:
	Person(string lastName, string firstName, string surname, Date dateOfBirth, string citizenship, bool exitPermit, double rating){
		this -> lastName = lastName;
		this -> firstName = firstName;
		this -> surname = surname;
		this -> dateOfBirth = dateOfBirth;
		this -> citizenship = citizenship;
		this -> exitPermit = exitPermit;
		this -> rating = rating;
	}
	Person(){}
	void pushLastName(string a){
		lastName = a;
	}
	void pushFirstName(string a){
		firstName = a;
	}
	void pushSurname(string a){
		surname = a;
	}
	void pushCitizenship(string a){
		citizenship = a;
	}
	void pushExitPermit(bool a){
		exitPermit = a;
	}
	void pushExitPermit(string a){
		if(a == "0"){
			exitPermit = 0;
		} else{
			exitPermit = 1;
		}
	}
	void pushDateOfBirth(Date a){
		dateOfBirth = a;
	}
	void pushDateOfBirth(string a){
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
		dateOfBirth = date;
	}
	void pushRating(double a){
		rating = a;
	}
	void pushRating(string a){
		rating = stof(a);
	}
	string getFirstName(){
		return firstName;
	}
	string getLastName(){
		return lastName;
	}
	string getSurname(){
		return surname;
	}
	Date getDateOfBirth(){
		return dateOfBirth;
	}
	string getCitizenship(){
		return citizenship;
	}
	bool getExitPermit(){
		return exitPermit;
	}
	double getRating(){
		return rating;
	}
	void print(){
		cout << lastName << " " << firstName << " " << surname << " " << dateOfBirth << " " << citizenship << " " << exitPermit << " " << rating <<  endl;
	}
	void print(fstream& f){
		f << lastName << " " << firstName << " " << surname << " " << dateOfBirth << " " << citizenship << " " << exitPermit << " " << rating;
	}
	void print(int i){
		stringstream s;
		s << lastName << " " << firstName << " " << surname << " " << dateOfBirth << " " << citizenship << " " << exitPermit << " " << rating << '\n';
		string tmp = s.str();
		writeToClient(i, (char*)tmp.c_str());
	}
	
};