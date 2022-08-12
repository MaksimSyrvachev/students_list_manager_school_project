#include "function.h"


using namespace std;

int _state_Menu;

void Menu() {
    cout << "\n\tMenu"
        << "\n(1).Adding new list"
        << "\n(2).Show data"
        << "\n(3).Show grades of student"
        << "\n(4).Delete student"
        << "\n(5).Delete list of students"
        << "\n(6).Modify student's data"
        << "\n(7).Sort list of students"
        << "\n(8).Add student"
        << "\n(9).Safe data"
        << "\n(10).Exit"
        << "\n\nYour choice: ";
    cin >> _state_Menu;
}

int main()
{
    int size_of_d = 0;
    Student** d = NULL;
    int actions;
    cout << setprecision(2)<<fixed;
    Menu();
    while (_state_Menu != 10)
    {
        switch (_state_Menu)
        {
        case 1:
            system("cls");
            cout << "Enter data from keyboard or read from file?(1/2)";
            cin >> actions;
            if (actions == 1) {
                if (!size_of_d)
                    add_new_list(d, size_of_d);
                else
                    cout << "Last list was not deleted.";
            }
            else
            {
                Data_reading(d, size_of_d, "Out.txt");
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 2:
            system("cls");
            if (size_of_d)
                print_list(d, size_of_d); 
            else
                cout << "Empty list :(\n";
            system("pause");
            system("cls");
            Menu();
            break;
            
        case 3:
            system("cls");
            if (size_of_d)
                Show_grades(d, size_of_d);
            else
                cout << "Empty list :(\n";
            system("pause");
            system("cls");
            Menu();
            break;
        
        case 4:
            system("cls");
            if (size_of_d)
                del_st(d, size_of_d);
            else
                cout << "Empty list :(\n";
            system("pause");
            system("cls");
            Menu();
            break;
        
        case 5:
            system("cls");
            if (size_of_d)
                del_list(d, size_of_d);
            else
                cout << "Empty list :(\n";
            system("pause");
            system("cls");
            Menu();
            break;
        case 6:
            system("cls");
            if (size_of_d)
                change_list(d, size_of_d);
            else
                cout << "Empty list :(\n";
            system("pause");
            system("cls");
            Menu();
            break;
        case 7:
            system("cls");
            if (size_of_d)
                sort_list(d, size_of_d);
            else
                cout << "Empty list :(\n";
            system("pause");
            system("cls");
            Menu();
            break;
        case 8:
            system("cls");
            if (size_of_d)
                add_st(d, size_of_d);
            else
                cout << "Empty list :(\n";
            system("pause");
            system("cls");
            Menu();
            break;
        case 9:
            system("cls");
            if (size_of_d)
                Save_data(d, size_of_d, "Out.txt");
            else
                cout << "Empty list :(\n";
            system("pause");
            system("cls");
            Menu();
            break;
        default:
            cout << "Wrong input\n";
            system("cls");
            Menu();
            break;
        }
        
    }
}
