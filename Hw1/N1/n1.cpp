#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	double x;
		cout << "Введите значение в метрах" << endl;
		cin >> x;
		cout << "Ваше значение в километрах: " << x/1000;
};