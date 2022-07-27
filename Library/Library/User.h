#pragma once
#include"Book.h"
#include<vector>
#include<iostream>
#include<string>
using namespace std;

class User
{
private:
	string _name, _IDlib;
	vector<Book*> _borrowBook;
	int _isBorrow;
public:

	User();
	User(const User& user);
	~User();
	User& operator=(const User& user);

	string getNameUser();
	string getIDUser();

	void setNameUser(string name);
	void setIDUser(string ID);

	void enterUser();
	void outUser();
	void setUser(string name, string ID);

	void setBorrowBook(Book* brbook);
	void printBorrowBook();
	void setIsBorrow(int x);
	int getIsBorrow();
};

