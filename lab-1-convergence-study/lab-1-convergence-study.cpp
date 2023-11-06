#include <iostream>
#include <iomanip>
#include "Functions.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RUSSIAN");

	cout << "Введите начальные значения" << endl;
	cout << "x1 = "; double x = 0; cin >> x;
	cout << "x2 = "; double y = 0; cin >> y;
	cout << "x3 = "; double z = 0; cin >> z;

	cout << "Введите номер метода:" << endl;
	cout << "1) Метод градиентного спуска с дроблением шага" << endl;
	cout << "2) Метод наискорейшего спуска" << endl;
	cout << "3) Метод покординатного спуска" << endl;
	cout << "4) Метод Флетчера-Ривса" << endl;
	int choice = 0; cin >> choice;

	switch (choice) {
		case 1: { // Метод градиентного спуска с дроблением шага
			GradStepSplit(x, y, z);
			break;
		}
		case 2: { // Метод наискорейшего спуска
			FastStep(x, y, z);
			break;
		}
		case 3: { // Метод покоординатного спуска
			Coordescent(x, y, z);
			break;
		}
		case 4: { // Метод Флетчера-Ривса
			FletRivs(x, y, z);
			break;
		}
	}
	system("pause");
	return 0;
}