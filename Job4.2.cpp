// Operator overloading
// Job4.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>
#include <conio.h>
using namespace std;

class String {
/*******************************************************************************************/
	friend ostream &operator << (ostream &out, const String &p);	// friend määritys outputtiin
	friend String operator + (const String &p, const String &p2);				// friend määritys + operaattoriin

/*******************************************************************************************/
public:
	String(char *object);	// constructor
	String(String &p);			// copy constructor jossa viite parametri
	~String();				//destructor

	void list();			// norm luokkafunktion määritys
/*********************************************************************************************/

	String();				// construktori jossa ei parametreja.
	String &operator = (String &param);		//operator overloading funk. määritys jossa viiteoperaattori sekä viite parametri

	String &operator++();		// pre-increment
    String operator++(int);		// post-increment
	char &operator[](int i);		// indexing overload

/********************************************************************************************/
private:
	char *c_string;			// luodaan luokan sisäinen dynamic data member
};
void f(String s);		// ordinary function, not a member of the class

int main() {
	
	
	/*String s("abcdefg");
	cout << s++ << endl;	// post
	cout << ++s << endl;	// pre
	return 0;*/
	
	String s("abcdefg");
	for (int i = 0; i < 7; i++) {
		cout << s[i] << " ";
	}

	s[4] = 'X';

	for (int i = 0; i < 7; i++) {
		cout << s[i] << " ";
	}	
	return 0;
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
							//cout << s.c_string << endl;
	s.list();
}
/*******************************************************************/





String::String() {		// constructor toteutus, ei tarvitse mitään sinne.
						//c_string = "Undefined";
}
String &String::operator = (String &param) {
	if (this != &param) {		//avoid damages in self assignment
		delete c_string;
		c_string = new char[strlen(param.c_string) + 1];		// tehdään uusi tila dynaamiseen muistiin.
		strcpy(c_string, param.c_string);					// kopioidaan normaalisti
	}
	return *this;
}

ostream &operator << (ostream &out, const String &p) {	// friend toteutus outputtiin <<
	out << p.c_string << endl;
	return out;
}
String operator + (const String &p, const String &p2) {
	char *joku;		// luodaan char tyyppinen osoitin, kuten String luokassakin tehdään.
	joku = new char[(strlen(p.c_string)) + (strlen(p2.c_string)) + 1];	// luodaan char taulukko ja varataan muistista tarvittava molempien merkkijonojen merkkimäärä dynaamisesti, + lopetusmerkki '0'
	strcpy(joku, p.c_string);	// kopioidaan merkkijonot luotuun taulukkoon
	strcat(joku, p2.c_string);	// -||-

	String sum(joku);	// luodaan uusi String olio jonka sisällä yhdistetty merkkijono.

	return sum;		// palautetaan String olio.
}
String String::operator++(int) {	// post increment
	
	String old = *this;	// kopioidaan mainin String olio
	strcat(c_string, "X");
	return old;
}
String &String::operator++() {	// pre increment

	char *joku;
	joku = new char[strlen(c_string) + 2];
	strcpy(joku, c_string);
	strcat(joku, "X");
	c_string = joku;
	return *this;
}

char &String::operator[](int i) {	
	
	return c_string[i];
}
