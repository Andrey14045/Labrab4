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
	cout << "Введите максимальную степень монома" << endl;
	cin >> power;
	cout << "Введите начальный полином" << endl;
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
		cout << "1. Показать все полиномы" << endl;
		cout << "2. Показать выбранный полином" << endl;
		cout << "3. Ввести новый полином" << endl;
		cout << "4. Сложить полиномы" << endl;
		cout << "5. Вычесть полиномы" << endl;
		cout << "6. Умножить полином на полином" << endl;
		cout << "7. Ввести коэффициент x и вычислить полином" << endl;
		cout << "0. Выйти из программы" << endl;
		cin >> check1;
		system("cls");
		switch (check1)
		{
		case 1:
			cout << "Полиномы:" << endl;
			for (int i = 0; i < actual_AmountOfPolynoms; i++)
			{
				cout << "Index["<<i<<"]   ";
				PolArray[i].PrintPolynom();
			}
			break;
		case 2:
			cout << "Введите индекс выводимого полинома" << endl;
			cin >> check2;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			cout << "Полином: ";
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
			cout << "Введите индекс 1 складываемого полинома" << endl;
			cin >> check2;
			cout << "Введите индекс 2 складываемого полинома" << endl;
			cin >> check3;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			if ((check3 < 0) || (check3 >= actual_AmountOfPolynoms))
				break;
			result = PolArray[check2] + PolArray[check3];
			cout << "Получившийся полином: ";
			result.PrintPolynom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
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
			cout << "Введите индекс 1 вычитаемого полинома" << endl;
			cin >> check2;
			cout << "Введите индекс 2 вычитаемого полинома" << endl;
			cin >> check3;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			if ((check3 < 0) || (check3 >= actual_AmountOfPolynoms))
				break;
			result = PolArray[check2] - PolArray[check3];
			cout << "Получившийся полином: ";
			result.PrintPolynom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
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
			cout << "Введите индекс умножаемого полинома:" << endl;
			cin >> check2;
			cout << "Введите индекс умножаемого полинома:" << endl;
			cin >> check3;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			if ((check3 < 0) || (check3 >= actual_AmountOfPolynoms))
				break;
			result = PolArray[check2] * PolArray[check3];
			cout << "Получившийся полином: ";
			result.PrintPolynom();
			cout << "Сохранить получившийся полином? 1 да ,0 нет" << endl;
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
			cout << "Введите индекс полинома для вычисления:" << endl;
			cin >> check2;
			if ((check2 < 0) || (check2 >= actual_AmountOfPolynoms))
				break;
			PolArray[check2].PrintPolynom();
			cout << "Введите х:" << endl;
			cin >> x;
			result_Calculate = PolArray[check2].Calculate(x);
			cout << "Получившийся результат: " << result_Calculate << endl;
			break;
		case 0:
			return 0;
		}
	}
}