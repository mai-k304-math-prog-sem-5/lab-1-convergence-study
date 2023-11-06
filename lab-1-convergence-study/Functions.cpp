#include <iostream>
#include <iomanip>
#include "Functions.h"

// ��������������� �������
double function(double x, double y, double z) { // �������� �������
	return (-3 * x * x - 2 * y * y - 2 * z * z + x * y + y * z - x * z + 5 * x);
}
double derivativex(double x, double y, double z) { // ������� ������� ����������� �� x
	int h = 1;
	return ((function(x + h, y, z) - function(x - h, y, z)) / 2 * h);
}
double derivativey(double x, double y, double z) { // ������� ������� ����������� �� y
	int h = 1;
	return ((function(x, y + h, z) - function(x, y - h, z)) / 2 * h);
}
double derivativez(double x, double y, double z) { // ������� ������� ����������� �� z
	int h = 1;
	return ((function(x, y, z + h) - function(x, y, z - h)) / 2 * h);
}
double grad(double x, double y, double z) { // ������� ��������� �������
	double h = 1; //��� ��� ���������� ������� �����������
	double derivativex = ((function(x + h, y, z) - function(x - h, y, z)) / 2 * h);
	double derivativey = ((function(x, y + h, z) - function(x, y - h, z)) / 2 * h);
	double derivativez = ((function(x, y, z + h) - function(x, y, z - h)) / 2 * h);
	return (sqrt(derivativex * derivativex + derivativey * derivativey + derivativez * derivativez));
}

using namespace std;

// ������� ��������� �������
void GradStepSplit(double currentx, double currenty, double currentz) { // ����� ������������ ������ � ���������� ����
	double nextx = currentx;
	double nexty = currenty;
	double nextz = currentz;
	double step = 0.1; // ���
	int count = 0; // ������� ������
	double eps = 0.001; // ��������

	double f = function(currentx, currenty, currentz);
	double fg = 0;

	cout << "x1 " << setw(18) << "x2" << setw(18) << "x3" << setw(20) << "f(x1,x2,x3)" << setw(12) << "grad" << endl;
	cout << currentx << setw(16) << currenty << setw(16) << currentz << setw(16) << f << setw(16) << grad(currentx, currenty, currentz) << endl;

	do {
		// ������� �� ����� ��������
		currentx = nextx;
		currenty = nexty;
		currentz = nextz;

		f = function(currentx, currenty, currentz); // ������� �������� �������

		// ������������ ����� �������� ����������
		nextx = currentx + step * derivativex(currentx, currenty, currentz) / grad(currentx, currenty, currentz);
		nexty = currenty + step * derivativey(currentx, currenty, currentz) / grad(currentx, currenty, currentz);
		nextz = currentz + step * derivativez(currentx, currenty, currentz) / grad(currentx, currenty, currentz);

		fg = function(nextx, nexty, nextz); // ������������ ����� �������� �������

		if (fg <= f) step *= 0.5; // ������ ���
		count++;
		cout << nextx << setw(16) << nexty << setw(16) << nextz << setw(16) << fg << setw(16) << grad(nextx, nexty, nextz) << endl;

	} while (grad(nextx, nexty, nextz) > eps);

	cout << "\n����� max(" << nextx << ", " << nexty << ", " << nextz << ") " << "fmax = " << fg << endl;
	cout << "���������� �������� = " << count << endl;
}

double minfunction(double x, double y, double z) { // ������� ����
	double chisl = 0;
	double znam = 0;

	// ������� ����������� �������
	double s_x = derivativex(x, y, z) / grad(x, y, z);
	double s_y = derivativey(x, y, z) / grad(x, y, z);
	double s_z = derivativez(x, y, z) / grad(x, y, z);

	chisl = -(-10 * x * s_x - 8 * y * s_y - 4 * z * s_z + 2 * y * s_x + 2 * x * s_y - 2 * y * s_z - 2 * z * s_y + 8 * s_y);
	znam = -10 * s_x * s_x - 8 * s_y * s_y - 4 * s_z * s_z + 4 * s_x * s_y - 4 * s_y * s_z;
	return (chisl / znam);
}

void FastStep(double currentx, double currenty, double currentz) { // ����� ������������� ������
	double nextx = currentx;
	double nexty = currenty;
	double nextz = currentz;

	int count = 0; // ������� ������
	double eps = 0.001;
	double step = 0.1;

	double f = function(currentx, currenty, currentz);
	double fg = f;

	cout << "x1 " << setw(18) << "x2" << setw(18) << "x3" << setw(20) << "f(x1,x2,x3)" << setw(12) << "grad" << endl;
	cout << currentx << setw(16) << currenty << setw(16) << currentz << setw(16) << f << setw(16) << grad(currentx, currenty, currentz) << endl;

	do {
		// ������� �� ����� ��������
		currentx = nextx;
		currenty = nexty;
		currentz = nextz;

		// ������� ������ ����
		step = minfunction(currentx, currenty, currentz);

		// ������������ ����� �������� ����������
		nextx = currentx + step * derivativex(currentx, currenty, currentz) / grad(currentx, currenty, currentz);
		nexty = currenty + step * derivativey(currentx, currenty, currentz) / grad(currentx, currenty, currentz);
		nextz = currentz + step * derivativez(currentx, currenty, currentz) / grad(currentx, currenty, currentz);

		count++;

		// ������������ ����� �������� �������
		fg = function(nextx, nexty, nextz);

		cout << nextx << setw(16) << nexty << setw(16) << nextz << setw(16) << fg << setw(16) << grad(nextx, nexty, nextz) << endl;

	} while (grad(nextx, nexty, nextz) > eps);


	cout << "/n����� max(" << nextx << ", " << nexty << ", " << nextz << ")" << endl;
	cout << "���������� �������� = " << count << endl;
}

