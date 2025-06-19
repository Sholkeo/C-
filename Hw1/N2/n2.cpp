#include <iostream>
#include <cctype>

using namespace std;

bool isLatinLetter(char c) {
	return (c >= 'A' && c <= 'Z');
}

int main() {
	setlocale(LC_ALL, "RU");


	char sym;
	cout << "������� ����� � ������ ��������" << endl;
	cin >> sym;
	if(isupper(sym)) {
		cout << "���� ����� ��� � ������� ��������" << endl;
	}
	else {
		char upper = toupper(sym);
		if (isLatinLetter(upper)) {
			cout << "���� ����� � ������� �������� - " << upper;
		}
		else {
			cout << "����� �� ���������";
		}
	}
}