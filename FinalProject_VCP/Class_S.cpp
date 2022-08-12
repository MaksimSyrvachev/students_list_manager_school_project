#include "Class_Student.h"

Student::Student() {
	nom._name = "";
	nom._surname = "";
	St_id = 0;
	m.math_mark = 0;
	m.eng_mark = 0;
	m.bio_mark = 0;
	m.sport_mark = 0;
	m.average = 0;
	m.grade = ' ';
	numm = 0;
	mas = NULL;
}

Student::Student(name _nom, marks _m, int _id, int n) {
	nom._name = _nom._name;
	nom._surname = _nom._surname;
	St_id = _id;
	m.math_mark = _m.math_mark;
	m.eng_mark = _m.eng_mark;
	m.bio_mark = _m.bio_mark;
	m.sport_mark = _m.sport_mark;
	numm = 0;
	mas = NULL;
	if (n > 0) {
		numm = n;
		mas = new int[numm];
		for (int i = 0; i < numm; ++i)
			mas[i] = numm;
	}
	m.average = (m.math_mark + m.eng_mark + m.bio_mark + m.sport_mark) / 4.0;
	if (m.average >= 95)
		m.grade = 'A';
	else if (m.average >= 85)
		m.grade = 'B';
	else if (m.average >= 75)
		m.grade = 'C';
	else if (m.average >= 65)
		m.grade = 'D';
	else if (m.average >= 50)
		m.grade = 'E';
	else
		m.grade = 'F';
}

Student::~Student() {
	if (mas)
		delete []mas;
}

Student::Student(Student const& a) {
	nom._name = a.nom._name;
	nom._surname = a.nom._surname;
	St_id = a.St_id;
	m.math_mark = a.m.math_mark;
	m.eng_mark = a.m.eng_mark;
	m.bio_mark = a.m.bio_mark;
	m.sport_mark = a.m.sport_mark;

	numm = a.numm;
	mas = NULL;
	if (a.mas) {
		mas = new int[numm];
		for (int i = 0; i < numm; ++i)
			mas[i] = numm;
	}
}

void Student::print() const {
	cout << "\nStudent name: " << nom._name;
	cout << "\nStudent surname: " << nom._surname;
	cout << "\nStudent ID: " << St_id;
	cout << "\nMath mark: " << m.math_mark;
	cout << "\nEnglish mark: " << m.eng_mark;
	cout << "\nBiology mark: " << m.bio_mark;
	cout << "\nSport mark: " << m.sport_mark;
	cout << "\nSome array: ";
	for (int i = 0; i < numm; i++)
		cout<< '\t' << mas[i] << '\t';
}