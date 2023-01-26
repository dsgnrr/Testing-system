#include "String.h"
#include <iostream>
#include <time.h>
using namespace std;
String::String()
{
	srand(unsigned(time(NULL)));
	length = 80;
	string = new char[length];
	for (int i = 0; i < length; i++)
	{
		string[i] = rand() % 255;
	}
}

String::String(int l)
{
	length = l;
	string = new char[length];
	srand(unsigned(time(NULL)));
	for (int i = 0; i < length; i++)
	{
		string[i] = rand() % 255;
	}
}

String::String(const char* str)
{
	int len = strlen(str);
	string = new char[len + 1];
	strcpy_s(string, len + 1, str);
}

String::String(const String& obj)
{
	length = strlen(obj.string);
	if (string != nullptr)
		delete[]string;
	string = new char[length + 1];
	strcpy_s(string, length + 1, obj.string);
	length = obj.length;
}

String::~String()
{
	delete[]string;
}

String& String::operator=(const String& obj)
{
	length = strlen(obj.string);
	if (string != nullptr)
		delete[]string;
	string = new char[length + 1];
	strcpy_s(string, length + 1, obj.string);
	length = obj.length;
	return *this;
}

void String::Input()
{
	cout << "Length ?";
	cin >> length;
	cin.ignore();
	if (string != nullptr)
	{
		delete[]string;
	}
	string = new char[length];
	cin.getline(string, length);
}

void String::Print() const
{
	cout << string;
}



bool String::MyStrStr(const char* str)
{
	bool check = 0;
	if (strstr(string, str))
		check = true;
	else
		check = false;
	
	return check;
}

int String::MyChr(char c)
{
	int pos = 0;
	length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		if (string[i] == c)
		{
			pos = i;
			break;
		}
		else
			return -1;
	}
	return pos;
}

int String::MyStrlen()
{
	length = strlen(string);
	return length;
}

void String::MyStrCat(String& b)
{
	length = strlen(string);
	b.length = strlen(b.string);
	char* buff = new char[length + b.length + 2];
	strcpy_s(buff, length + 1, string);
	buff[length] = ' ';
	buff[length + 1] = '\0';
	strcat_s(buff, (length + b.length + 2), b.string);
	delete[]string;
	length = strlen(buff);
	string = new char[length + 1];
	strcpy_s(string, length + 1, buff);
	delete[]buff;
}

void String::MyDelChr(char c)
{
	int pos = 0;
	length = strlen(string);
	for (int i = 0; i < length; i++)
	{
		if (string[i] == c)
		{
			pos = i;
			string[pos] = ' ';
		}
	}
}

int String::MyStrCmp(String& b)
{
	int check = 0;
	length = strlen(string);
	b.length = strlen(b.string);
	if (length > b.length)
		check = 1;
	else if (length < b.length)
		check = -1;
	else
		check = 0;
	return check;
}
