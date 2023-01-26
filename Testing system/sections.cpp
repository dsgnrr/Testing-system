#include "sections.h"

//����������
sections::~sections()
{
	//�������� ���� ����� � ������ � ����
	DelAll();
}

//�������� ������ ��������
void sections::Del()
{
	//��������� ��������� ������
	section_list* temp = head;
	//������������ ������ ���������� �� ��������� �������
	head = head->next;
	//��������� ���-�� ��������
	elem_count--;
	//������� ������ ��������
	temp->data.DelAll();
	//�������� ������ ������(�������)
	delete temp;
}

//�������� ������������ ������� � ������
void sections::DelSpecific()
{
	//���� ���������� �������� �� ����� ���� �� ����� ������� ����� ������� ������
	if (elem_count != 0)
	{
		//�������� ������� ������ �������
		//�������������� ���-��� ���������+1 ��� ������� �����
		int pos = elem_count + 1;
		//���� ������� ������������� ������� ������ ��� ���-�� ��������, ����� ��������� ������� ������ ������� ������ ��� ���-�� ��������

		while (pos > elem_count)
		{
			//������� ������
			system("cls");
			//����� ��������
			Print();
			//���� � ���������� ������� ��� ��������
			cout << "������� ����� ������� ������� ������� �������: ";
			cin >> pos;
			cin.ignore();

			if (elem_count < pos)
				cout << "���� �������� ������ ��� ���������� ��������!\n";
		}
		//��������� �����
		section_list* temp1 = tail;
		//��������� ������
		section_list* temp2 = head;
		//��� ���� ��� �� ������ ������� ��������� � 1 � �� � 0 
		pos -= 1;
		//���� ������� ����� 1 �� ������� ������
		if (pos == 0)
		{
			temp2->data.DelAll();
			Del();
		}
		//���� ������� ����� ���-�� �������� ������� �����
		else if (pos == elem_count)
		{
			//��������� ������ �������� ������������ ����� �������
			for (int i = 0; i < elem_count - 1; i++)
				temp2 = temp2->next;
			//�������������� ����� �� ����������
			tail->next = temp2;
			tail = temp2;
			//��������� ���-�� �������� �� 1
			elem_count--;
			//�������� ������ �������� � �������
			temp1->data.DelAll();
			//�������� �������
			delete temp1;
		}
		else {
			//�������� ��������� �� ��� �������
			for (int i = 0; i < pos; i++)
			{
				temp2 = temp2->next;
			}
			//���������� ��� �� ��������� ���������
			section_list* del_elem = temp2;
			//�������������� ��������� ��������� �� ������
			temp2 = head;
			//��������� ������ ������� ������������ ����� ���������
			for (int i = 0; i < pos - 1; i++)
			{
				temp2 = temp2->next;
			}
			//��������� ������ ������� ������������ ����� ���������� 
			temp1 = head;
			for (int i = 0; i < pos + 1; i++)
				temp1 = temp1->next;
			//������������� ���������
			temp2->next = temp1;
			//��������� ���-�� �������� �� 1
			elem_count--;
			//������� ������ �������� � �������
			del_elem->data.DelAll();
			//�������� ������ �������
			delete del_elem;
		}
	}
	else
		cout << "������� �����������!" << endl;
}
//�������� ���� ��������
void sections::DelAll()
{
	while (head != NULL)
		Del();
}
//���������� ������ �������
void sections::Add(Quest_list quest_lis)
{
	//���-�� �������� ������������� �� 1
	elem_count++;
	//�������� ������ ����
	section_list* new_elem = new section_list;
	//������������� ������ ����
	new_elem->data = quest_lis;
	//�������� ��������� �� ��������� ������ ������ ��� ��� ���
	new_elem->next = NULL;
	//���� � ������ ���� ������� ��������� ����� � �����
	if (head != NULL)
	{
		tail->next = new_elem;
		tail = new_elem;
	}
	//���� � ������ ��� ��������, ��������� ����� ������ � � ����� � � ������
	else
		head = tail = new_elem;
}
//����������� �����
void sections::SelectSect()
{
	//���� �������� ��� ����� ������, ����� �������� ����
	if (elem_count != 0)
	{
		//�������� ������ �������
		int choice = elem_count+1;
		//�������� �� ������������ ����� ������ �������
		while (choice > elem_count)
		{
			cout << "�������� ������(���� ��������): ";
			cin >> choice;
			if (choice > elem_count)
				cout << "���� ������� ������ ��� ���������� ��������!" << endl;
			system("pause>>NULL");
		}
		//��� ���� ��� �� �������� � 1 � �� � 0
		choice -= 1;
		//������� ��������� ������ ��� ����������� �� ������
		section_list* temp = head;
		//������� �� ������ �������
		for (int i = 0; i < choice; i++)
			temp = temp->next;
		//�������� ����
		temp->data.DoTest();
	}
	else
		cout << "������� ����������� !" << endl;
}
//����� ������������ �������
void sections::ShowSpecSect()
{
	//���� ���-��  �������� ����� ���� ������� ������
	if (elem_count != 0)
	{
		//��� ����� ������ �������
		int answer = elem_count + 1;
		//�������� �� ������������ �����
		while (answer > elem_count)
		{
			//���� ������ �������
			cout << "�������� ������: ";
			cin >> answer;
			//���� �������� ������ ������ ���0�� ��������
			//�������� ������ ������
			if (answer > elem_count)
				cout << "���� �������� ������ ��� ���������� �������� !" << endl;
			system("pause>>NULL");
		}
		cin.ignore();
		//�������� ��������� ������ ��� ����������� �� ������
		section_list* temp = head;
		system("cls");
		//���������� ������� ������ �� ������ ������������
		for (int i = 0; i < answer-1; i++)
		{
			temp = temp->next;
		}
		//����� �������� �������
		cout<<"�������� �������: "<<temp->data.GetSectName()<<endl;
		//����� ������ ��������
		temp->data.Print();
	}
	else
	{
		cout << "������� ����������� !" << endl;
		system("pause>>NULL");
	}
}

