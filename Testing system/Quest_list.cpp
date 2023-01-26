#include "Quest_list.h"
//����������� �� ���������
Quest_list::Quest_list()
{
	//��������� ����� ������
	head = tail = NULL;
	num_of_node = 0;
	//����������� ��� ��� �������
	name = "name";
	mark = 0;
}
//����������� �����������
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
//����������� ��������
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
//����������
Quest_list::~Quest_list()
{
		DelAll();
}
//��������� ��������� ������������ ������ ���� � �� ��� � � ������������ �����������
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
//��������� ��������� ������������ ������ ���� � �� ��� � � ������������ ��������
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
//��������� ����� �������
void Quest_list::SetSectName(string temp_name)
{
	name = temp_name;
}
//����� �������� �� ������� �� ��� ��� ���������� �����
void Quest_list::PrintWrongAnswers()
{
	system("cls");
	//�������� �� ������������ ��������� � ������
	if (num_of_node != 0)
	{
		//��������� ��������� ������
		question* temp = head;
		int count_wrong=0;
		//����� �� ���������� �������
		cout << "�� ���������� ������: " << endl;
		for (int i = 0; i < num_of_node; i++)
		{
			//����� �� ���������� �������
			if (temp->quest.GetWrongAnswer() != 0)
			{
				count_wrong++;
				//�����
				cout << temp->quest;
				//���������� �����
				cout << "���������� �����: " << temp->quest.GetRightAnswer() << endl;
				//����� ������������
				cout << "��� �����: " << temp->quest.GetWrongAnswer() << endl;
				//��������
				system("pause>>NULL");
			}
			//�������������� ��������� ������ �� ��������� �������
			temp = temp->next;
		}
		cout << endl;
		if (count_wrong == 0)
			cout << "�� ��� ������� �� ���� ���������� �����!" << endl;
	}
	//���� ������ ����
	else
		cout << "��� �������� !" << endl;
}
//����������� �����
void Quest_list::DoTest()
{
	//��������� ��������� ������
	question* temp = head;
	//����� ������������
	char user_answ=0;
	//����� ������� �������
	mark = 0;
	for (int i = 0; i < num_of_node; i++)
	{
		//������� ������
		system("cls");
		cout << "������: " << name << endl;
		//����� ������� � ��������� �������
		cout << i+1 << "." << temp->quest;
		//���� � ���������� �����
		cout << "������� ��� �����: ";
		cin >> user_answ;
		temp->quest.SetWrongAnswer(0);
		cin.ignore(); 
		//��������� ���� ����� �������� ������ �������������, ����� ����� ������������ � ���� ������� ������ Questions ������������ ����� 
		if (user_answ == temp->quest.GetRightAnswer())
			this->mark++;
		else
			temp->quest.SetWrongAnswer(user_answ);
		//��������� ������ ������������
		user_answ = 0;
		cout << "������� Enter ��� �����������...";
		system("pause>>NULL");
		//������� �� ��������� ������
		temp = temp->next;
	}
}
//�������� ������� �������
void Quest_list::Del()
{
	//���������� ��������� ������
	question* temp = head;
	//������� �� ��������� �������
	head = head->next;
	//���������� �������� ����������� �� 1
	num_of_node--;
	//�������� �������� ������� ������� ��������� ������
	delete temp;
}
//�������� ���� �������� 
void Quest_list::DelAll()
{
	while (head != NULL)
		Del();
}
//���������� ������� � �����
void Quest_list::Add(Questions _quest)
{
	//������ ����� ������
	question* new_quest = new question;
	//���������� ������ ����������
	new_quest->quest = _quest;
	//��������� �� ��������� ��������
	new_quest->next = NULL;
	//����������� ���-�� ��������
	num_of_node++;
	//���� ������ �� ����� NULL ����� ������� ������ �������
	if (head != NULL)
	{
		tail->next = new_quest;
		tail = new_quest;
	}
	//���� ������ � ���� ������ �� �������� ����������� ����� ������� � � ����� � � ������
	else
		head = tail = new_quest;
}
//����� ���� ��������
void Quest_list::Print()
{
	//���� ���-�� �������� �� ����� ���� �������������� ����� ����� ��������� �� ���������� ��������� � ������ ��������
	if (num_of_node != 0)
	{
		//�������� ��������� ������
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
		cout << "��� �������� !" << endl;
}
//��������� ������
int Quest_list::getMark() const
{
	return mark;
}
//��������� �������� �������
string Quest_list::GetSectName()
{
	return name;
}
