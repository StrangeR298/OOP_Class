#include <iostream>
#include "Date.h"
#include <fstream>
#include <cassert>

using namespace std;

//Функция для чтения из файла даты
void ReadFile(const string& filename, Date& obj) {
	cout << "\nReadData";
	fstream fs;
	string path = filename;
	cout << endl;
	fs.open(path);
	try {
		string str = "";
		getline(fs, str);
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
		cout << "Ошибка при чтении из файла!";
	}
}

int main() {
	
	Date date(12, 2, 2022);		//Создание экземпляра класса date
	date.Print();				//Вызов метода для вывода в консоль заданной даты
	
	date.addDay(15);			//Вызов метода прибавления дней к заданной дате
	date.addMonth(2);			//Вызов метода прибавления месяцев к заданной дате
	date.addYear(1);			//Вызов метода прибавления года к заданной дате
	date.Print();				//Вызов метода для вывода в консоль посчитаной даты даты
	
	date.addDate(12, 2, 12);	//Вызов метода прибавления к заданной дате 12.2.12
	date.Print();


	Date* myDate = new Date();		//Динамическое создание обькта
	
	Date* arr = new Date[5];		//Динамический массив arr длиной 5
	Date::GenDate(arr, 5);			//Вызов метода для заполнения динамического массива случайными датами
	arr[2].Print();					//Вывод одного элемента массива
	delete[] arr;


	//Создание статического массива arr1 с длиной N
	int const N = 7;
	Date arr1[N];
	Date::GenDate(arr1, N);
	arr1[1].Print();

	//Создание  массива из указателей на обьект
	int const Size = 3;
	//arr2 хранит адреса обьекта
	Date* arr2[N];
	arr2[0] = new Date();
	arr2[0]->setDay(12);



	//date.WriteFile("data.txt");	//Метод для записи в файл заданную дату
	ReadFile("data.txt", date);		//Метод для чтения из файла даты
	date.Print();


	//Тесты методов 

	Date dateTest(12, 12, 2011);

	assert(dateTest.getDay() - 2 == 10);	
	assert(dateTest.getMonth() - 2 == 10);
	dateTest.addYear(14);

	assert(dateTest.getDay() == 12);
	assert(dateTest.getMonth() == 12);
	assert(dateTest.getYear() == 2025);
}