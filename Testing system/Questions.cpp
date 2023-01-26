#include "Questions.h"
//конструктор по умолчанию
Questions::Questions()
{
	//обнуляем все поля
	question = "";
	answers = nullptr;
	right_answer = 0;
	wrong_answer = 0;
	length = 0;
}
//конструктор копирования
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
//конструктор переноса
Questions::Questions(Questions&& quest)
{
	question = quest.question;
	right_answer = quest.right_answer;
	wrong_answer = quest.wrong_answer;
	length = quest.length;
	answers = quest.answers;
	quest.answers = nullptr;
}
//деструктор
Questions::~Questions()
{
	delete[]answers;
}

Questions& Questions::operator=(Questions& quest)
{
	//проверка на идентичность двух объектов семантика копирования
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
//перегрузка оператора присваивания с переносом
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
	//возрват вопроса
	return question;
}

string* Questions::GetAnswers()const
{
	//возврат вариантов ответа
	return answers;
}

char Questions::GetRightAnswer()const
{
	//возврат правильного ответва
	return right_answer;
}

int Questions::GetLength()const
{
	//возврат количества вариантов ответа
	return length;
}

char Questions::GetWrongAnswer() const
{
	//возврат неправильного ответа
	return wrong_answer;
}


void Questions::SetQuest(string qst)
{
	//изменение вопроса
	question = qst;
}

void Questions::SetAnswers(string* answer)
{
	//изменение вариантов ответа
	if (answers != nullptr)
		delete[]answers;
	answers = new string[length];
	for (int i = 0; i < length; i++)
		answers[i] = answer[i];
}

void Questions::SetRightAnswer(char rig_ans)
{
	//изменение правильного ответа
	right_answer = rig_ans;
}

void Questions::SetLength(int len)
{
	//изменение количества вар
	length = len;
}

void Questions::SetWrongAnswer(char wrong)
{
	//изменение не правильного ответа
	wrong_answer = wrong;
}

//перегрузка потоков ввода/вывода
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
	cout << "Введите вопрос: ";
	getline(in, temp);
	quest.SetQuest(temp);

	cout << "Введите количетсво вариантов ответа(одно число): ";
	int length;
	cin >> length;
	cin.ignore();
	quest.SetLength(length);

	cout << "Введите варианты ответа: \n";
	string* answers = new string[length];
	for (int i = 0; i < length; i++)
		getline(in, answers[i]);
	quest.SetAnswers(answers);

	char right;
	cout << "Введите правильный ответ(одну букву): ";
	cin >> right;
	cin.ignore();
	quest.SetRightAnswer(right);

	delete[]answers;
	system("cls");
	return in;
}
