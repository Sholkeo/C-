#include <iostream>
#include <filesystem>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <string>
#include <functional> 
#include <climits>
#include <limits>

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
		cerr << "������ ��� �������� ����������" << endl;
		return;
	}

	char currentDir[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, currentDir);
	cout << " ���������� ����� " << currentDir << "\n\n";
	cout << " ��������   ���� ���������        ������    ���\n";
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

	cout << "������ ������� DIR � DOS\n";
	cout << "-----------------------\n\n";

	listDirectory();
}	

const int MAX_SIZE = 100;

struct Request {
	int priority; 
	int data;     
};

class PriorityQueue {
private:
	Request queue[MAX_SIZE]; 
	int front;              
	int rear;               
	int size;               

public:
	PriorityQueue() : front(0), rear(-1), size(0) {}

	void enqueue(int data, int priority) {
		if (isFull()) {
			cout << "������� �����������!\n";
			return;
		}

		if (isEmpty()) {
			rear = front;
			queue[rear] = { priority, data };
			size++;
			return;
		}

		int insertPos = rear + 1;
		if (insertPos == MAX_SIZE) {
			insertPos = 0; 
		}

		queue[insertPos] = { priority, data };
		rear = insertPos;
		size++;
	}

	Request dequeue() {
		if (isEmpty()) {
			cout << "������� �����!\n";
			return { INT_MAX, -1 };
		}

		int highestPriority = INT_MAX;
		int highestPriorityPos = -1;

		for (int i = 0; i < size; ++i) {
			int currentPos = (front + i) % MAX_SIZE;
			if (queue[currentPos].priority < highestPriority) {
				highestPriority = queue[currentPos].priority;
				highestPriorityPos = currentPos;
			}
		}

		Request highestPriorityRequest = queue[highestPriorityPos];

		for (int i = highestPriorityPos; i != rear; i = (i + 1) % MAX_SIZE) {
			queue[i] = queue[(i + 1) % MAX_SIZE];
		}
		rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
		size--;

		return highestPriorityRequest;
	}

	bool isEmpty() const {
		return size == 0;
	}

	bool isFull() const {
		return size == MAX_SIZE;
	}
	
	void printQueue() const {
		if (isEmpty()) {
			cout << "������� �����.\n";
			return;
		}

		cout << "������� �������:\n";
		for (int i = 0; i < size; ++i) {
			int currentPos = (front + i) % MAX_SIZE;
			cout << "Data: " << queue[currentPos].data
				<< ", Priority: " << queue[currentPos].priority << "\n";
		}
	}
};

void clearInputBuffer() {
	std::cin.clear();
	#ifdef max
	#undef max
	#endif
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void number2() {
	PriorityQueue pq;
	int choice, data, priority;

	while (true) {
		cout << "\n����:\n"
			<< "1. �������� ������ (enqueue)\n"
			<< "2. ������� ������ (dequeue)\n"
			<< "3. �������� �������\n"
			<< "4. �����\n"
			<< "�������� ��������: ";

		if (!(std::cin >> choice)) {
			clearInputBuffer();
			std::cout << "������ �����. ���������� �����.\n";
			continue;
		}

		switch (choice) {
		case 1:
			std::cout << "������� ������ (�����): ";
			if (!(std::cin >> data)) {
				clearInputBuffer();
				std::cout << "������ ����� ������!\n";
				break;
			}

			std::cout << "������� ��������� (��� ������, ��� ����): ";
			if (!(std::cin >> priority)) {
				clearInputBuffer();
				std::cout << "������ ����� ����������!\n";
				break;
			}

			pq.enqueue(data, priority);
			std::cout << "������ ��������.\n";
			break;

		case 2: 
			if (pq.isEmpty()) {
				std::cout << "������� �����!\n";
			}
			else {
				Request r = pq.dequeue();
				std::cout << "���������: Data = " << r.data
					<< ", Priority = " << r.priority << "\n";
			}
			break;

		case 3: 
			pq.printQueue();
			break;

		case 4: 
			std::cout << "���������� ������.\n";
			return;

		default:
			std::cout << "�������� �����. ���������� �����.\n";
		}
	}
}


void generateCombinations(const string& charset, int maxLength, const string& realPassword) {
	ofstream outFile("combinations.txt", ios::app);

	function<void(string)> brute = [&](string current) {
		if (current.length() > maxLength) return;

		if (!current.empty()) {
			outFile << current << endl;

			if (current == realPassword) {
				cout << "\n������ ������: " << current << endl;
				exit(0); 
			}
		}
		
		for (char c : charset) {
			brute(current + c);
		}
		};

	brute(""); 
	cout << "������ �� ������ (����������� �����)" << endl;
}

void number3() {
	const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
	const int maxLength = 4;

	string realPassword;
	cout << "������� ������ ��� ������� (�� 4 ��������): ";
	cin >> realPassword;

	if (realPassword.length() > maxLength) {
		cerr << "������: ������ ������� ������� (����. " << maxLength << " ��������)" << endl;
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