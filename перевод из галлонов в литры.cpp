// ������� �� �������� � �����.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h";
#include <iostream>;
using namespace std;
#include <clocale>;


;int main()
{
	setlocale(LC_CTYPE, "rus"); // ����� ������� ��������� ������
	double gallons, liters;
	cout << "������� ���������� ��������:  ";
	cin >> gallons; // ���� ���-�� �������� �������������
	liters = gallons * 3.7854; // �������������� � �����
	cout << "������:     " << liters << '\n';
	system("pause");

    return 0;
}