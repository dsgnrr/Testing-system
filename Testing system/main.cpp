#include<cstdlib>
#include <iostream>
#include"My_library.h"
#include<Windows.h>
#include<conio.h>
using namespace std;

int main()
{
	//������� �����������
	sections sect;
	//�����
	string login;
	//������
	string pass;
	//��� ������ �� ����
	bool cicle_break1 = false;
	//��� ������ �� ����� ����
	bool cicle_break = false;
	//����� ������ ����
	char choice = 0;
	//��� ������ ���������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (cicle_break1!=true) 
	{
		system("cls");
		//����
		cout << "�������� ������� ������: \n1. Admin\n2. Respondent\nEsc - �����\n";
		choice = 0;
		choice = _getch();
		//������� ����
		switch (choice)
		{
			//�����. ����� ����
		case'1':
			system("cls");
			//���� ������
			cout << "������� �����: ";
			getline(cin, login);
			//���� ������
			cout << "������� ������: ";
			getline(cin, pass);
			//�������� �� ������������ ����� ������ � ������ ���� �� ������ ����� ��� ������ � ���� ������ ������� ���
			system("pause>>NULL");
			if (login.find("admin")==0 && pass.find("123")==0)
			{
				cicle_break = false;
				//������ ����� ���� ������
				while (cicle_break!=true)
				{
					system("cls");
					//����� ������ ����
					cout << "1. ������� ����� ������\n2. �������� ������������ �������\n3. �������� ����������� ������ � ������� � ��\n4. ������� ������\nEsc - ����� � ������� ����\n";

					choice = _getch();
					//����� ������
					switch (choice)
					{
						//�������� ������ �������
					case'1':
						system("cls");

						sect.CreateNewSect();

						system("pause>>NULL");
						system("cls");

						break;
						//����� ���� ��������
					case'2':
						system("cls");
						sect.Print();
						system("pause>>NULL");
						system("cls");
						break;
						//�������� ����������� ������
					case'3':
						system("cls");

						sect.ShowSpecSect();
						system("pause>>NULL");
						system("cls");

						break;
						//������� ���������� ������
					case'4':
						system("cls");
						sect.DelSpecific();
						system("pause>>NULL");
						system("cls");

						break;
						//����� � ������� ����
					case 27:
						cicle_break = true;
						break;

					default:
						cout << "����� ����� ���� ����������!" << endl;
						system("pause>>NULL");
						
						break;

					}
				}
			}
			else
			{
				system("cls");
				cout << "�������� ����� ��� ������ !" << endl;
				system("pause>>NULL");
			}
			
			system("cls");
			break;
			//������ ����� ���� ������������
		case'2':
			system("cls");
			//���� ������
			cout << "������� �����: ";
			getline(cin, login);
			//���� ������
			cout << "������� ������: ";
			getline(cin, pass);

			system("pause>>NULL");
			//�������� �� ������������ �����
			if (login.find("user") == 0 && pass.find("1234") == 0)
			{
				cicle_break = false;
				//������ ���� ������������
				while (cicle_break != true)
				{
					system("cls");
					//����� �������
					cout << "1. ������ ������������\n2. �������� ��� ������������ �������\n3. �������� ����������� ������\n4. ����� ���������� �� ������������ �������\nEsc - ����� � ������� ����\n";
					//����� ������
					choice = _getch();
					//���������� ������
					switch (choice)
					{
						//������ ������������
					case'1':
						system("cls");
						sect.Print();
						sect.SelectSect();

						system("pause>>NULL");
						system("cls");

						break;
					case'2':
						//����� ���� ������������ ��������
						system("cls");
						sect.Print();
						system("pause>>NULL");
						system("cls");
						break;
					case'3':
						//����� ������������ �������
						system("cls");
						sect.Print();
						sect.ShowSpecSect();
						system("pause>>NULL");
						system("cls");

						break;
					case'4':
						//����� ���������� �� ��������
						system("cls");
						sect.Print();
						sect.PrintStat();
						system("pause>>NULL");
						system("cls");

						break;
						//����� � ������� ����
					case 27:
						cicle_break = true;
						break;

					default:
						cout << "�������� ����� ������ ����!" << endl;
						system("pause>>NULL");

						break;

					}
				}
			}
			else
			{
				system("cls");
				cout << "�������� ����� ��� ������" << endl;
				system("pause>>NULL");
			}
			system("cls");
			break;
			//����� �� ������� ������������
		case 27:
			system("cls");
			cicle_break1 = true;
			system("pause>>NULL");
			system("cls");
			break;
		default:
			cout << "�������� �����!" << endl;
			system("pause>>NULL");
			break;
		}
	}
}