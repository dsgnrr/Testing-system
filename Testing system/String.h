#pragma once
class String
{
	char* string;
	int length;
public:
	String();
	String(int l);
	String(const char* str);
	String(const String& obj);//copy constuctor
	~String();
	String& operator=(const String& obj);//operator= with copy
	void Input();
	void Print()const;
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrlen();
	void MyStrCat(String& b);
	void MyDelChr(char c);
	int MyStrCmp(String& b);
};

