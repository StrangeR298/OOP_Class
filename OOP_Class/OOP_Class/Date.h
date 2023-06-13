#include <iostream>
#include <string>


using namespace std;


/// Класс для работы с датой
class Date {
  
public:

    // Конструктор по умолчанию
    Date();

    // Конструктор с параметрами
    Date(int day1, int month1, int year1);

    //Сеттеры
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    //Геттеры
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    //Перевода с строку
    string srting_date() const;

    //Добавление к текущей дате
    //Метод  добавление дней,
    void addDay(int d);
    //Метод  добавление меясцев
    void addMonth(int m);
    //Метод  добавление года(лет)
    void addYear(int y);
    //Метод для добавления d(дней), m(месяцев), y(лет) к дате
    void addDate(int d, int m, int y);

    //Метод для вывода даты
    void Print() const;

    //Метод для записи в файл заданную дату
    void WriteFile(const string& filename) const;

    //Метод, генерирующий массив обьктов класса
    static void GenDate(Date* obj, unsigned int size);

    //Метод переопределяющий оператор, для возможности вывода в консоль, friend - дружественная функция,
    friend ostream& operator<<(ostream& os, const Date& date);

    //Метод для определения кол-во дней в заданном месяце
    int DaysInMonth() const;

    //Метод для определения високосности года
    bool IsLeapYear() const;

private:
    // поля класса: day - число, month - номер месяца, year - год
    int day;
    int month;
    int year;

};