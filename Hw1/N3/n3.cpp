#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	string x;
	cout << "Ведите пятизначное число" << endl;
	cin >> x;

	if (x.length() == 5) {
		cout << "Ваше число по символам" << endl;
		cout << x[0] << endl;
		cout << x[1] << endl;
		cout << x[2] << endl;
		cout << x[3] << endl;
		cout << x[4] << endl;
	}
	else {
		cout << "Ваше число не пятизначное";
	}
}