void Coordescent(double currentx, double currenty, double currentz) { // ����� ��������������� ������
	double nextx = currentx;
	double nexty = currenty;
	double nextz = currentz;

	int count = 0; // ������� ������
	double eps = 0.001;
	double step = 0.1; // ���

	double f = function(currentx, currenty, currentz);
	double fg = f;

	cout << "x1 " << setw(18) << "x2" << setw(18) << "x3" << setw(20) << "f(x1,x2,x3)" << setw(12) << "grad" << endl;
	cout << currentx << setw(16) << currenty << setw(16) << currentz << setw(16) << f << setw(16) << grad(currentx, currenty, currentz) << endl;


	do { // ������� �� ����� ��������
		currentx = nextx;
		currenty = nexty;
		currentz = nextz;

		// ������� ������� ��������� � ��� ����
		nextx = currentx + step * derivativex(currentx, currenty, currentz) / grad(currentx, currenty, currentz);
		step = minfunction(currentx, currenty, currentz);

		// ������� ������� ��������� � ��� ����
		nexty = currenty + step * derivativey(currentx, currenty, currentz) / grad(currentx, currenty, currentz);
		step = minfunction(currentx, currenty, currentz);

		// ������� �������� ��������� � ��� ����
		nextz = currentz + step * derivativez(currentx, currenty, currentz) / grad(currentx, currenty, currentz);
		step = minfunction(currentx, currenty, currentz);


		count++;

		// ������������ ����� �������� �������
		fg = function(nextx, nexty, nextz);

		cout << nextx << setw(16) << nexty << setw(16) << nextz << setw(16) << fg << setw(16) << grad(nextx, nexty, nextz) << endl;

	} while (grad(nextx, nexty, nextz) > eps);

	cout << "����� max(" << nextx << ", " << nexty << ", " << nextz << ")" << endl;
	cout << "���������� �������� = " << count << endl;
}

double lastminfunction(double x, double y, double z, double s_x, double s_y, double s_z) { // ������� ����
	double chisl = 0;
	double znam = 0;

	chisl = -(-10 * x * s_x - 8 * y * s_y - 4 * z * s_z + 2 * y * s_x + 2 * x * s_y - 2 * y * s_z - 2 * z * s_y + 8 * s_y);
	znam = -10 * s_x * s_x - 8 * s_y * s_y - 4 * s_z * s_z + 4 * s_x * s_y - 4 * s_y * s_z;
	return (chisl / znam);
}

void FletRivs(double currentx, double currenty, double currentz) { // ����� ��������-�����
	// ��������� ���������
	double nextx = currentx;
	double nexty = currenty;
	double nextz = currentz;

	double beforegrad = grad(currentx, currenty, currentz);

	double step = 0; // ���
	int count = 0; // ���������� ��������
	double eps = 0.001; // ��������
	double b = 0;

	// �������� ������� P
	double p_x = 0;
	double p_y = 0;
	double p_z = 0;

	double beforep_x = 0;
	double beforep_y = 0;
	double beforep_z = 0;

	double f = function(currentx, currenty, currentz);

	cout << "x1 " << setw(18) << "x2" << setw(18) << "x3" << setw(20) << "f(x1,x2,x3)" << setw(14) << "grad" << endl;
	cout << currentx << setw(23) << currenty << setw(16) << currentz << setw(16) << f << setw(16) << grad(currentx, currenty, currentz) << endl;

	while (grad(nextx, nexty, nextz) > eps) {
		// ������� �� ����� ��������
		currentx = nextx;
		currenty = nexty;
		currentz = nextz;

		b = pow(grad(nextx, nexty, nextz), 2) / pow(beforegrad, 2);

		// ���������� ������� ���������
		beforegrad = grad(currentx, currenty, currentz);

		// ������� ������������ p 
		p_x = derivativex(nextx, nexty, nextz) + b * beforep_x;
		p_y = derivativey(nextx, nexty, nextz) + b * beforep_y;
		p_z = derivativez(nextx, nexty, nextz) + b * beforep_z;

		// �������� �������� p
		beforep_x = p_x;
		beforep_y = p_y;
		beforep_z = p_z;

		// ��������� �������� ����
		step = lastminfunction(nextx, nexty, nextz, p_x, p_y, p_z);

		// ������������ ����� �������� ����������
		nextx = currentx + step * p_x;
		nexty = currenty + step * p_y;
		nextz = currentz + step * p_z;

		count++;

		f = function(nextx, nexty, nextz);

		cout << nextx << setw(16) << nexty << setw(16) << nextz << setw(16) << f << setw(16) << grad(nextx, nexty, nextz) << endl;
	}

	cout << "/n����� max(" << nextx << ", " << nexty << ", " << nextz << ")" << endl;
	cout << "���������� �������� = " << count << endl;
}