//�������� ������ �������
void sections::CreateNewSect()
{
	//��������� ���-�� ������� ��� ����� � ����������
	int count_of_question;
	//��������� ��� ������� ��� ����� � ����������
	string name_sect;
	//��������� ������ ��� ����� � ����������
	Questions question;
	//��������� ������ �������� ��� ����� � ���������� � ���������� � ������
	Quest_list quest_lis;
	system("cls");
	cout << "������� �������� ������ �������: ";
	getline(cin, name_sect);
	quest_lis.SetSectName(name_sect);

	cout << "������� ���������� ��������: ";
	cin >> count_of_question;
	cin.ignore();
	
	//���� ��������
	for (int i = 0; i < count_of_question; i++)
	{
		cin >> question;
		quest_lis.Add(question);
	}
	//���������� ������ �������� � ������
	Add(quest_lis);
}
//����� ����������
void sections::PrintStat()
{
	if (elem_count != 0)
	{
		int answer = elem_count + 1;
		while (answer > elem_count)
		{
			cout << "�������� ������ �� �������� ������ ���������� ����������: ";
			cin >> answer;
			if (answer > elem_count)
				cout << "���� �������� ������ ��� ���-�� �������� !" << endl;
			system("pause>>NULL");
		}
		cin.ignore();
		answer -= 1;
		section_list* temp = head;
		for (int i = 0; i<answer; i++)
		{
			temp = temp->next;
		}
		//����� ������������ �������
		temp->data.PrintWrongAnswers();
		//����� ������
		cout << "���� ������ �� ������� " << temp->data.GetSectName() << ": " << temp->data.getMark() << endl;
	}
	else
	{
		cout << "No section!" << endl;
	}
}

//����� ���� ��������
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
		cout << "������� ����������!" << endl;
}



