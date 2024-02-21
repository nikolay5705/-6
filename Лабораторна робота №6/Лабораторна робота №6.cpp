#include <math.h>
#include <Windows.h>
#include <iostream>
#include <iomanip>
using namespace std;

double Function(double x) {
	double Sqrt_Sin, Sqrt_of_Exp, Drib;
	Sqrt_Sin = sqrt(pow(sin(x / 2), 3));
	Sqrt_of_Exp = pow(exp(1.3 * x) + exp(-1.3 * x), 1.0 / 3);
	Drib = 1.0 / abs(x + 5.0 / 2);
	return (Sqrt_Sin + Sqrt_of_Exp) * Drib;

}

void first_task(double x_start, double x_end, double x_shag) {
	double x, y;
	cout << "|-----------|---------------------|" << endl;
	cout << "|     x     |         y           |" << endl;
	cout << "|-----------|---------------------|" << endl;

	for (x = x_start;x <= x_end;x += x_shag) {
		if (x > 5 && x < 10 && x != -5.0 / 2) {
			y = Function(x);

		}
		else if (x > -5 && x <= 2) {
			y = x;

		}
		else {
			y = 1.0 / pow(x, 2);

		}

		cout << "|   " << setw(8);
		if (x < 0.0000001 && x > -0.0000001)cout << "0";
		else cout << x;
		cout << "| " << setw(19);
		if (x >= 6 && x <= 10) cout << "Не входить в ОДЗ";
		else if (x < 0.0000001 && x > -0.0000001) cout << "0";
		else cout << y;
		cout << " |" << endl;
	}

	cout << "|-----------|---------------------|" << endl;
}

void second_task(double Accuracy, int x_2) {
	 double current_member = x_2;
	 double sum = 1, sum_while = 1, sum_do_while = 1;
	 double i, j = 0;
	 for (i = 0;abs(current_member) > Accuracy; j++, sum += current_member, i++)
	 {
		 current_member *= -(x_2 * x_2) / (i + 1);
		 if (j == 7) cout << "Сума перших 5 членів ряду Тейлора =" << setprecision(16) << sum << endl;
	 }

	 j = 0;
	 i = 0;
	 current_member = x_2;

	 while (abs(current_member) > Accuracy)
	 {
		 current_member *= -(x_2 * x_2) / (i + 1);

		 j++;
		 sum_while += current_member;
		 i++;
	 }

	 j = 0;
	 i = 0;
	 current_member = x_2;

	 do
	 {
		 
		 current_member *= -(x_2 * x_2) / (i + 1);


		 sum_do_while += current_member;
		 j++;
		 i++;
	 } while (abs(current_member) > Accuracy);

	 cout << setprecision(18) << "Сума ряду Тейлора = " << sum  << endl;
	 cout << setprecision(18) << "Сума ряду Тейлора = " << sum_while << endl;
	 cout << setprecision(18) << "Сума ряду Тейлора = " << sum_do_while << endl;
	 cout << "\t   e^-x^2 = " << setprecision(18) << exp(-(x_2 * x_2)) << endl;
	 cout << "Кількість ітерацій = " << j << endl;
}

void Checking_number_for_first_task(double& x_start, double& x_end, double& x_shag) {
	while (((x_start || x_end || x_shag) == !cin) || x_end < x_start || x_shag <= 0) {
		if ((x_start || x_end || x_shag) == !cin) {
			cout << "Ви ввели не число" << endl;
			cout << "Введіть значення знову у послідовності (початок інтервалу, кінець інтервалу та шаг):";
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> x_start >> x_end >> x_shag;
		}
		else if (x_end < x_start && x_shag <= 0) {
			cout << "Кінець інтервалу повинен бути більше за початок, та шаг повинен бути додатнім" << endl;
			cout << "Введіть значення знову у послідовності (початок інтервалу, кінець інтервалу та шаг):";
			cin >> x_start >> x_end >> x_shag;
		}
		else if (x_end < x_start) {
			cout << "Кінець інтервалу повинен бути більше за початок" << endl;
			cout << "Введіть значення знову у послідовності (початок інтервалу, кінець інтервалу та шаг):";
			cin >> x_start >> x_end >> x_shag;
		}
		else if (x_shag <= 0) {
			cout << "Шаг повинен бути додатнім (він не може бути нулем або від'ємним)" << endl;
			cout << "Введіть значення знову у послідовності (початок інтервалу, кінець інтервалу та шаг):";
			cin >> x_start >> x_end >> x_shag;
		}
	}
 }

