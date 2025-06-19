#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void number1() {
	char sym1, sym2, sym3;
	cout << "Введите первую цифру:" << endl;
	cin >> sym1;
	cout << "Введите вторую цифру:" << endl;
	cin >> sym2;
	cout << "Введите третью цифрц" << endl;
	cin >> sym3;

	string comb;
	comb += sym1;
	comb += sym2;
	comb += sym3;
	cout << "Объедененное число - " << comb << endl;

	cout << "Посимвольный вывод числа" << endl;
	
	sym1 = comb[0];
	sym2 = comb[1];
	sym3 = comb[2];
	cout << sym1 << endl;
	cout << sym2 << endl;
	cout << sym3 << endl;

}

void number2() {
	unsigned int color = 0x04F1A2u;
	unsigned char red = (color >> 16) & 0xFF;
	unsigned char green = (color >> 8) % 0xFF;
	unsigned char blue = color & 0xFF;
	cout << "Color: #" << hex << setfill('0') << setw(2) << static_cast<int>(red)
		<< setw(2) << static_cast<int>(green)
		<< setw(2) << static_cast<int>(blue)
		<< endl;
	cout << "Red: " << dec << static_cast<int>(red) << endl;
	cout << "Green: " << static_cast<int>(green) << endl;
	cout << "Blue: " << static_cast<int>(blue) << endl;

}

void number3() {
	int a, b;
	cout << "Введите переменную 'a' и 'b' на новых строках: " << endl;
	cin >> a;
	cin >> b;

	cout << "a = " << a << " b = " << b << endl;

	a ^= b;
	b ^= a;
	a ^= b;

	cout << "a = " << a << " b = " << b << endl;
}

void number4() {
	int x;
	cout << "Введите число от 1 до 100" << endl;
	cin >> x;
	if (x >= 1 && x <= 100) {
		cout << "Число корректное" << endl;
		if (x > 50) {
			cout << x << " > " << "50" << endl;
		}
		else if (x < 50) {
			cout << x << " < " << "50" << endl;
		}
		else {
			cout << x << " = " << "50" << endl;
		}
	}
	else {
		cout << "Число некорректное" << endl;
	}
}

void number5() {
	int a, b;
	cout << "Введите первое число " << endl;
	cin >> a;
	cout << "Введите второе число " << endl;
	cin >> b;
	if (a != 0) {
		if (b % a == 0) {
			cout << "Второе число кратно первому" << endl;
		}
		else {
			cout << "Второе число некратно первому" << endl;
		}
	}
	else {
		cout << "На 0 делить нельзя" << endl;
	}
}

void number6() {
	vector<int> num;
	int input;
	double sraref;
	double suma = 0;
	bool condition = true;
	char ans;
	while (condition) {
		cout << "Введите число" << endl;
		cin >> input;
		num.push_back(input);
		cout << "Вы закончили ввод чисел? Y/y - да, N/n - нет" << endl;
		cin >> ans;
		if (ans == 'Y' || ans == 'y') {
			condition = false;
			for (int i = 0; i < num.size(); i++) {
				suma += num[i];
			}
			cout << "Сумма введеных чисел - " << suma << endl;
			sraref = suma / num.size();
			cout << "Среднее арифмитическое введенных чисел - " << sraref << endl;
		}
		else if (ans != 'N' && ans != 'n' && ans && 'Y' && ans != 'y') {
			cout << "Некорректный ответ" << endl;
		}
	}
}

void number7() {
	int const SIZE = 7;
	int num[SIZE] = {};
	for (int i = 0; i < SIZE; i++) {
		num[i] = 1 + rand() % 100;
		cout << num[i] << " ";
	}
	cout << " " << endl;

	for (int i = SIZE - 1; i >= 0; i--) {
		cout << num[i] << " ";
	}
}

int main() {
	setlocale(LC_ALL, "RU");

	srand(time(0));

	int num;
	int choice;
	cout << "Выберите какую задачу хотите просмотреть: " << endl;
	cout << "Задача 1" << endl;
	cout << "Задача 2" << endl;
	cout << "Задача 3" << endl;
	cout << "Задача 4" << endl;
	cout << "Задача 5" << endl;
	cout << "Задача 6" << endl;
	cout << "Задача 7" << endl;
	cout << "Введите номер выбранной задачи" << endl;
	cin >> num;
	cout << " " << endl;
	
	switch (num) {
	case 1:
		number1();
		break;
	case 2:
		number2();
		break;
	case 3:
		number3();
		break;
	case 4:
		number4();
		break;
	case 5:
		number5();
		break;
	case 6:
		number6();
		break;
	case 7:
		number7();
		break;
	}

	cout << " " << endl;
	cout << "Хотите продолжить?" << endl;
	cout << "Да - 1" << endl;
	cout << "Нет - 2" << endl;
	cin >> choice;

	if (choice == 1) {
		return main();
	}
	else {
		return 0;
	}
}