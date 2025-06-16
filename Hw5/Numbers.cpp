#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <windows.h>

using namespace std;

int calculate(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a, b);
	default: return 0;
	}
}

double calculate(double a, double b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a, b);
	default: return 0.0;
	}
}

string calculate(string a, string b, char op) {
	switch (op) {
	case '+': return a + b;
	case '*': {
		int n = stoi(b);
		string res;
		for (int i = 0; i < n; i++) res += a;
		return res;
	}
	default: return "";
	}
}

void number1() {
	int choice;
	char op;
	cout << "�������� ��� ������: " << endl;
	cout << "1 - int " << endl;
	cout << "2 - double" << endl;
	cout << "3 - string " << endl;
	cin >> choice;
	switch (choice) {
	case 1: {
		int a, b, res;
		cout << "������� �������� ������ ����������: " << endl;
		cin >> a;
		cout << "������� �������� ������ ����������: " << endl;
		cin >> b;
		cout << "������� ���� ��������: " << endl;
		cin >> op;
		res = calculate(a, b, op);
		cout << "��������� ����������: " << res << endl;
	}
		  break;
	case 2: {
		double a, b;
		int res;
		cout << "������� �������� ������ ����������: " << endl;
		cin >> a;
		cout << "������� �������� ������ ����������: " << endl;
		cin >> b;
		cout << "������� ���� ��������: " << endl;
		cin >> op;
		res = calculate(a, b, op);
		cout << "��������� ����������: " << res << endl;
	}
		  break;
	case 3: {
		string a, b;
		cout << "������� �������� ������ ����������: " << endl;
		cin >> a;
		cout << "������� �������� ������ ����������: " << endl;
		cin >> b;
		cout << "������� ���� ��������: " << endl;
		cin >> op;
		cout << "��������� ����������: " << calculate(a, b, op) << endl;
	}
		  break;
	}
}

void number2() {
	static vector<int> us;
	int x;
	bool choice = true;
	char sym;
	cout << "������� �����: " << endl;
	cin >> x;
	us.push_back(x);
	for (size_t i = 0; i < us.size(); i++) {
		cout << us[i] << " ";
	}
	cout << endl;
	while (choice) {
		cout << "���� ������ ��������� �������� 'Y/y', ���� ��� 'N/n'" << endl;
		cin >> sym;
		if (sym == 'y' || sym == 'Y') {
			choice = false;
			us.clear();
			break;
		}
		else if (sym == 'n' || sym == 'N'){
			return number2();
		}
		else {
			cout << "������������ ����" << endl;
		}
	} 
}

void number3() {
	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251);       

	string text;
	vector<string> words;
	int choice;
	cout << "������� ���� ������" << endl;
	getline(cin >> ws, text);
	cout << "�������� ����� ����� �� �������� ����� ������� ������" << endl;
	cin >> choice;
	cin.ignore();

	stringstream ss(text);
	string word;
	while (ss >> word) {
		words.push_back(word);
	}
	if (!words[choice - 1].empty()) {
		words[choice - 1].erase(0,1); 
	}
	for (size_t i = 0; i < words.size(); i++) {
		cout << words[i] << " ";
	}


	SetConsoleOutputCP(866);
	SetConsoleCP(866);
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