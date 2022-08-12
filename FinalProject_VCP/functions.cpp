#include "function.h"
void add_new_list(Student**  (&_mas), int& n) {
	cout << "Enter size of list: ";
	cin >> n;
	_mas = new Student*[n];
	name tem;
	marks _m;
	int id, _n;
	for (int i = 0; i < n; i++) {
		system("cls");
		cout << "Enter name of student: ";
		cin >> tem._name;
		system("cls");
		cout << "Enter surname of student: ";
		cin >> tem._surname;
		system("cls");
		cout << "Enter ID of student: ";
		cin >> id;
		system("cls");
		cout << "Enter index number of student: ";
		cin >> _n;
		system("cls");
		cout << "Enter points for math: "; 
		cin >> _m.math_mark;
		system("cls");
		cout << "Enter points for english: ";
		cin >>_m.eng_mark;
		system("cls");
		cout << "Enter points for biology: ";
		cin >> _m.bio_mark;
		system("cls");
		cout << "Enter points for sport: ";
		cin >> _m.sport_mark;
		system("cls");
		_mas[i] = new Student(tem, _m, id, _n);
	}
}

void print_list(Student** _mas, int &n) {
	for (int i = 0; i < n; i++) { 
		_mas[i]->print();
		cout << '\n';
	}
}

void Show_grades(Student** _mas, int n) {
	for (int i = 0; i < n; ++i) {
		cout << _mas[i]->get_Initials()._name<< " " << _mas[i]->get_Initials()._surname<< " has grade " << _mas[i]->get_marks().grade;
		cout << endl;
	}
}

void del_st(Student** (&_mas), int& n) {
	int t;
	Student** buf = new Student*[n];
	cout << "Enter index number of student, which will be deleted (from 1 to "<<n<<"): ";
	cin >> t;
	--t;
	if (t >= 0 && t < n) {
		copy(buf, _mas, n);
		int q = 0;
		--n;
		delete[] _mas;
		_mas = new Student*[n];
		for (int i = 0; i <= n; ++i) {
			if (i != t) {
				_mas[q] = buf[i];
				q++;
			}

		}
	}
	else
		cout << "Wrong input :(" << endl;
	delete[] buf;
}

void copy(Student** a, Student** b, int n) {
	for (int i = 0; i < n; ++i)
		a[i] = b[i];
}

void Data_reading(Student** (&_mas), int& n, string file_name) {
	ifstream reading(file_name);
	if (reading) {
		name tem;
		marks _m;
		int id, nu;
		reading >> n;
		_mas = new Student * [n];
		for (int i = 0; i < n; ++i) {
			reading >> tem._name >> tem._surname;
			reading >> id;
			reading >> nu;
			reading >> _m.math_mark >> _m.eng_mark >> _m.bio_mark >> _m.sport_mark;
			_mas[i] = new Student(tem, _m, id, nu);
		}
	}
	else
		cout << "Error opening file";
	reading.close();
}

void change_list(Student** _mas, int n) {
	int t;
	cout << "Enter number of studnet whith data will be changed: ";
	cin >> t;
	t--;
	name tem;
	marks _m;
	int id, _n;
	if (t >= 0 && t < n) {
		cout << "Enter new name: ";
		cin >> tem._name;
		cout << "Enter new surname: ";
		cin >> tem._surname;
		cout << "Enter new ID of student: ";
		cin >> id;
		cout << "Enter new index number of student: ";
		cin >> _n;
		cout << "Enter new points for math: ";
		cin >> _m.math_mark;
		cout << "Enter new points for english: ";
		cin >> _m.eng_mark;
		cout << "Enter new points for biology: ";
		cin >> _m.bio_mark;
		cout << "Enter new points for sport: ";
		cin >> _m.sport_mark;
		_mas[t] = new Student(tem, _m, id, _n);
	}
	else
		cout << "Wrong input :(" << endl;
}

void del_list(Student** (&_mas), int& n) {
	delete[]_mas;//delete all list with structures?
	_mas = NULL;
	n = 0;
}

void sort_list(Student** _mas, int n) {
	Student *S;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (_mas[i]->get_Initials()._surname > _mas[j]->get_Initials()._surname)
			{
				S = _mas[i];
				_mas[i] = _mas[j];
				_mas[j] = S;
			}
		}
	}

}

void add_st(Student** (&_mas), int& n) {
	name tem;
	marks _m;
	int id, _n;
	int size = n;
	++n;
	Student** buf = new Student*[size];
	copy(buf, _mas, size);
	delete[]_mas;
	_mas = new Student*[n];
	copy(_mas, buf, size);
	cout << "Enter new name: ";
	cin >> tem._name;
	cout << "Enter new surname: ";
	cin >> tem._surname;
	cout << "Enter ID of student: ";
	cin >> id;
	cout << "Enter index number of student: ";
	cin >> _n;
	cout << "Enter points for math: ";
	cin >> _m.math_mark;
	cout << "Enter points for english: ";
	cin >> _m.eng_mark;
	cout << "Enter points for biology: ";
	cin >> _m.bio_mark;
	cout << "Enter points for sport: ";
	cin >> _m.sport_mark;
	_mas[n-1] = new Student(tem, _m, id, _n);
	delete[]buf;
}

void Save_data(Student** _mas, int n, string str) {
	ofstream myfile(str);
	if (myfile) {
		myfile << n << endl;
		for (int i = 0; i < n; ++i) {
			myfile << _mas[i]->get_Initials()._name << '\n' << _mas[i]->get_Initials()._surname << endl;
			myfile << _mas[i]->get_St_id() << endl;
			myfile << _mas[i]->get_numm() << endl;
			myfile << _mas[i]->get_marks().math_mark << '\n' << _mas[i]->get_marks().eng_mark << '\n' << _mas[i]->get_marks().bio_mark << '\n' << _mas[i]->get_marks().sport_mark;
		}
	}
	else
		cout << "Error opening file";
	myfile.close();
}
