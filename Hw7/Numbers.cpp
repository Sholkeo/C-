#include <iostream>
#include <filesystem>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <string>
#include <functional> 

using namespace std;

void printAttributes(DWORD attributes) {
	cout << (attributes & FILE_ATTRIBUTE_DIRECTORY ? "D" : " ");
	cout << (attributes & FILE_ATTRIBUTE_READONLY ? "R" : " ");
	cout << (attributes & FILE_ATTRIBUTE_HIDDEN ? "H" : " ");
	cout << (attributes & FILE_ATTRIBUTE_SYSTEM ? "S" : " ");
	cout << (attributes & FILE_ATTRIBUTE_ARCHIVE ? "A" : " ");
}

void printFileTime(const FILETIME& ft) {
	SYSTEMTIME st;
	FileTimeToSystemTime(&ft, &st);
	cout << setw(2) << setfill('0') << st.wDay << "."
		<< setw(2) << setfill('0') << st.wMonth << "."
		<< st.wYear << " "
		<< setw(2) << setfill('0') << st.wHour << ":"
		<< setw(2) << setfill('0') << st.wMinute;
}

void listDirectory(const string& path = ".") {
	WIN32_FIND_DATAA findData;
	HANDLE hFind = FindFirstFileA((path + "\\*").c_str(), &findData);

	if (hFind == INVALID_HANDLE_VALUE) {
		cerr << "Ошибка при открытии директории" << endl;
		return;
	}

	char currentDir[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, currentDir);
	cout << " Содержимое папки " << currentDir << "\n\n";
	cout << " Атрибуты   Дата изменения        Размер    Имя\n";
	cout << "----------  -------------------  ----------  ------------------------\n";

	do {
		if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) {
			continue;
		}

		printAttributes(findData.dwFileAttributes);
		cout << "  ";
		printFileTime(findData.ftLastWriteTime);
		cout << "  ";

		if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			cout << setw(10) << findData.nFileSizeLow << "  ";
		}
		else {
			cout << setw(10) << "<DIR>" << "  ";
		}

		cout << findData.cFileName << "\n";

	} while (FindNextFileA(hFind, &findData) != 0);

	FindClose(hFind);
}

void number1() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Аналог команды DIR в DOS\n";
	cout << "-----------------------\n\n";

	listDirectory();
}	

void number2() {

}

void generateCombinations(const string& charset, int maxLength, const string& realPassword) {
	ofstream outFile("combinations.txt", ios::app);

	function<void(string)> brute = [&](string current) {
		if (current.length() > maxLength) return;

		if (!current.empty()) {
			outFile << current << endl;

			if (current == realPassword) {
				cout << "\nПароль найден: " << current << endl;
				exit(0); 
			}
		}
		
		for (char c : charset) {
			brute(current + c);
		}
		};

	brute(""); 
	cout << "Пароль не найден (ограничение длины)" << endl;
}

void number3() {
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
	const int maxLength = 4;

	string realPassword;
	cout << "Введите пароль для подбора (до 4 символов): ";
	cin >> realPassword;

	if (realPassword.length() > maxLength) {
		cerr << "Ошибка: пароль слишком длинный (макс. " << maxLength << " символов)" << endl;
		return number3();
	}

	ofstream clearFile("combinations.txt", ios::trunc);
	clearFile.close();

	generateCombinations(charset, maxLength, realPassword);

}

int main() {
	setlocale(LC_ALL, "RU");

	int num;
	int choice;
	cout << "Выберите какую задачу хотите просмотреть: " << endl;
	cout << "Задача 1" << endl;
	cout << "Задача 2" << endl;
	cout << "Задача 3" << endl;
	cout << "Введите номер выбранной задачи" << endl;
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
	cout << "Хотите продолжить?" << endl;
	cout << "Да - 1" << endl;
	cout << "Нет - 2" << endl;
	cin >> choice;

	if (choice == 1) {
		return main();
	}
	else {
		return 0;
	}
}