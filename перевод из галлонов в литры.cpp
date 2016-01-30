// перевод из галлонов в литры.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h";
#include <iostream>;
using namespace std;
#include <clocale>;


;int main()
{
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
	double gallons, liters;
	cout << "Введите количество галлонов:  ";
	cin >> gallons; // ввод кол-ва галлонов пользователем
	liters = gallons * 3.7854; // Преобразование в литры
	cout << "Литров:     " << liters << '\n';
	system("pause");

    return 0;
}