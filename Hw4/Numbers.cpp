#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void number1() {
	int num, step;
	cout << "Введите число" << endl;
	cin >> num;
	cout << "Введите степень числа" << endl;
	cin >> step;
	cout << "Результат возведения в степень: " << pow(num, step) << endl;
}

void number2() {
	srand(time(0));
	int vvod1, vvod2;
	int value = 0, value2 = 0;
	cout << "Введите размер массива 1" << endl;
	cin >> vvod1;
	cout << "Введите размер массива 2" << endl;
	cin >> vvod2;
	vector<vector<int>> num1(vvod1, vector<int>(vvod1));
	vector<vector<int>> num2(vvod2, vector<int>(vvod2));

	vector<int> data1(vvod1 * vvod1);
	for (int i = 0; i < vvod1 * vvod1; ++i) {
		data1[i] = i + 1; 
	}

	for (int d = 0; d < 2 * vvod1 - 1; ++d) { 
		if (d % 2 == 0) { 
			int row = min(d, vvod1 - 1);
			int col = d - row;
			while (row >= 0 && col < vvod1) {
				num1[row][col] = data1[value++];
				row--;
				col++;
			}
		}
		else {
			int col = min(d, vvod1 - 1);
			int row = d - col;
			while (col >= 0 && row < vvod1) {
				num1[row][col] = data1[value++];
				row++;
				col--;
			}
		}
	}

	vector<int> data2(vvod2 * vvod2);
	for (int i = 0; i < vvod2 * vvod2; ++i) {
		data2[i] = 1 + rand() % 100;
	}

	for (int d = 0; d < 2 * vvod2 - 1; ++d) {
		if (d % 2 == 0) {
			int row = min(d, vvod2 - 1);
			int col = d - row;
			while (row >= 0 && col < vvod2) {
				num2[row][col] = data2[value2++];
				row--;
				col++;
			}
		}
		else {
			int col = min(d, vvod2 - 1);
			int row = d - col;
			while (col >= 0 && row < vvod2) {
				num2[row][col] = data2[value2++];
				row++;
				col--;
			}
		}
	}

	for (int i = 0;i < vvod1;i++) {
		for (int j = 0;j < vvod1;j++) {
			cout << num1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0;i < vvod2;i++) {
		for (int j = 0;j < vvod2;j++) {
			cout << num2[i][j] << " ";
		}
		cout << endl;
	}

	
}

void number3() {
	string vvod;
	char res = vvod[0];
	int nowCount = 1, maxCount = 1;
	cout << "Введите вашу строку:" << endl;
	cin >> vvod;

	for (size_t i = 1;i < vvod.size(); i++) {
		if (vvod[i] == vvod[i - 1]) {
			nowCount++;
			if (nowCount > maxCount) {
				maxCount = nowCount;
				res = vvod[i];
			}
		}
		else {
			nowCount = 1;
		}
	}

	cout << "Символ: " << res << '\n' 
		<< "Количество: " << maxCount << endl;
}

int main() {
	setlocale(LC_ALL, "RU");

	int num;
	int choice;
	cout << "Выберите какую задачу хотите просмотреть: " << endl;
	cout << "Задача 1" << endl;
	cout << "Задача 2" << endl;
	cout << "Задача 3" << endl;
	cout << "Введите номер выбранной задачи" << endl;
	cin >> num;
	cout << endl;

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
	}

	cout << endl;
	cout << "Хотите продолжить?" << endl;
	cout << "Да - 1" << endl;
	cout << "Нет - 2" << endl;
	cin >> choice;
	cout << endl;

	if (choice == 1) {
		return main();
	}
	else {
		return 0;
	}
}