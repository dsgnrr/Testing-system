#pragma once
#include "Quest_list.h"
#include<deque>
//список разделов
struct section_list
{
	//раздел
	Quest_list data;
	//переход на следующий раздел
	section_list* next;
};
//список разделов
class sections
{
	//начало списка
	section_list* head;
	//конец списка
	section_list* tail;
	//количество разделов
	int elem_count;
	//оценка
	int mark;
public:
	//конструктор по умолчанию
	sections() :head(NULL), tail(NULL),elem_count(0) ,mark(0){}
	//деструктор
	~sections();
	//удаление первого в списке раздела
	void Del();
	//удаление конкректного раздела
	void DelSpecific();
	//удаление всех разделов
	void DelAll();
	//добавление нового раздела
	void Add(Quest_list quest_lis);
	//выбрать раздел и пройти тест
	void SelectSect();
	//показать конкректный раздел и вопросы содержащиеся в нём
	void ShowSpecSect();
	//создать новый раздел и заполнить список вопросов
	void CreateNewSect();
	//печать статистики по прохождению теста
	void PrintStat();
	//печать только разделов
	void Print();
};


