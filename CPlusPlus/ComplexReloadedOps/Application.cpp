#include "stdafx.h"
#include "Utils.h"
#include "Application.h"
#include "Complex.h"

void execute();
int chois();
void choise();

Application::Application()
{
}

Application::~Application()
{
}

void Application::run()
{
	execute();
	cout << "������������ ������ ��������\n";
	cout << "(2+4j)+(2-7j)= ";
	Complex A, B, C;
	A = Complex(2, 4);
	B = Complex(2, -7);
	C = A + B;
	cout << C << "\n\n������������ ������ ���������\n";
	cout << "(2+4j)-(2-7j)= ";
	C = A - B;
	cout << C << "\n\n������������ ������ ���������\n";
	cout << "(2+4j)*(2-7j)= ";
	C = A*B;
	cout << C;
	Complex R, T, Y;
	R = Complex(-2, 3);
	T = Complex(7, 1);
	cout << "\n\n������������ ������ �������\n";
	cout << "(-2+3j)/(7+1j)= ";
	Y = R / T;
	cout << Y << "\n\n������������ ������ ������������ �����\n";
	cout << "-2+3j= ";
	Y = R.conj();
	cout << Y << "\n\n������������ ������ ���������\n";
	cout << "(-2+3j)==(7+1j)= ";
	if (R == T)
		cout << "���������� ����� �����\n";
	else cout << "���������� ����� �� �����\n";
	Wrap(2);
	system("pause");
	system("cls");
	cout << "\n   -------------------------------------------------------\n";
	Wrap(12);
	choise();
}

//-----------------------------------------------------------
// 					���������� ���� ������
//-----------------------------------------------------------
void execute()
{
	tMark(" �������: \n");
	cout << " ����������� ����� Complex ��� ������ � ������������ �������.\n"
		<< " ����������� ����� �������������� ����� �������������� ����� (a, b), ���\n"
		<< "\ta � �������������� �����, b � ������ �����. \n"
		<< " ����������� ��������:\n"
		<< "\t- ��������\n"
		<< "\t- ���������\n"
		<< "\t- ���������\n"
		<< "\t- �������\n"
		<< "\t- ���������\n"
		<< "\t- ����������\n\n";
}
int chois(){
	int chois_1;
	tMark(" �������� ������������ �������:\n");
	cout << "\t1 - ��������\n"
		<< "\t2 - ���������\n "
		<< "\t3 - ���������\n"
		<< "\t4 - �������\n"
		<< "\t5 - ���������\n"
		<< "\t6 - ����������� �����\n"
		<< "\t0 - �����\n\n"
		<< "\n �������� ��������: \n";
	cin >> chois_1;
	while ((chois_1<0) || chois_1>6){
		cout << "     !!!�� ���������� ������!!!\n";
		cout << " ������ ������: ";
		cin >> chois_1;
	}
	return chois_1;
}
void choise(){
	switch (chois()){
	case 1: {
				Complex a, b;
				cout << "������ ����� :> ";
				cin >> a;
				cout << "������ ����� :> ";
				cin >> b;
				Complex c = a + b;
				cout << c;
				break;
	}
	case 2:{
			   Complex a, b;
			   cout << "������ ����� :> ";
			   cin >> a;
			   cout << "������ ����� :> ";
			   cin >> b;
			   Complex c = a - b;
			   cout << c;
			   break;
	}
	case 3:{
			   Complex a, b;
			   cout << "������ ����� :> ";
			   cin >> a;
			   cout << "������ ����� :> ";
			   cin >> b;
			   Complex c = a*b;
			   cout << c;
			   break;
	}
	case 4:{
			   Complex a, b;
			   cout << "������ ����� :> ";
			   cin >> a;
			   cout << "������ ����� :> ";
			   cin >> b;
			   Complex c = a / b;
			   cout << c;
			   break;
	}
	case 5:{
			   Complex a, b;
			   cout << "������ ����� :> ";
			   cin >> a;
			   cout << "������ ����� :> ";
			   cin >> b;
			   if (a == b)
				   cout << "��������� ����� �����\n";
			   else cout << "���������� ����� �� �����\n";
			   break;
	}
	case 6:{
			   Complex a;
			   cout << "����������� ����� :> ";
			   cin >> a;
			   cout << "\n����������� �����: " << a;
			   cout << "\n����������� ����������� �����: "
				    << a.conj();
			   Wrap(3);
			   break;
	}
	default:exit(0);
	}
	system("pause");
	system("cls");
	choise();

}
//-----------------------------------------------------------
//				����� ���������� ���� ������
//-----------------------------------------------------------