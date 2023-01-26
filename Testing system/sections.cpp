#include "sections.h"

//деструктор
sections::~sections()
{
	//удаление всех узлов и данных в куче
	DelAll();
}

//удаление одного элемента
void sections::Del()
{
	//добавляем временную голову
	section_list* temp = head;
	//оригинальную голову перемещаем на следующий элемент
	head = head->next;
	//списываем кол-во разделов
	elem_count--;
	//очистка списка вопросов
	temp->data.DelAll();
	//удаление старой головы(раздела)
	delete temp;
}

//удаление конкректного раздела в списке
void sections::DelSpecific()
{
	//если количество разделов не равно нулю то можно выбрать иначе выводит ошибку
	if (elem_count != 0)
	{
		//создание позиции нашего раздела
		//инициализируем кол-вом элементов+1 для условия цикла
		int pos = elem_count + 1;
		//если введёная пользователем позиция больше чем кол-во разделов, будет постоянно просить ввести позицию меньше чем кол-во разделов

		while (pos > elem_count)
		{
			//очистка экрана
			system("cls");
			//показ разделов
			Print();
			//ввод с клавиатуры позиции для удаления
			cout << "Введите номер раздела который желаете удалить: ";
			cin >> pos;
			cin.ignore();

			if (elem_count < pos)
				cout << "Ваше значение больше чем количество разделов!\n";
		}
		//временный хвост
		section_list* temp1 = tail;
		//временная голова
		section_list* temp2 = head;
		//для того что бы первая позиция вводилась с 1 а не с 0 
		pos -= 1;
		//если позиция равна 1 то удаляем голову
		if (pos == 0)
		{
			temp2->data.DelAll();
			Del();
		}
		//если позиция равна кол-ву разделов удаляем хвост
		else if (pos == elem_count)
		{
			//получение адреса элемента находящегося перед хвостом
			for (int i = 0; i < elem_count - 1; i++)
				temp2 = temp2->next;
			//перенаправляем хвост на предыдущий
			tail->next = temp2;
			tail = temp2;
			//списываем кол-во разделов на 1
			elem_count--;
			//удаление списка вопросов в разделе
			temp1->data.DelAll();
			//удаление раздела
			delete temp1;
		}
		else {
			//получаем указатель на наш элемент
			for (int i = 0; i < pos; i++)
			{
				temp2 = temp2->next;
			}
			//записываем его во временный указатель
			section_list* del_elem = temp2;
			//перенаправляем временный указатель на голову
			temp2 = head;
			//получение адреса раздела находящегося перед удаляемым
			for (int i = 0; i < pos - 1; i++)
			{
				temp2 = temp2->next;
			}
			//получение адреса раздела находящегося после удаляемого 
			temp1 = head;
			for (int i = 0; i < pos + 1; i++)
				temp1 = temp1->next;
			//пренаправляем указатели
			temp2->next = temp1;
			//списываем кол-во разделов на 1
			elem_count--;
			//удаляем список вопросов в разделе
			del_elem->data.DelAll();
			//удаление самого раздела
			delete del_elem;
		}
	}
	else
		cout << "Разделы отсутствуют!" << endl;
}
//удаление всех разделов
void sections::DelAll()
{
	while (head != NULL)
		Del();
}
//добавление нового раздела
void sections::Add(Quest_list quest_lis)
{
	//кол-во разделов увеличивается на 1
	elem_count++;
	//создание нового узла
	section_list* new_elem = new section_list;
	//инициализация нового узла
	new_elem->data = quest_lis;
	//обнулить указатель на следующий раздел потому что его нет
	new_elem->next = NULL;
	//если в голове есть разделы добавляем новый в хвост
	if (head != NULL)
	{
		tail->next = new_elem;
		tail = new_elem;
	}
	//если в голове нет разделов, добавляем новый раздел и в хвост и в голову
	else
		head = tail = new_elem;
}
//прохождение теста
void sections::SelectSect()
{
	//если разделов нет будет ошибка, иначе начнется тест
	if (elem_count != 0)
	{
		//создание выбора раздела
		int choice = elem_count+1;
		//проверка на правильность ввода номера раздела
		while (choice > elem_count)
		{
			cout << "Выберите раздел(одно значение): ";
			cin >> choice;
			if (choice > elem_count)
				cout << "Ваше знаение больше чем количество разделов!" << endl;
			system("pause>>NULL");
		}
		//для того что бы начинать с 1 а не с 0
		choice -= 1;
		//создаем временную голову для перемещения по списку
		section_list* temp = head;
		//доходим до нашего раздела
		for (int i = 0; i < choice; i++)
			temp = temp->next;
		//начинаем тест
		temp->data.DoTest();
	}
	else
		cout << "Разделы отсутствуют !" << endl;
}
//показ конкректного раздела
void sections::ShowSpecSect()
{
	//если кол-во  разделов равно нулю выведет ошибку
	if (elem_count != 0)
	{
		//для ввода номера раздела
		int answer = elem_count + 1;
		//проверка на правильность ввода
		while (answer > elem_count)
		{
			//ввод номера раздела
			cout << "Выберите раздел: ";
			cin >> answer;
			//если введённые данные больше кол0ва разделов
			//попросит ввести заново
			if (answer > elem_count)
				cout << "Ваше значение больше чем количество разделов !" << endl;
			system("pause>>NULL");
		}
		cin.ignore();
		//создание временной головы для перемещения по списку
		section_list* temp = head;
		system("cls");
		//нахождение раздела исходя из данных пользователя
		for (int i = 0; i < answer-1; i++)
		{
			temp = temp->next;
		}
		//вывод названия раздела
		cout<<"Название раздела: "<<temp->data.GetSectName()<<endl;
		//вывод списка вопросов
		temp->data.Print();
	}
	else
	{
		cout << "Разделы отсутствуют !" << endl;
		system("pause>>NULL");
	}
}

