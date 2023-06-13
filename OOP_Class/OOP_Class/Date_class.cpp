#include <iostream>
#include <string>
#include "Date.h"
#include <cmath>
#include <fstream>

using namespace std;


Date::Date() {}     //Конструктор по умолчанию

//Конструктор с параметрами
Date::Date(int day1, int month1, int year1) {
    setDay(day1);
    setMonth(month1);
    setYear(year1);
}
//Cеттер для дня
void Date::setDay(int d) {
    if ((d > 0) && (d < 32)) {
        day = d;
    }
}
//Cеттер для месяца
void Date::setMonth(int m) {
    if ((m > 0) && (m < 13)) {
        month = m;
    }
}
//Cеттер для года
void Date::setYear(int y) {
    if (y > 0) { 
        year = y; 
    }
}
//Геттер для дня
int Date::getDay() const {
    return day; 
}
//Геттер для месяца
int Date::getMonth() const {
    return month;
}
//Геттер для года
int Date::getYear() const {
    return year; 
}
//Метод перевода даты в строку
string Date::srting_date() const {
    return to_string(this->day) + '.' + to_string(this->month) + '.' + to_string(this->year);
}
//Метод прибавления дня
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
//Метод прибавления меясца
void Date::addMonth(int m) {
    this->month += m;
    while (this->month > 12) {
        this->month -= 12;
        this->year;
    }
}
//Метод прибавления года
void Date::addYear(int y) {
    this->year += y;
}
//Метод для прибавления дней, месяцев, лет к дате
void Date::addDate(int d, int m, int y) {
    addDay(d);
    addMonth(m);
    addYear(y);
}
//Метод для вывода даты
void Date::Print() const {
    cout << this->day << "." << this->month << "." << this->year << endl;
}
//Метод для записи в файл заданную дату
void Date::WriteFile(const string& filename) const {
    fstream fs;                                                                 // Объект класса fstream для работы с файлами
    try {
        fs.open(filename, fstream::out | fstream::in | fstream::app);           // Открывает файл по пути filename в режиме записи (out), чтения (in) и добавления (app)
        fs << this->day << "." << this->month << "." << this->year << endl;     // Записывает день, месяц и год объекта типа Date в файл
    }
    catch (const fstream::failure& e) {
        cout << "Ошибка при открытии файла!";
    }
    fs.close();                                                                 // Закрывает файл
}
//Метод, генерирующий массив обьктов класса
void Date::GenDate(Date* obj, unsigned int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        obj[i] = Date(rand() % 32, rand() % 13, rand() % 9999);
    }
}
//Метод переопределяющий оператор, для возможности вывода в консоль
ostream& operator<<(ostream& os, const Date& date) {
    os << date.day << '.' << date.month << '.' << date.year;
    return os;
}
//Данный метод вернёт кол - во дней в данном месяце
int Date::DaysInMonth() const {
    switch (this->month) {          // Оператор switch проверяет значение переменной month
    case 2:                         // Если месяц - февраль (2), проверяем, является ли год високосным с помощью функции IsLeapYear()
        if (IsLeapYear()) {         // Если год високосный, возвращаем 29
            return 29; 
        }
        else {                      // В противном случае возвращаем 28
            return 28; 
        }
    case 4:                         // Если месяц - апрель (4), возвращаем 30
    case 6:                         // Если месяц - июнь (6), возвращаем 30
    case 9:                         // Если месяц - сентябрь (9), возвращаем 30
    case 11:
        return 30;                  // Если месяц - ноябрь (11), возвращаем 30
    default:                        // Для всех остальных месяцев возвращаем 31
        return 31;
    }
}
//Метод для определения года, вернёт true - високосный, false - невисокосный
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