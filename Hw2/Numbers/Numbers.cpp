#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void number1() {
	char sym1, sym2, sym3;
	cout << "������� ������ �����:" << endl;
	cin >> sym1;
	cout << "������� ������ �����:" << endl;
	cin >> sym2;
	cout << "������� ������ �����" << endl;
	cin >> sym3;

	string comb;
	comb += sym1;
	comb += sym2;
	comb += sym3;
	cout << "������������ ����� - " << comb << endl;

	cout << "������������ ����� �����" << endl;
	
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
	cout << "������� ���������� 'a' � 'b' �� ����� �������: " << endl;
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
	cout << "������� ����� �� 1 �� 100" << endl;
	cin >> x;
	if (x >= 1 && x <= 100) {
		cout << "����� ����������" << endl;
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
		cout << "����� ������������" << endl;
	}
}

void number5() {
	int a, b;
	cout << "������� ������ ����� " << endl;
	cin >> a;
	cout << "������� ������ ����� " << endl;
	cin >> b;
	if (a != 0) {
		if (b % a == 0) {
			cout << "������ ����� ������ �������" << endl;
		}
		else {
			cout << "������ ����� �������� �������" << endl;
		}
	}
	else {
		cout << "�� 0 ������ ������" << endl;
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
		cout << "������� �����" << endl;
		cin >> input;
		num.push_back(input);
		cout << "�� ��������� ���� �����? Y/y - ��, N/n - ���" << endl;
		cin >> ans;
		if (ans == 'Y' || ans == 'y') {
			condition = false;
			for (int i = 0; i < num.size(); i++) {
				suma += num[i];
			}
			cout << "����� �������� ����� - " << suma << endl;
			sraref = suma / num.size();
			cout << "������� �������������� ��������� ����� - " << sraref << endl;
		}
		else if (ans != 'N' && ans != 'n' && ans && 'Y' && ans != 'y') {
			cout << "������������ �����" << endl;
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
	cout << "�������� ����� ������ ������ �����������: " << endl;
	cout << "������ 1" << endl;
	cout << "������ 2" << endl;
	cout << "������ 3" << endl;
	cout << "������ 4" << endl;
	cout << "������ 5" << endl;
	cout << "������ 6" << endl;
	cout << "������ 7" << endl;
	cout << "������� ����� ��������� ������" << endl;
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
	cout << "������ ����������?" << endl;
	cout << "�� - 1" << endl;
	cout << "��� - 2" << endl;
	cin >> choice;

	if (choice == 1) {
		return main();
	}
	else {
		return 0;
	}
}