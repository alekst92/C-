// Job3.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class String {
public:
	String(char *object);	// constructor
	String(String &p);			// copy constructor jossa viite parametri
	~String();				//destructor

	void list();			// function
private:
	char *c_string;			// luodaan dynamic data member
};
void f(String s);		// ordinary function, not a member of the class

int main() {
	String s("abcdefg");
	s.list();
	f(s);			//kutsutaan copy constructoria
	s.list();
}

String::String(char *object) {			// constructor implementation
	c_string = new char[strlen(object) + 1];
	strcpy(c_string, object);			// tallentaa luodun object-merkkijonon c_string-merkkijonoon
}
String::String(String &p) {					// copy constructor
	c_string = new char[strlen(p.c_string) + 1];
	strcpy(c_string, p.c_string);
}
String::~String() {			// destructor implementation
	cout << "destructor done." << endl;
	delete c_string;
}
void String::list() {						// luokkafunktion toteutus
	cout << c_string << endl;
}

/*****************************************************************/
void f(String s) {			// norm.funtion toteutus arvo parametrilla
	//cout << s.list << endl;
	s.list();
}

