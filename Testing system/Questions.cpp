#include "Questions.h"
//����������� �� ���������
Questions::Questions()
{
	//�������� ��� ����
	question = "";
	answers = nullptr;
	right_answer = 0;
	wrong_answer = 0;
	length = 0;
}
//����������� �����������
Questions::Questions(Questions& quest)
{
	question = quest.question;
	right_answer = quest.right_answer;
	wrong_answer = quest.wrong_answer;
	length = quest.length;
	answers = new string[length];
	for (int i = 0; i < length; i++)
		answers[i] = quest.answers[i];
}
//����������� ��������
Questions::Questions(Questions&& quest)
{
	question = quest.question;
	right_answer = quest.right_answer;
	wrong_answer = quest.wrong_answer;
	length = quest.length;
	answers = quest.answers;
	quest.answers = nullptr;
}
//����������
Questions::~Questions()
{
	delete[]answers;
}

Questions& Questions::operator=(Questions& quest)
{
	//�������� �� ������������ ���� �������� ��������� �����������
	if (this != &quest)
	{
		if (answers != nullptr)
			delete[]answers;
		question = quest.question;
		wrong_answer = quest.wrong_answer;
		right_answer = quest.right_answer;
		length = quest.length;
		answers = new string[length];
		for (int i = 0; i < length; i++)
			answers[i] = quest.answers[i];
		return *this;
	}
	return*this;
}
//���������� ��������� ������������ � ���������
Questions& Questions::operator=(Questions&& quest)
{
	question = quest.question;
	length = quest.length;
	right_answer = quest.right_answer;
	wrong_answer = quest.wrong_answer;
	answers = quest.answers;
	quest.answers = nullptr;
	return *this;
}

string Questions::GetQuest()const
{
	//������� �������
	return question;
}

string* Questions::GetAnswers()const
{
	//������� ��������� ������
	return answers;
}

char Questions::GetRightAnswer()const
{
	//������� ����������� �������
	return right_answer;
}

int Questions::GetLength()const
{
	//������� ���������� ��������� ������
	return length;
}

char Questions::GetWrongAnswer() const
{
	//������� ������������� ������
	return wrong_answer;
}


void Questions::SetQuest(string qst)
{
	//��������� �������
	question = qst;
}

void Questions::SetAnswers(string* answer)
{
	//��������� ��������� ������
	if (answers != nullptr)
		delete[]answers;
	answers = new string[length];
	for (int i = 0; i < length; i++)
		answers[i] = answer[i];
}

void Questions::SetRightAnswer(char rig_ans)
{
	//��������� ����������� ������
	right_answer = rig_ans;
}

void Questions::SetLength(int len)
{
	//��������� ���������� ���
	length = len;
}

void Questions::SetWrongAnswer(char wrong)
{
	//��������� �� ����������� ������
	wrong_answer = wrong;
}

//���������� ������� �����/������
ostream& operator<<(ostream& out, const Questions& quest)
{
	char var_letter = 65;
	out << quest.GetQuest() << endl;
	for (int i = 0; i < quest.GetLength(); i++)
	{
		cout << var_letter << ". " << quest.GetAnswers()[i] << "\n";
		var_letter++;
	}
	cout << endl;
	return out;
}

istream& operator>>(istream& in, Questions& quest)
{
	string temp;
	cout << "������� ������: ";
	getline(in, temp);
	quest.SetQuest(temp);

	cout << "������� ���������� ��������� ������(���� �����): ";
	int length;
	cin >> length;
	cin.ignore();
	quest.SetLength(length);

	cout << "������� �������� ������: \n";
	string* answers = new string[length];
	for (int i = 0; i < length; i++)
		getline(in, answers[i]);
	quest.SetAnswers(answers);

	char right;
	cout << "������� ���������� �����(���� �����): ";
	cin >> right;
	cin.ignore();
	quest.SetRightAnswer(right);

	delete[]answers;
	system("cls");
	return in;
}
