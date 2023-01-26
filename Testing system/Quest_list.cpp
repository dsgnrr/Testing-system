#include "Quest_list.h"
//конструктор по умолчанию
Quest_list::Quest_list()
{
	//обнуление всего списка
	head = tail = NULL;
	num_of_node = 0;
	//стандартное имя для раздела
	name = "name";
	mark = 0;
}
//конструктор копирования
Quest_list::Quest_list(Quest_list& list)
{
	head = list.head;
	list.head = NULL;
	tail = list.tail;
	list.tail = NULL;
	num_of_node = list.num_of_node;
	name = list.name;
	mark = list.mark;
}
//конструктор переноса
Quest_list::Quest_list(Quest_list&& list)
{
	head = list.head;
	list.head = NULL;
	tail = list.tail;
	list.tail = NULL;
	num_of_node = list.num_of_node;
	name = list.name;
	mark = list.mark;
}
//деструктор
Quest_list::~Quest_list()
{
		DelAll();
}
//прегрузка оператора присваивания логика така я же как и в конструкторе копирования
Quest_list& Quest_list::operator=(Quest_list& list)
{
	if (this != &list)
	{
		head = list.head;
		list.head = NULL;
		tail = list.tail;
		list.tail = NULL;
		num_of_node = list.num_of_node;
		name = list.name;
		mark = list.mark;
		return *this;
	}
	return*this;
}
//прегрузка оператора присваивания логика така я же как и в конструкторе переноса
Quest_list& Quest_list::operator=(Quest_list&& list)
{
	if (this != &list)
	{
		head = list.head;
		list.head = NULL;
		tail = list.tail;
		list.tail = NULL;
		num_of_node = list.num_of_node;
		name = list.name;
		mark = list.mark;
		return *this;
	}
	return *this;
}
//изменение имени раздела
void Quest_list::SetSectName(string temp_name)
{
	name = temp_name;
}
//вывод вопросов на которые не был дан правильный ответ
void Quest_list::PrintWrongAnswers()
{
	system("cls");
	//проверка на содержимость элементов в списке
	if (num_of_node != 0)
	{
		//добавляем временную голову
		question* temp = head;
		int count_wrong=0;
		//вывод не правильных ответов
		cout << "Не правильные ответы: " << endl;
		for (int i = 0; i < num_of_node; i++)
		{
			//поиск не правильных ответов
			if (temp->quest.GetWrongAnswer() != 0)
			{
				count_wrong++;
				//вывод
				cout << temp->quest;
				//правильный ответ
				cout << "Правильный ответ: " << temp->quest.GetRightAnswer() << endl;
				//ответ пользователя
				cout << "Ваш ответ: " << temp->quest.GetWrongAnswer() << endl;
				//ожидание
				system("pause>>NULL");
			}
			//перенарпавляем временную голову на следующий элемент
			temp = temp->next;
		}
		cout << endl;
		if (count_wrong == 0)
			cout << "На все вопросы вы дали правильный ответ!" << endl;
	}
	//если список пуст
	else
		cout << "Нет вопросов !" << endl;
}
//прохождение теста
void Quest_list::DoTest()
{
	//добавляем временную голову
	question* temp = head;
	//ответ пользователя
	char user_answ=0;
	//вывод каждого вопроса
	mark = 0;
	for (int i = 0; i < num_of_node; i++)
	{
		//очистка экрана
		system("cls");
		cout << "Раздел: " << name << endl;
		//вывод вопроса и вариантов ответов
		cout << i+1 << "." << temp->quest;
		//ввод с клавиатуры ответ
		cout << "Введите ваш ответ: ";
		cin >> user_answ;
		temp->quest.SetWrongAnswer(0);
		cin.ignore(); 
		//сравнение если ответ подходит оценка увеличевается, иначе ответ записывается в поле объекта класса Questions неправильный ответ 
		if (user_answ == temp->quest.GetRightAnswer())
			this->mark++;
		else
			temp->quest.SetWrongAnswer(user_answ);
		//обнуление ответа пользователя
		user_answ = 0;
		cout << "Нажмите Enter для продолжения...";
		system("pause>>NULL");
		//переход на следующий вопрос
		temp = temp->next;
	}
}
//удаление первого вопроса
void Quest_list::Del()
{
	//добавление временной головы
	question* temp = head;
	//переход на следующий элемент
	head = head->next;
	//количество вопросов уменьшается на 1
	num_of_node--;
	//удаление значения которое хранила временная голова
	delete temp;
}
//удаление всех вопросов 
void Quest_list::DelAll()
{
	while (head != NULL)
		Del();
}
//добавление вопроса в конец
void Quest_list::Add(Questions _quest)
{
	//создаём новый вопрос
	question* new_quest = new question;
	//полученные данные записываем
	new_quest->quest = _quest;
	//указатель на следующий обнуляем
	new_quest->next = NULL;
	//увеличиваем кол-во вопросов
	num_of_node++;
	//если голова не равна NULL новый элемент делаем хвостом
	if (head != NULL)
	{
		tail->next = new_quest;
		tail = new_quest;
	}
	//если голова в себе ничего не содержит записыываем новый элемент и в хвост и в голову
	else
		head = tail = new_quest;
}
//вывод всех вопросов
void Quest_list::Print()
{
	//если кол-во вопросов не равно нулю осуществляется вывод иначе сообщение об отсутствии элементов в списке вопросов
	if (num_of_node != 0)
	{
		//создание временной головы
		question* temp = head;
		for (int i = 0; i < num_of_node; i++)
		{
			cout << "\n-----------------------------------------\n";
			cout <<i+1<< "." << temp->quest;
			temp = temp->next;
			cout << "-----------------------------------------\n";
		}
	}
	else
		cout << "Нет вопросов !" << endl;
}
//получение оценки
int Quest_list::getMark() const
{
	return mark;
}
//получение названия раздела
string Quest_list::GetSectName()
{
	return name;
}
