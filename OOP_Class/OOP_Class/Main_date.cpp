#include <iostream>
#include "Date.h"
#include <fstream>
#include <cassert>

using namespace std;

//������� ��� ������ �� ����� ����
void ReadFile(const string& filename, Date& obj) {
	cout << "\nReadData";
	fstream fs;													// ������ ������ fstream ��� ������ � �������
	string path = filename;										// ���� � �����
	cout << endl;
	fs.open(path);												// ��������� ���� �� ���� path
	try {
		string str = "";										// ���������� ��� �������� ������ �� �����.
		getline(fs, str);										// ��������� ������ ������ �� ����� � ���������� �� � ���������� str.

		// ���� ������ �� ������, �� ��������� �� � ���������� ����, ����� � ��� � ������ ���� Date.
		if (str != "") {
			int temp2 = str.find(".");
			int temp3 = str.find(".", temp2 + 1);
			obj.setDay(stoi(str.substr(0, temp2)));
			obj.setMonth(stoi(str.substr( temp2 + 1, temp3)));
			obj.setYear(stoi(str.substr(temp3 + 1, '\n')));
		}
		fs.close();
	}
	catch (const fstream::failure& e) {
		cout << "������ ��� ������ �� �����!";
	}
}

int main() {
	
	Date date(12, 2, 2022);		//�������� ���������� ������ date
	date.Print();				//����� ������ ��� ������ � ������� �������� ����
	
	date.addDay(15);			//����� ������ ����������� ���� � �������� ����
	date.addMonth(2);			//����� ������ ����������� ������� � �������� ����
	date.addYear(1);			//����� ������ ����������� ���� � �������� ����
	date.Print();				//����� ������ ��� ������ � ������� ���������� ���� ����
	
	date.addDate(12, 2, 12);	//����� ������ ����������� � �������� ���� 12.2.12
	date.Print();


	Date* myDate = new Date();		//������������ �������� ������
	
	Date* arr = new Date[5];		//������������ ������ arr ������ 5
	Date::GenDate(arr, 5);			//����� ������ ��� ���������� ������������� ������� ���������� ������
	arr[2].Print();					//����� ������ �������� �������
	delete[] arr;


	//�������� ������������ ������� arr1 � ������ N
	int const N = 7;
	Date arr1[N];
	Date::GenDate(arr1, N);
	arr1[1].Print();

	//��������  ������� �� ���������� �� ������
	int const Size = 3;
	//arr2 ������ ������ �������
	Date* arr2[N];
	arr2[0] = new Date();
	arr2[0]->setDay(12);



	//date.WriteFile("data.txt");	//����� ��� ������ � ���� �������� ����
	ReadFile("data.txt", date);		//����� ��� ������ �� ����� ����
	date.Print();


	//����� ������� 

	Date dateTest(12, 12, 2011);

	assert(dateTest.getDay() - 2 == 10);	
	
	dateTest.addYear(13);
	assert(dateTest.IsLeapYear());

	assert(dateTest.getMonth() - 2 == 10);

	
	assert(dateTest.getDay() == 12);
	assert(dateTest.getMonth() == 12);
	assert(dateTest.getYear() == 2024);
}