#include <iostream>
#include <cctype>

using namespace std;

bool isLatinLetter(char c) {
	return (c >= 'A' && c <= 'Z');
}

int main() {
	setlocale(LC_ALL, "RU");


	char sym;
	cout << "Введите букву в нижнем регистре" << endl;
	cin >> sym;
	if(isupper(sym)) {
		cout << "Ваше буква уже в верхнем регистре" << endl;
	}
	else {
		char upper = toupper(sym);
		if (isLatinLetter(upper)) {
			cout << "Ваша буква в верхнем регистре - " << upper;
		}
		else {
			cout << "Буква не латинская";
		}
	}
}