//создание нового раздела
void sections::CreateNewSect()
{
	//временное кол-во вопрсов для ввода с клавиатуры
	int count_of_question;
	//временное имя раздела для ввода с клавиатуры
	string name_sect;
	//временный вопрос для ввода с клавиатуры
	Questions question;
	//временный список вопросов для ввода с клавиатуры и добавления в список
	Quest_list quest_lis;
	system("cls");
	cout << "Введите название нового раздела: ";
	getline(cin, name_sect);
	quest_lis.SetSectName(name_sect);

	cout << "Введите количество вопросов: ";
	cin >> count_of_question;
	cin.ignore();
	
	//ввод вопросов
	for (int i = 0; i < count_of_question; i++)
	{
		cin >> question;
		quest_lis.Add(question);
	}
	//добавление списка вопросов в раздел
	Add(quest_lis);
}
//вывод статистики
void sections::PrintStat()
{
	if (elem_count != 0)
	{
		int answer = elem_count + 1;
		while (answer > elem_count)
		{
			cout << "выберите раздел по которому хотите посмотреть статистику: ";
			cin >> answer;
			if (answer > elem_count)
				cout << "Ваше значение больше чем кол-во разделов !" << endl;
			system("pause>>NULL");
		}
		cin.ignore();
		answer -= 1;
		section_list* temp = head;
		for (int i = 0; i<answer; i++)
		{
			temp = temp->next;
		}
		//вывод неправильных ответов
		temp->data.PrintWrongAnswers();
		//вывод оценки
		cout << "Ваша оценка по разделу " << temp->data.GetSectName() << ": " << temp->data.getMark() << endl;
	}
	else
	{
		cout << "No section!" << endl;
	}
}

//вывод всех разделов
void sections::Print()
{
	if (elem_count != 0)
	{
		section_list* temp = head;
		for (int i = 0; i < elem_count; i++)
		{
			cout << i + 1 << ". " << temp->data.GetSectName() << endl;
			temp = temp->next;
		}
		temp = head;
	}
	else
		cout << "Разделы отсутсвуют!" << endl;
}



