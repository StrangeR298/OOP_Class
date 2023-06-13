#include <iostream>
#include <string>


using namespace std;


/// ����� ��� ������ � �����
class Date {
  
public:

    // ����������� �� ���������
    Date();

    // ����������� � �����������
    Date(int day1, int month1, int year1);

    //�������
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    //�������
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    //�������� � ������
    string srting_date() const;

    //���������� � ������� ����
    //�����  ���������� ����,
    void addDay(int d);
    //�����  ���������� �������
    void addMonth(int m);
    //�����  ���������� ����(���)
    void addYear(int y);
    //����� ��� ���������� d(����), m(�������), y(���) � ����
    void addDate(int d, int m, int y);

    //����� ��� ������ ����
    void Print() const;

    //����� ��� ������ � ���� �������� ����
    void WriteFile(const string& filename) const;

    //�����, ������������ ������ ������� ������
    static void GenDate(Date* obj, unsigned int size);

    //����� ���������������� ��������, ��� ����������� ������ � �������, friend - ������������� �������,
    friend ostream& operator<<(ostream& os, const Date& date);

    //����� ��� ����������� ���-�� ���� � �������� ������
    int DaysInMonth() const;

    //����� ��� ����������� ������������ ����
    bool IsLeapYear() const;

private:
    // ���� ������: day - �����, month - ����� ������, year - ���
    int day;
    int month;
    int year;

};