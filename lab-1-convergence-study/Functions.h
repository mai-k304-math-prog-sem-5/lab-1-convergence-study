#ifndef VARHANDLER_H
#define VARHANDLER_H

// Вспомогательные функции
double function(double x, double y, double z); // Исходная функция
double derivativex(double x, double y, double z); // Подсчет частной производной по x
double derivativey(double x, double y, double z); // Подсчет частной производной по y
double derivativez(double x, double y, double z); // Подсчет частной производной по z
double grad(double x, double y, double z); // Подсчет градиента функции

// Функции численных методов
void GradStepSplit(double currentx, double currenty, double currentz); // Метод градиентного спуска с дроблением шага

double minfunction(double x, double y, double z); // Подсчет шага
void FastStep(double currentx, double currenty, double currentz); // Метод наискорейшего спуска

void Coordescent(double currentx, double currenty, double currentz); // Метод покоординатного спуска

double lastminfunction(double x, double y, double z, double s_x, double s_y, double s_z); // Подсчет шага
void FletRivs(double currentx, double currenty, double currentz); // Метод Флетчера-Ривса

#endif