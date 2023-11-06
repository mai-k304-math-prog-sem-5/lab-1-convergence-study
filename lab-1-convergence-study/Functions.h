#ifndef VARHANDLER_H
#define VARHANDLER_H

// ��������������� �������
double function(double x, double y, double z); // �������� �������
double derivativex(double x, double y, double z); // ������� ������� ����������� �� x
double derivativey(double x, double y, double z); // ������� ������� ����������� �� y
double derivativez(double x, double y, double z); // ������� ������� ����������� �� z
double grad(double x, double y, double z); // ������� ��������� �������

// ������� ��������� �������
void GradStepSplit(double currentx, double currenty, double currentz); // ����� ������������ ������ � ���������� ����

double minfunction(double x, double y, double z); // ������� ����
void FastStep(double currentx, double currenty, double currentz); // ����� ������������� ������

void Coordescent(double currentx, double currenty, double currentz); // ����� ��������������� ������

double lastminfunction(double x, double y, double z, double s_x, double s_y, double s_z); // ������� ����
void FletRivs(double currentx, double currenty, double currentz); // ����� ��������-�����

#endif