#include<cstdlib>
#include <iostream>
#include"My_library.h"
#include<Windows.h>
#include<conio.h>
using namespace std;

int main()
{
	//системы тистровани€
	sections sect;
	//логин
	string login;
	//пароль
	string pass;
	//дл€ выхода из меню
	bool cicle_break1 = false;
	//дл€ выхода из ветки меню
	bool cicle_break = false;
	//выбор пункта меню
	char choice = 0;
	//дл€ работы кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (cicle_break1!=true) 
	{
		system("cls");
		//меню
		cout << "¬ыберите учетную запись: \n1. Admin\n2. Respondent\nEsc - выход\n";
		choice = 0;
		choice = _getch();
		//главное меню
		switch (choice)
		{
			//админ. ветка меню
		case'1':
			system("cls");
			//ввод логина
			cout << "¬ведите логин: ";
			getline(cin, login);
			//ввод парол€
			cout << "¬ведите пароль: ";
			getline(cin, pass);
			//проверка на правильность ввода парол€ и логина если не верный логин или пароль в меню админа допуска нет
			system("pause>>NULL");
			if (login.find("admin")==0 && pass.find("123")==0)
			{
				cicle_break = false;
				//запуск ветки меню админа
				while (cicle_break!=true)
				{
					system("cls");
					//вывод пункто меню
					cout << "1. —оздать новый раздел\n2. ѕоказать существующие разделы\n3. ѕоказать конкректный раздел и вопросы в нЄм\n4. ”далить раздел\nEsc - выход в главное меню\n";

					choice = _getch();
					//выбор пункта
					switch (choice)
					{
						//создание нового раздела
					case'1':
						system("cls");

						sect.CreateNewSect();

						system("pause>>NULL");
						system("cls");

						break;
						//вывод всех разделов
					case'2':
						system("cls");
						sect.Print();
						system("pause>>NULL");
						system("cls");
						break;
						//показать конкректный раздел
					case'3':
						system("cls");

						sect.ShowSpecSect();
						system("pause>>NULL");
						system("cls");

						break;
						//удалить конкретный раздел
					case'4':
						system("cls");
						sect.DelSpecific();
						system("pause>>NULL");
						system("cls");

						break;
						//выход в главное меню
					case 27:
						cicle_break = true;
						break;

					default:
						cout << "“акой пункт меню отсутсвует!" << endl;
						system("pause>>NULL");
						
						break;

					}
				}
			}
			else
			{
				system("cls");
				cout << "Ќеверный логин или пароль !" << endl;
				system("pause>>NULL");
			}
			
			system("cls");
			break;
			//запуск ветки меню пользовател€
		case'2':
			system("cls");
			//ввод логина
			cout << "¬ведите логин: ";
			getline(cin, login);
			//ввод парол€
			cout << "¬ведите пароль: ";
			getline(cin, pass);

			system("pause>>NULL");
			//проверка на правильность ввода
			if (login.find("user") == 0 && pass.find("1234") == 0)
			{
				cicle_break = false;
				//запуск меню пользовател€
				while (cicle_break != true)
				{
					system("cls");
					//вывод пунктов
					cout << "1. Ќачать тестирование\n2. ѕоказать все существующие разделы\n3. ѕоказать конкерктный раздел\n4. ¬ывод статистики по конкректному разделу\nEsc - выход в главное меню\n";
					//выбор пункта
					choice = _getch();
					//выполнение пункта
					switch (choice)
					{
						//начало тестировани€
					case'1':
						system("cls");
						sect.Print();
						sect.SelectSect();

						system("pause>>NULL");
						system("cls");

						break;
					case'2':
						//показ всех существующих разделов
						system("cls");
						sect.Print();
						system("pause>>NULL");
						system("cls");
						break;
					case'3':
						//показ конкректного раздела
						system("cls");
						sect.Print();
						sect.ShowSpecSect();
						system("pause>>NULL");
						system("cls");

						break;
					case'4':
						//вывод статистики по разделам
						system("cls");
						sect.Print();
						sect.PrintStat();
						system("pause>>NULL");
						system("cls");

						break;
						//выход в главное меню
					case 27:
						cicle_break = true;
						break;

					default:
						cout << "Ќеверный выбор пункта меню!" << endl;
						system("pause>>NULL");

						break;

					}
				}
			}
			else
			{
				system("cls");
				cout << "Ќеверный логин или пароль" << endl;
				system("pause>>NULL");
			}
			system("cls");
			break;
			//выход из системы тестировани€
		case 27:
			system("cls");
			cicle_break1 = true;
			system("pause>>NULL");
			system("cls");
			break;
		default:
			cout << "Ќеверный выбор!" << endl;
			system("pause>>NULL");
			break;
		}
	}
}