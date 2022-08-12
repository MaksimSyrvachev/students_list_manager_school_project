#pragma once
#include "Class_Student.h"
void add_new_list(Student** (&), int&);
void print_list(Student**, int &);
void Show_grades(Student**, int);
void del_st(Student**(&), int&);
void copy(Student**, Student**, int);
void Data_reading(Student** (&), int&, string);
void change_list(Student**, int);
void del_list(Student** (&), int&);
void sort_list(Student**, int);
void add_st(Student** (&), int&);
void Save_data(Student**, int, string);
