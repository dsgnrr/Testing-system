#pragma once
#include <iostream>
#include<string>
#include"String.h"
using namespace std;
//������� �� �������
class Questions
{
	//�������
	string question;
	//�������� �������
	string* answers = nullptr;
	//���������� �����
	char right_answer;
	//������������ �����
	char wrong_answer;
	//���-�� ��������� �������
	int length;
	//����� �������

public:
	//���������� �� ���������
	Questions();
	//����������� �����������
	Questions(Questions& quest);
	//����������� ��������
	Questions(Questions&& quest);
	//����������
	~Questions();
	//���������� ��������� ������������ c ������������
	Questions& operator=(Questions& quest);
	////���������� ��������� ������������ � ���������
	Questions& operator=(Questions&& quest);
	//������ ���������
	//����� ��������� �������
	string GetQuest() const;
	//����� ��������� ��������� �������
	string* GetAnswers() const;
	//����� ��������� ����������� ������
	char GetRightAnswer() const;
	//������ ��������� ���-�� ��������� �������
	int GetLength() const;
	//����� ��������� �� ����������� ������
	char GetWrongAnswer()const;
	

	//����� ��������� �������
	void SetQuest(string qst);
	//����� ��������� ��������� �������
	void SetAnswers(string*answer);
	//����� ��������� ����������� ������
	void SetRightAnswer(char rig_ans);
	//����� ��������� ���-�� ��������
	void SetLength(int len);
	//����� ��������� �� ����������� ������
	void SetWrongAnswer(char wrong);

};

//���������� ������� �����/������
ostream& operator<<(ostream& out, const Questions& quest);
istream& operator>>(istream& in, Questions& quest);

