#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int col = 0;
	string alph = "12345";
	string x;
	cout << "Ведите пятизначное число" << endl;
	cin >> x;

	if (x.length() == 5) {
		for (int i = 0; i < 5; i++) {
			if (alph.find(x[i]) != string::npos) {
				col++;
			}
		}
		if (col == 5) {
			cout << "Ваше число по символам" << endl;
			for (int i = 0; i < 5; i++) {
				cout << x[i] << endl;
			}
		}
		else {
			cout << "Некорректный ввод" << endl;
		}
		
	}
	else {
		cout << "Ваше число не пятизначное" << endl;
	}
	cout << endl;
	
	return main();
}