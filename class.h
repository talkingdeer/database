#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <list>
#include <sstream>
using namespace std;

class Date;
class Person;
bool load(fstream& f, list<Person>& base);
bool add(list<Person>& base, list<string>::const_iterator it);
bool print(list<Person>& base);
bool save(fstream& f, list<Person>& base);
bool generate(list<Person>& base, int k);
bool remove(list<Person>& base, string line);
bool find(list<Person>& base, string lastname, bool is_lastname, double rating, bool is_rating, bool is_greater, bool exitPermit, bool is_exitPermit);
bool findName(string name, list<Person>& base);
bool findDate(Date d, list<Person>& base);
bool findRating(double r, bool sign, list<Person>& base);

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
	Date getDate(){
		return dateOfBirth;
	}
	double getRating(){
		return rating;
	}
	
	bool getExitPermit(){
		return exitPermit;
	}
	
	void print(){
		cout << lastName << " " << firstName << " " << surname << " " << dateOfBirth << " " << citizenship << " " << exitPermit << " " << rating <<  endl;
	}
	void print(fstream& f){
		f << lastName << " " << firstName << " " << surname << " " << dateOfBirth << " " << citizenship << " " << exitPermit << " " << rating;
	}
};