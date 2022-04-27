#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;

struct schedule {
    int s_date;
    float s_begin_time;
    float s_end_time;
    char s_called_subject[50];
    char s_type_of_occupation[50];
    int s_auditorium;
    char s_familiya[50];
    char s_imya[50];
    char s_otchestvo[50];
};

void print(schedule* f, int count);
void print_menu();
int load(const char* file, schedule* a);
void setData(const char* fileName, int size);
void get_all_lessons(schedule* f, int date, int count);
int get_all_hours(schedule* f, char* prepod, int count);
int get_all_lections(schedule* f, int count);


int main()
{
    setlocale(LC_ALL, "RUS");

    schedule f[15];
    int count = 0;
    int c = 0;
    char flower[50] = {};
    int day;
    int month;
    while (true)
    {
        print_menu();
        char ch = _getch();
        switch (ch)
        {
        case '1':
            count = load("TXT.txt", f);
            if (count < 0)
            {
                return 0;
            }
            break;
        case '2':
            print(f, count);
            break;
        case '3':
            cout << "Enter num: ";
            cin >> c;
            setData("TXT.txt", c);
            break;
        case '4':
            cout << "Enter date: ";
            cin >> day;
            for (; day > 30;) {
                cin >> day;
            }
            cin >> month;
            for (; month > 12;) {
                cin >> month;
            }
            cout << find_normal_ingredient(f, day, month, count, 1);
            break;
        case '5':
            cout << "Enter date: ";
            cin >> day;
            for (; day > 30;) {
                cin >> day;
            }
            cin >> month;
            for (; month > 12;) {
                cin >> month;
            }
            cout << find_normal_ingredient(f, day, month, count, 0);
            break;
        case '6':
            enough(f, count);
            break;
        case '0':
            return 0;
            break;
        default:
            cout << "Noname command!!!" << endl;
        }
        cout << "..." << endl;
        _getch();
    }

}
void print(schedule* f, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Date " << f[i].s_date << endl;
        cout << "Begin " << f[i].s_begin_time << endl;
        cout << "End " << f[i].s_end_time << endl;
        cout << "Subject " << f[i].s_called_subject << endl;
        cout << "Type of occupation " << f[i].s_type_of_occupation << endl;
        cout << "Auditorium " << f[i].s_auditorium << endl;
        cout << "Familiya " << f[i].s_familiya << endl;
        cout << "Imya " << f[i].s_imya << endl;
        cout << "Othestvo " << f[i].s_otchestvo << endl;
        cout << endl;
    }
}
void print_menu()
{
    cout << endl;
    cout << "1 - Downloading data" << endl;
    cout << "2 - Output data" << endl;
    cout << "3 - Input new data" << endl;
    cout << "4 - Output all lessons on this date" << endl;
    cout << "5 - All hours teacher" << endl;
    cout << "6 - All lections " << endl;
    cout << "0 - Exit" << endl;
    cout << "Enter your answer: ";
}
int load(const char* file, schedule* a)
{
    ifstream f;
    f.open(file);
    if (!f.is_open())
    {
        cout << "File is not open: " << file << endl;
        return -1;
    }

    char buff[100];
    f.getline(buff, 99);
    int count = atoi(buff);

    for (int i = 0; i < count; i++)
    {
        if (f.eof())
        {
            f.close();
            return -1;
        }
        char date[49] = {};
        f.getline(date, 49);
        a[i].s_date = atoi(date);

        char begin_time[49] = {};
        f.getline(begin_time, 49);
        a[i].s_begin_time = atof(begin_time);

        char end_time[49] = {};
        f.getline(end_time, 49);
        a[i].s_end_time = atof(end_time);

        f.getline(a[i].s_called_subject, 49);

        f.getline(a[i].s_type_of_occupation, 49);

        char auditorium[49] = {};
        f.getline(auditorium, 49);
        a[i].s_auditorium = atoi(auditorium);

        f.getline(a[i].s_familiya, 49);

        f.getline(a[i].s_imya, 49);

        f.getline(a[i].s_otchestvo, 49);
    }
    f.close();
    return count;
}
void setData(const char* fileName, int size) {
    schedule* dataBase = new schedule[size];
    std::ofstream file;
    file.open(fileName, ios::app);
    if (file.is_open()) {
        cout << "Enter details: " << std::endl;
        for (int i = 0; i < size; i++) {
            float d, s;

            cout << "Enter date: " << std::endl;
            std::cin >> dataBase[i].s_date;
            for (; dataBase[i].s_date < 0 || dataBase[i].s_date> 31;) {
                cout << "Enter date: " << std::endl;
                std::cin >> dataBase[i].s_date;
            }

            cout << "Enter begin: " << std::endl;
            std::cin >> dataBase[i].s_begin_time;
            for (; int(dataBase[i].s_begin_time) < 1 || int(dataBase[i].s_begin_time) > 12 && (dataBase[i].s_begin_time - int(dataBase[i].s_begin_time)) * 100 < 1 || (dataBase[i].s_begin_time - int(dataBase[i].s_begin_time)) * 100 > 31;) {
                cout << "Enter begin: " << std::endl;
                std::cin >> dataBase[i].s_begin_time;
            }

            cout << "Enter end: " << std::endl;
            std::cin >> dataBase[i].s_end_time;
            for (; int(dataBase[i].s_end_time) < 1 || int(dataBase[i].s_end_time) > 12 && (dataBase[i].s_end_time - int(dataBase[i].s_end_time)) * 100 < 1 || (dataBase[i].s_end_time - int(dataBase[i].s_end_time)) * 100 > 31;) {
                cout << "Enter end: " << std::endl;
                std::cin >> dataBase[i].s_end_time;
            }

            cout << "Enter subject: " << std::endl;
            std::cin >> dataBase[i].s_called_subject;

            cout << "Enter type of occupation: " << std::endl;
            std::cin >> dataBase[i].s_type_of_occupation;

            cout << "Enter auditorium: " << std::endl;
            std::cin >> dataBase[i].s_auditorium;
            for (; dataBase[i].s_auditorium < 1 || dataBase[i].s_auditorium > 600;) {
                cout << "Enter auditorium: " << std::endl;
                std::cin >> dataBase[i].s_auditorium;
            }

            cout << "Enter familiya: " << std::endl;
            std::cin >> dataBase[i].s_familiya;


            cout << "Enter imya: " << std::endl;
            std::cin >> dataBase[i].s_imya;

            cout << "Enter otchestvo: " << std::endl;
            std::cin >> dataBase[i].s_otchestvo;


            file << dataBase[i].s_date << std::endl
                << dataBase[i].s_begin_time << std::endl
                << dataBase[i].s_end_time << std::endl
                << dataBase[i].s_called_subject << std::endl
                << dataBase[i].s_type_of_occupation << std::endl
                << dataBase[i].s_auditorium << std::endl
                << dataBase[i].s_familiya << std::endl
                << dataBase[i].s_imya << std::endl
                << dataBase[i].s_otchestvo << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Fatal error! Try again.." << std::endl;
    }
    delete[]dataBase;
}
void get_all_lessons(schedule* f, int date, int count) {
    for (int i = 0; i < count; i++) {
        if (f[i].s_date == date) {
            cout << f[i].s_date << endl;
            cout << f[i].s_called_subject << endl;
        }
    }
}

int get_all_lections(schedule* f, int count) {
    int c = 0;
    for (int i = 0; i < count; i++) {
        if (f[i].s_type_of_occupation == "lection") {
            c++;
        }
    }
    return c;
}
int get_all_hours(schedule* f, char* prepod, int count) {
    int h = 0;
    bool j = true;
    int week;
    for (int i = 0; i < count; i++) {
        if (f[i].s_familiya == prepod) {
            if (abs(week - f[i].s_date) > 7) break;
            h += 1;
            if (j == true) {
                week = f[i].s_date;
                j = false;
            }
        }
    }
    return h;
}