#pragma once
#include "Quest_list.h"
#include<deque>
//������ ��������
struct section_list
{
	//������
	Quest_list data;
	//������� �� ��������� ������
	section_list* next;
};
//������ ��������
class sections
{
	//������ ������
	section_list* head;
	//����� ������
	section_list* tail;
	//���������� ��������
	int elem_count;
	//������
	int mark;
public:
	//����������� �� ���������
	sections() :head(NULL), tail(NULL),elem_count(0) ,mark(0){}
	//����������
	~sections();
	//�������� ������� � ������ �������
	void Del();
	//�������� ������������ �������
	void DelSpecific();
	//�������� ���� ��������
	void DelAll();
	//���������� ������ �������
	void Add(Quest_list quest_lis);
	//������� ������ � ������ ����
	void SelectSect();
	//�������� ����������� ������ � ������� ������������ � ��
	void ShowSpecSect();
	//������� ����� ������ � ��������� ������ ��������
	void CreateNewSect();
	//������ ���������� �� ����������� �����
	void PrintStat();
	//������ ������ ��������
	void Print();
};


