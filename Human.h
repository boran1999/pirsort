#pragma once
#include<iostream>
#include <fstream>
#include<vector>
#include "sort.h"

using namespace std;

class Human {
public:
	Human(char* sstr)
	{
		str = new char[strlen(sstr) + 1];
		for (int i = 0; i < strlen(sstr); i++)
			str[i] = sstr[i];
		str[strlen(sstr)] = 0;
	}

	char* get()
	{
		return str;
	}
	void operator =(const Human& r);
	bool operator ==(const Human& h) const;
	bool operator >(const Human& h) const;
	bool operator <(const Human& h) const;

private:
	char* str;
};

void Human::operator =(const Human& r) {
	str = new char[strlen(r.str) + 1];
	for (int i = 0; i < strlen(r.str); i++) {
		str[i] = r.str[i];
	}
	str[strlen(r.str)] = 0;
}

bool Human::operator ==(const Human& r) const {
	if (strcmp((*this).str, r.str) == 0)
		return 1;
	return 0;
}

bool Human::operator >(const Human& r) const {
	if (strcmp((*this).str, r.str) > 0)
		return 1;
	return 0;
}

bool Human::operator <(const Human& r) const {
	if (strcmp((*this).str, r.str) < 0)
		return 1;
	return 0;
}

bool read_hum(const char* filename, SortableVector<Human>& humans) {
	ifstream in(filename);
	char str[100];
	if (!in.is_open()) {
		return 0;
	}
	else {
		while (!in.eof()) {
			in.getline(str, 100);
			Human h = Human(str);
			humans.push_back(h);
		}
		return 1;
	}
}

ostream& operator<<(ostream& out, Human& hum)
{
	out << hum.get();
	return out;
}

void write_hum(const char* filename, SortableVector<Human>& humans) {
	ofstream out(filename);
	char strik[100];
	while (1) {
		cin.getline(strik, 100);
		if (*strik == 0) {
			break;
		}
		Human h = Human(strik);
		humans.push_back(h);
	}
	humans.sort();
	for (int i = 0; i < humans.size(); i++) {
		out << humans[i]<<endl;
	}
}
