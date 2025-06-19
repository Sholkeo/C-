#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void number1() {
	string vvod, userAlpf;
	string alpflow = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int sizeAlpf = 1 + rand() % 62;
	int suma = 0;

	srand(time(0));
	for (int i = 0; i < sizeAlpf; i++) {
		int x = 0 + rand() % 61;
		if (userAlpf.find(alpflow[x]) == string::npos ) {
			userAlpf += alpflow[x];
		}
	}

	cout << "���������������� �������: " << endl;
	for (size_t i = 0; i < userAlpf.size(); i++) {
		cout << userAlpf[i];
	}
	cout << " " << endl;

	cout << "������� ��������� ������ �� �������� ���������� �������� � ����" << endl;
	cin >> vvod;
	for (size_t i = 0; i < vvod.size(); i++) {
		if (alpflow.find(vvod[i]) == string::npos) {
			cout << "������������ ����" << endl;
			return number1();
		}
	}
	for (size_t i = 0; i < vvod.size(); i++) {
		if (userAlpf.find(vvod[i]) != string::npos) {
			size_t foundpos = userAlpf.find(vvod[i]);
			cout << "C����� �� ������: " << vvod[i]
				<< " ������ �� ��������: " << userAlpf[foundpos]
				<< " ������ ������� �� ��������: " << foundpos+1 << endl;
			suma++;
		}
	}
	cout << "���������� ����������: " << suma << endl;

}

void number2() {
	srand(time(0));

	int num[50] = {};
	int nechet, numSize = 0;
	int* ptr = num; 

	while (numSize < 50) {
		nechet = 1 + rand() % 100;
		if (nechet % 2 != 0) {
			num[numSize] = nechet;
			numSize++;
		}
	}

	for (int i = 0; i < 25; i++) {
		cout << *ptr << " ";
		ptr++;
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}
	cout << "|| ";

	ptr = num + 26;
	for (int i = 0; i < 25; i++) {
		cout << *ptr << " ";
		ptr--;
		if (i == 4 || i == 14 || i == 24) {
			cout << endl;
		}
	}
	
}

void number3() {
	int choice, num;
	char sym;
	cout << "������� ����� �/� ������������" << endl;
	cin >> choice;
	cout << "������� ������� �� �������� ����� �������� �����������" << endl;
	cin >> sym;
	cout << "������� ���������� �������������" << endl;
	cin >> num;

	for (int k = 0; k < num; k++) {
		for (int i = 0; i < choice; i++) {
			for (int j = 0; j < choice - i - 1;j++) {
				cout << " ";
			}

			for (int j = 0; j < 2 * i + 1;j++) {
				cout << sym;
			}
			cout << endl;
		}
		cout << endl;
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