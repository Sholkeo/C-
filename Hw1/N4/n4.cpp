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
	cout << "������� ����� 'a' " << endl;
	cin >> a;
	cout << "������� ����� 'b' " << endl;
	cin >> b;
	cout << "������� ����� 'c' " << endl;
	cin >> c;
	/*cout << d << endl;*/

	a = round(a * 10000) / 10000;
	b = round(b * 10000) / 10000;
	c = round(c * 10000) / 10000;
	
	resh = 2*log((a+b/2-c/a)+d*3-sqrt(c*a*a-(a+b)));
	resh = round(resh * 10000) / 10000;
	cout << "����� ��������� �����: " << resh;
}