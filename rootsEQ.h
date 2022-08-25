#pragma once
#include <cmath>
#include<iostream>

using namespace std;

class Equation
{
protected:
	double a{}, b{}, x1{};

public:
	Equation() {}
	virtual void Solution() = 0;

};

//���� ���� �������
class EqLine : public Equation
{

public:
	EqLine() {}
	virtual void Solution() override;
};

//���� �������� �������
class EqQuad : public Equation
{
	double c, d, x2;

public:
	EqQuad() {}
	virtual void Solution() override;
};

void EqLine::Solution()
{
	cout << "˳��� ������� ����� ������: Ax + B = 0\n";
	cout << "� = ";
	cin >> a;
	cout << "B = ";
	cin >> b;
	cout << "������� ������ �� ������:\n";
	cout << a << "x+" << b << "=0\n";

	if (a == 0 && b == 0)
		cout << "г������ ���� ���� ����� �\n";
	else if (a == 0 && b != 0)
		cout << "г������ ���� �����\n";
	else
	{
		if (b)
			x1 = (-b) / a;
		else
			x1 = b / a;
	}

	if (x1)
		cout << "x = " << x1 << '\n';
}

void EqQuad::Solution()
{
	cout << "˳��� ������� ����� ������: A(x^2)+Bx+C=0\n";
	cout << "A, B, C ������ ���� ����������� �� ����������� ������� ";
	cout << "����� ���� � ��� ������ ���������� ����\n";
	cout << "� = ";
	cin >> a;
	cout << "� = ";
	cin >> b;
	cout << "C = ";
	cin >> c;
	
	if (a == 0)
	{
		cout << "г������ ��������� ����'�����\n";
	}
	else if (b == 0 && c == 0)
	{
		cout << "���� ������� �� ������\n";
		cout << a << "(x^2)=0\n";
		cout << "³������: x=0\n";
	}
	else if (c == 0 && b != 0)
	{
		cout << "���� ������� �� ������\n";
		cout << a << "(x^2)+" << b << "x=0\n";
		x1 = 0;
		x2 = - (b / a);
		cout << "³������: x1=" << x1 << " x2=" << x2 << '\n';
	}
	else if (b == 0 && a != 0 && c != 0)
	{
		if ((a < 0 && c > 0) || (c < 0 && a > 0))
		{
			cout << "���� ������� �� ������\n";
			cout << a << "(x^2)+" << c << "=0\n";
			x1 = sqrt((-1)*(c / a));
			x2 = (-1) * (sqrt((-1) * (c / a)));
			cout << "³������: x1=" << x1 << " x2=" << x2 << '\n';
		}
		else
			cout << "г������ �� �� ������\n";
	}
	else if (a != 0 && b != 0 && c != 0)
	{
		cout << "���� ������� �� ������\n";
		cout << a << "(x^2) + " << b << "x +" << c << "=0\n";
		d = pow(b, 2) - 4 * a * c;
		cout << "d=" << d <<'\n';
		if (d < 0)
		{
			cout << "г������ �� �� ������, ��� �� ����������� ����� 0\n";
		}
		else if (d == 0)
		{
			x1 = (-1) * (b / (2 * a));
			cout << "³������: x=" << x1 << '\n';
		}
		else if (d > 0)
		{
			x1 = (((-1) * b) + sqrt(d)) / (2 * a);
			x2 = (((-1) * b) - sqrt(d)) / (2 * a);
			cout << "³������: x1=" << x1 << " x2=" << x2 << '\n';
		}
	}
}