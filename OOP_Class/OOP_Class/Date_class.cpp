#include <iostream>
#include <string>
#include "Date.h"
#include <cmath>
#include <fstream>

using namespace std;


Date::Date() {}     //����������� �� ���������

//����������� � �����������
Date::Date(int day1, int month1, int year1) {
    setDay(day1);
    setMonth(month1);
    setYear(year1);
}
//C����� ��� ���
void Date::setDay(int d) {
    if ((d > 0) && (d < 32)) {
        day = d;
    }
}
//C����� ��� ������
void Date::setMonth(int m) {
    if ((m > 0) && (m < 13)) {
        month = m;
    }
}
//C����� ��� ����
void Date::setYear(int y) {
    if (y > 0) { 
        year = y; 
    }
}
//������ ��� ���
int Date::getDay() const {
    return day; 
}
//������ ��� ������
int Date::getMonth() const {
    return month;
}
//������ ��� ����
int Date::getYear() const {
    return year; 
}
//����� �������� ���� � ������
string Date::srting_date() const {
    return to_string(this->day) + '.' + to_string(this->month) + '.' + to_string(this->year);
}
//����� ����������� ���
void Date::addDay(int d) {
    this->day += d;
    while (this->day > DaysInMonth()) {
        this->day -= DaysInMonth();
        this->month++;
        if (this->month > 12) {
            this->month = 1;
            this->year++;
        }
    }
}
//����� ����������� ������
void Date::addMonth(int m) {
    this->month += m;
    while (this->month > 12) {
        this->month -= 12;
        this->year;
    }
}
//����� ����������� ����
void Date::addYear(int y) {
    this->year += y;
}
//����� ��� ����������� ����, �������, ��� � ����
void Date::addDate(int d, int m, int y) {
    addDay(d);
    addMonth(m);
    addYear(y);
}
//����� ��� ������ ����
void Date::Print() const {
    cout << this->day << "." << this->month << "." << this->year << endl;
}
//����� ��� ������ � ���� �������� ����
void Date::WriteFile(const string& filename) const {
    fstream fs;                                                                 // ������ ������ fstream ��� ������ � �������
    try {
        fs.open(filename, fstream::out | fstream::in | fstream::app);           // ��������� ���� �� ���� filename � ������ ������ (out), ������ (in) � ���������� (app)
        fs << this->day << "." << this->month << "." << this->year << endl;     // ���������� ����, ����� � ��� ������� ���� Date � ����
    }
    catch (const fstream::failure& e) {
        cout << "������ ��� �������� �����!";
    }
    fs.close();                                                                 // ��������� ����
}
//�����, ������������ ������ ������� ������
void Date::GenDate(Date* obj, unsigned int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        obj[i] = Date(rand() % 32, rand() % 13, rand() % 9999);
    }
}
//����� ���������������� ��������, ��� ����������� ������ � �������
ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << '.' << date.month << '.' << date.year;
    return os;
}
//������ ����� ����� ��� - �� ���� � ������ ������
int Date::DaysInMonth() const {
    switch (this->month) {          // �������� switch ��������� �������� ���������� month
    case 2:                         // ���� ����� - ������� (2), ���������, �������� �� ��� ���������� � ������� ������� IsLeapYear()
        if (IsLeapYear()) {         // ���� ��� ����������, ���������� 29
            return 29; 
        }
        else {                      // � ��������� ������ ���������� 28
            return 28; 
        }
    case 4:                         // ���� ����� - ������ (4), ���������� 30
    case 6:                         // ���� ����� - ���� (6), ���������� 30
    case 9:                         // ���� ����� - �������� (9), ���������� 30
    case 11:
        return 30;                  // ���� ����� - ������ (11), ���������� 30
    default:                        // ��� ���� ��������� ������� ���������� 31
        return 31;
    }
}
//����� ��� ����������� ����, ����� true - ����������, false - ������������
bool Date::IsLeapYear() const {
    if (this->year % 4 != 0) {
        return false;
    }
    else if (this->year % 100 != 0) {
        return true;
    }
    else if (this->year % 400 != 0) {
        return false;
    }
    else {
        return true;
    }
}