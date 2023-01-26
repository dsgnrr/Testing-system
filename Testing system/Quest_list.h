#pragma once
#include"Questions.h"
struct question
{
	//вопрос
	Questions quest;
	//указатель на следующий элемент
	question* next;

};
class Quest_list
{
	//наименование раздела
	string name;
	//голова
	question* head;
	//хвост
	question* tail;
	//количество узлов 
	int num_of_node;
	//количество разделов
	int mark;
public:
	//конструктор по умолчанию
	Quest_list();
	//конструктор копирования
	Quest_list(Quest_list& list);
	//конструктор переноса
	Quest_list(Quest_list&& list);
	//деструктор
	~Quest_list();
	//перегрузка оператора присваивания с копированием 
	Quest_list& operator=(Quest_list& list);
	//перегрузка оператора присваивания с перенсом
	Quest_list& operator = (Quest_list&& list);
	//изменение названия раздела
	void SetSectName(string temp_name);
	//вывод не правильных ответов с вопросами
	void PrintWrongAnswers();
	//запуск теста
	void DoTest();
	//удаление вопроса
	void Del();
	//удаление всех вопросов
	void DelAll();
	//добавление вопроса
	void Add(Questions _quest);
	//вывод всех вопросов
	void Print();
	//получение оценки
	int getMark()const;
	//получение имени раздела
	string GetSectName();
};

