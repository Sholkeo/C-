#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
	srand(time(0));
	setlocale(LC_ALL, "RU");

	double a, b, c;
	double d = rand() % 200;
	double resh;
	cout << "¬ведите число 'a' " << endl;
	cin >> a;
	cout << "¬ведите число 'b' " << endl;
	cin >> b;
	cout << "¬ведите число 'c' " << endl;
	cin >> c;
	/*cout << d << endl;*/

	a = round(a * 10000) / 10000;
	b = round(b * 10000) / 10000;
	c = round(c * 10000) / 10000;
	
	resh = 2*log((a+b/2-c/a)+d*3-sqrt(c*a*a-(a+b)));
	resh = round(resh * 10000) / 10000;
	cout << "ќтвет выражени€ равен: " << resh;
}