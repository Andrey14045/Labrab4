#include "Polynom.h"
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string in;
	unsigned int power;
	int x;
	Polynom PolArray[50];
	int check1;
	int check2;
	int check3;
	int result_Calculate;
	int actual_AmountOfPolynoms = 1;
	cout << "������� ������������ ������� ������" << endl;
	cin >> power;
	cout << "������� ��������� �������" << endl;
	cin >> in;
	Polynom result;
	try
	{
		Polynom::SetMaxPower(power);
		Polynom Polinom(in);
		PolArray[0] = Polinom;
	}
	catch (char* ch)
	{
		cout << ch << endl;
		return 1;
	}
	while (true)
	{
		cout << endl;
		cout << "          Short List " << endl;
		cout << "1. �������� ��� ��������" << endl;
		cout << "2. �������� ��������� �������" << endl;
		cout << "3. ������ ����� �������" << endl;
		cout << "4. ������� ��������" << endl;
		cout << "5. ������� ��������" << endl;
		cout << "6. �������� ������� �� �������" << endl;
		cout << "7. ������ ����������� x � ��������� �������" << endl;
		cout << "0. ����� �� ���������" << endl;
		cin >> check1;
		system("cls");
		switch (check1)
		{
		case 1:
			cout << "��������:" << endl;
			for (int i = 0; i < actual_AmountOfPolynoms; i++)
			{
				cout << "Index["<<i<<"]   ";
				PolArray[i].PrintPolynom();
			}
			break;
		case 2:
			cout << "������� ������ ���������� ��������" << endl;
			cin >> check2;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			cout << "�������: ";
			PolArray[check2].PrintPolynom();
			break;
		case 3:
			cin >> in;
			try
			{
				Polynom Polinom(in);
				PolArray[actual_AmountOfPolynoms] = Polinom;
				actual_AmountOfPolynoms++;
			}
			catch (char* ch)
			{
				cout << ch << endl;
			}
			break;
		case 4:
			cout << "������� ������ 1 ������������� ��������" << endl;
			cin >> check2;
			cout << "������� ������ 2 ������������� ��������" << endl;
			cin >> check3;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			if ((check3 < 0) || (check3 >= actual_AmountOfPolynoms))
				break;
			result = PolArray[check2] + PolArray[check3];
			cout << "������������ �������: ";
			result.PrintPolynom();
			cout << "��������� ������������ �������? 1 �� ,0 ���" << endl;
			cin >> check3;
			if (check3 == 0)
				break;
			if (check3 == 1)
			{
				PolArray[actual_AmountOfPolynoms] = result;
				actual_AmountOfPolynoms++;
			}
			break;
		case 5:
			cout << "������� ������ 1 ����������� ��������" << endl;
			cin >> check2;
			cout << "������� ������ 2 ����������� ��������" << endl;
			cin >> check3;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			if ((check3 < 0) || (check3 >= actual_AmountOfPolynoms))
				break;
			result = PolArray[check2] - PolArray[check3];
			cout << "������������ �������: ";
			result.PrintPolynom();
			cout << "��������� ������������ �������? 1 �� ,0 ���" << endl;
			cin >> check3;
			if (check3 == 0)
				break;
			if (check3 == 1)
			{
				PolArray[actual_AmountOfPolynoms] = result;
				actual_AmountOfPolynoms++;
			}
			break;
		case 6:
			cout << "������� ������ ����������� ��������:" << endl;
			cin >> check2;
			cout << "������� ������ ����������� ��������:" << endl;
			cin >> check3;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			if ((check3 < 0) || (check3 >= actual_AmountOfPolynoms))
				break;
			result = PolArray[check2] * PolArray[check3];
			cout << "������������ �������: ";
			result.PrintPolynom();
			cout << "��������� ������������ �������? 1 �� ,0 ���" << endl;
			cin >> check3;
			if (check3 == 0)
				break;
			if (check3 == 1)
			{
				PolArray[actual_AmountOfPolynoms] = result;
				actual_AmountOfPolynoms++;
			}
			break;
		case 7:
			cout << "������� ������ �������� ��� ����������:" << endl;
			cin >> check2;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			PolArray[check2].PrintPolynom();
			cout << "������� �:" << endl;
			cin >> x;
			result_Calculate = PolArray[check2].Calculate(x);
			cout << "������������ ���������: " << result_Calculate << endl;
			break;
		case 0:
			return 0;
		}
	}
}