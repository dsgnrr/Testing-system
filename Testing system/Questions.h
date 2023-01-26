#pragma once
#include <iostream>
#include<string>
#include"String.h"
using namespace std;
//вопросы по разделу
class Questions
{
	//вопросы
	string question;
	//варианты ответов
	string* answers = nullptr;
	//правильный ответ
	char right_answer;
	//нерпавильный ответ
	char wrong_answer;
	//кол-во вариантов ответов
	int length;
	//номер вопроса

public:
	//конструкто по умолчанию
	Questions();
	//конструктор копирования
	Questions(Questions& quest);
	//конструктор переноса
	Questions(Questions&& quest);
	//деструктор
	~Questions();
	//перегрузка оператора присваивания c копированием
	Questions& operator=(Questions& quest);
	////перегрузка оператора присваивания с переносом
	Questions& operator=(Questions&& quest);
	//методы аксессоры
	//метод получения вопроса
	string GetQuest() const;
	//метод получения вариантов ответов
	string* GetAnswers() const;
	//метод получения правильного ответа
	char GetRightAnswer() const;
	//метода получения кол-ва вариантов ответов
	int GetLength() const;
	//метод получения не правильного ответа
	char GetWrongAnswer()const;
	

	//метод изменения вопроса
	void SetQuest(string qst);
	//метод изменения вариантов ответов
	void SetAnswers(string*answer);
	//метод изменения правильного ответа
	void SetRightAnswer(char rig_ans);
	//метод изменения кол-ва вопросов
	void SetLength(int len);
	//метод изменения не правильного ответа
	void SetWrongAnswer(char wrong);

};

//перегрузка потоков ввода/вывода
ostream& operator<<(ostream& out, const Questions& quest);
istream& operator>>(istream& in, Questions& quest);

