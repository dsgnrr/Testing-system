#pragma once
#include"Questions.h"
struct question
{
	//������
	Questions quest;
	//��������� �� ��������� �������
	question* next;

};
class Quest_list
{
	//������������ �������
	string name;
	//������
	question* head;
	//�����
	question* tail;
	//���������� ����� 
	int num_of_node;
	//���������� ��������
	int mark;
public:
	//����������� �� ���������
	Quest_list();
	//����������� �����������
	Quest_list(Quest_list& list);
	//����������� ��������
	Quest_list(Quest_list&& list);
	//����������
	~Quest_list();
	//���������� ��������� ������������ � ������������ 
	Quest_list& operator=(Quest_list& list);
	//���������� ��������� ������������ � ��������
	Quest_list& operator = (Quest_list&& list);
	//��������� �������� �������
	void SetSectName(string temp_name);
	//����� �� ���������� ������� � ���������
	void PrintWrongAnswers();
	//������ �����
	void DoTest();
	//�������� �������
	void Del();
	//�������� ���� ��������
	void DelAll();
	//���������� �������
	void Add(Questions _quest);
	//����� ���� ��������
	void Print();
	//��������� ������
	int getMark()const;
	//��������� ����� �������
	string GetSectName();
};