void Checking_number_for_second_task(double& Accuracy, int& x_2) {
	cin.clear();
	cin.ignore(32767, '\n');
	while ((Accuracy == !cin) || (x_2 == !cin)) {
		if ((Accuracy == !cin) || (x_2 == !cin)) {
			cout << "\nВи ввели не число\n";
			cout << "Введіть точність розрахунців та аргумент (х)\nУ послідовності перша - це точність, далі друга - аргумент: ";
			cin >> Accuracy >> x_2;
		}
		cin.clear();
		cin.ignore(32767, '\n');
	}

	cout << endl;
}

 int main(int argc, char* argv[])
 {
	 SetConsoleCP(1251);
	 SetConsoleOutputCP(1251);
	 cout << "\t\tЛабораторна робота № 6" << endl;
	
     cout << "\t\tЗавдання № 1" << endl << endl;
	 double x_start, x_end, x_shag;
	 int choice_to_try_again;
	 if (argc == 4)
	 {
		 x_start = atof(argv[1]);
		 x_end = atof(argv[2]);
		 x_shag = atof(argv[3]);
		 if ((x_start || x_end || x_shag) == !cin) {
			 cout << "Ви ввели не число" << endl;
			 cout << "Введіть значення знову у послідовності (початок інтервалу, кінець інтервалу та шаг):";
			 cin.clear();
			 cin.ignore(32767, '\n');
			 cin >> x_start >> x_end >> x_shag;
		 }
	 }
	 
	 else
	 {
		 cout << "Ви не ввели всі значення, будь ласка введіть значеня у цій послідовності" << endl;
		 cout << "Введіть початок інтервалу, кінець інтервалу та шаг: ";
		 cin >> x_start >> x_end >> x_shag;

	 }

	   Checking_number_for_first_task(x_start, x_end, x_shag);
	
		first_task(x_start, x_end, x_shag);
			
		
		
		cout << "Щоб продовжити pоботу цієї програми, напишіть, 1 - продовжити, 0 - закінчиити:";
		cin >> choice_to_try_again;
		while (choice_to_try_again == 1) {
			switch (choice_to_try_again) {
			case 1:
				cout << "Введіть початок інтервалу, кінець інтервалу та шаг: ";
				cin >> x_start >> x_end >> x_shag;
				Checking_number_for_first_task(x_start, x_end, x_shag);
				cout << endl;
				first_task(x_start, x_end, x_shag);
				cout << endl;
				cout << "Щоб продовжити роботу цієї програми, напишіть, 1 - продовжити, 0 - закінчиити:";
				cin >> choice_to_try_again;
				break;
			default:
				cout << "Програма переходить до іншого завдання ";
				break;
			}
		}
		
	 cout << "\t\tЗавдання № 2" << endl << endl;
	 double Accuracy;
	 int x_2;
	 int choice_to_try_again_2;


	 cout << "Калькулятор  e^-x^2" << endl << endl;
	 cout << "Введіть точність розрахунців та аргумент (х)\nУ послідовності перша - це точність, далі друга - аргумент: ";
	 cin >> Accuracy >> x_2;
	 
	Checking_number_for_second_task(Accuracy,x_2);
	second_task(Accuracy,x_2);

	
	
	cout << "Щоб продовжити роботу цієї програми, напишіть, 1 - продовжити, 0 - закінчиити:";
	cin >> choice_to_try_again_2;  
	while (choice_to_try_again_2 == 1) {
		switch (choice_to_try_again_2) {
		case 1:
			cout << "Введіть точність розрахунців та аргумент (х)\nУ послідовності перша - це точність, далі друга - аргумент: ";
			cin >> Accuracy >> x_2;
			cout << endl;
			Checking_number_for_second_task(Accuracy, x_2);
			second_task(Accuracy,x_2);
			cout << endl;
			cout << "Щоб продовжити роботу цієї програми, напишіть, 1 - продовжити, 0 - закінчиити:";
			cin >> choice_to_try_again_2;
			break;
		default:
			cout << "Програма закінчила свою роботу";
			break;
		}
	}
	
	system("pause");
	return 0;
}