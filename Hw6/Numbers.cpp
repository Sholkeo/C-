#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cctype>
#include <unordered_map>
#include <stdexcept>


using namespace std;

string cleanWord(const string& word) {
	string cleaned;
	for (char c : word) {
		if (isalpha((unsigned char)c)) {
			cleaned += toupper((unsigned char)c); 
		}
	}
	return cleaned;
}

void number1() {
	int rowsCols = 1 + rand() % 7;
	vector<vector<int>> matrix(rowsCols, vector<int>(rowsCols));

	for (int i = 0; i < rowsCols; i++) {
		for (int j = 0; j < rowsCols; j++) {
			matrix[i][j] = -100 + rand() % 201;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	vector<int> diagonal;
	for (size_t i =0; i < rowsCols; i++){
		diagonal.push_back(matrix[i][i]);
	}

	vector<int> upDiagonal;
	for (size_t i = 0; i < rowsCols; i++) {
		for (size_t j = i + 1; j < rowsCols; j++) {
			upDiagonal.push_back(matrix[i][j]); 
		}
	}

	vector<int> unDiagonal;
	for (size_t i = 0; i < rowsCols; i++) {
		for (size_t j = 0; j < i && j < rowsCols; j++) {
			unDiagonal.push_back(matrix[i][j]);
		}
	}

	auto maxItUp = max_element(upDiagonal.begin(), upDiagonal.end());
	int maxUp = *maxItUp;

	auto minItUn = min_element(unDiagonal.begin(), unDiagonal.end());
	int minUn = *minItUn;

	cout << "Max: " << maxUp << " Min: " << minUn << endl;
	swap(maxUp, minUn);
	cout << "Max: " << maxUp << " Min: " << minUn << endl;
}

void number2() {
	ifstream file("C:\\Users\\Genetal\\C-\\Hw6\\Text.txt");
	if (!file.is_open()) {
		cout << "Ошибка открытия файла Text.txt!" << endl;
		return;
	}

	string line;
	unordered_map<string, int> wordCount;

	while (getline(file, line)) {
		istringstream iss(line);
		string word;
		
		while (iss >> word) {
			string cleaned = cleanWord(word);
			if (!cleaned.empty()) {
				wordCount[cleaned]++;
			}
		}
	}
	file.close();
	

	string maxWord;
	int maxCount = 0;
	for (const auto& pair : wordCount) {
		if (pair.second > maxCount ||
			(pair.second == maxCount && pair.first < maxWord)) {
			maxCount = pair.second;
			maxWord = pair.first;
		}
	}

	

	cout << "Самое частое слово в тексте: " << maxWord << " Количество повторений: " << maxCount << endl;
}

vector<vector<int>> readMatrix(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		throw runtime_error("Не удалось открыть файл: " + filename);
	}

	int rows, cols;
	file >> rows >> cols;

	vector<vector<int>> matrix(rows, vector<int>(cols));
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			file >> matrix[i][j];
		}
	}

	return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
	for (const auto& row : matrix) {
		for (int val : row) {
			cout << val << "\t";
		}
		cout << endl;
	}
}

vector<vector<int>> addMatrices(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	if (a.size() != b.size() || a[0].size() != b[0].size()) {
		throw runtime_error("Матрицы разных размеров нельзя сложить");
	}

	vector<vector<int>> result(a.size(), vector<int>(a[0].size()));
	for (size_t i = 0; i < a.size(); ++i) {
		for (size_t j = 0; j < a[0].size(); ++j) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}

	return result;
}

vector<vector<int>> subtractMatrices(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	if (a.size() != b.size() || a[0].size() != b[0].size()) {
		throw runtime_error("Матрицы разных размеров нельзя вычесть");
	}

	vector<vector<int>> result(a.size(), vector<int>(a[0].size()));
	for (size_t i = 0; i < a.size(); ++i) {
		for (size_t j = 0; j < a[0].size(); ++j) {
			result[i][j] = a[i][j] - b[i][j];
		}
	}

	return result;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	if (a[0].size() != b.size()) {
		throw runtime_error("Несовместимые размеры матриц для умножения");
	}

	vector<vector<int>> result(a.size(), vector<int>(b[0].size(), 0));
	for (size_t i = 0; i < a.size(); ++i) {
		for (size_t j = 0; j < b[0].size(); ++j) {
			for (size_t k = 0; k < a[0].size(); ++k) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return result;
}

void number3() {
	auto matrixA = readMatrix("C:\\Users\\Genetal\\C-\\Hw6\\Matrix1.txt");
	auto matrixB = readMatrix("C:\\Users\\Genetal\\C-\\Hw6\\Matrix2.txt");

	cout << "Матрица A:" << endl;
	printMatrix(matrixA);
	cout << endl;
	cout << "Матрица B:" << endl;
	printMatrix(matrixB);
	cout << endl;

	cout << "Сумма матриц:" << endl;
	auto sum = addMatrices(matrixA, matrixB);
	printMatrix(sum);
	cout << endl;

	cout << "Разность матриц:" << endl;
	auto diff = subtractMatrices(matrixA, matrixB);
	printMatrix(diff);
	cout << endl;

	cout << "Произведение матриц:" << endl;
	auto product = multiplyMatrices(matrixA, matrixB);
	printMatrix(product);
	cout << endl;



}


int main() {
	setlocale(LC_ALL, "RU");

	srand(time(0));

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