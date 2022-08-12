#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct name {
	string _name;
	string _surname;
};

struct marks {
	int math_mark, eng_mark, bio_mark, sport_mark;
	double average;
	char grade;
};

class Student {
	name nom;
	int St_id;
	int numm;
	marks m;
	int *mas;
public:
	Student(name, marks, int, int);
	Student();
	~Student();
	Student(Student const&);
	void print() const;
	name get_Initials() { return nom; };
	marks get_marks() { return m; };
	int get_St_id() { return St_id; };
	int get_numm() { return numm; };
};

