#include "User.h"

User::User()
{
	_name = "";
	_IDlib = "";
	_borrowBook.clear();
	_isBorrow = 0;
}

User::User(const User& user)
{
	_name = user._name;
	_IDlib = user._IDlib;
	_borrowBook = user._borrowBook;
	_isBorrow = user._isBorrow;
}

User::~User()
{
	_name = "";
	_IDlib = "";
	_borrowBook.clear();
	_isBorrow = 0;
}

User& User::operator=(const User& user)
{
	if (this == &user)
		return *this;

	_borrowBook.clear();
	_name = user._name;
	_IDlib = user._IDlib;
	_borrowBook = user._borrowBook;
	_isBorrow = user._isBorrow;

	return *this;
}

string User::getNameUser()
{
	return _name;
}

string User::getIDUser()
{
	return _IDlib;
}

void User::setNameUser(string name)
{
	_name = name;
}

void User::setIDUser(string ID)
{
	_IDlib = ID;
}

void User::enterUser()
{
	cout << "Nhap ten user: ";
	getline(cin, _name);
	cout << "Nhap ID library: ";
	getline(cin, _IDlib);
}

void User::outUser()
{
	cout << "Ho va ten: " << _name << endl;
	cout << "ID library: " << _IDlib << endl;
}

void User::setUser(string name, string ID)
{
	_name = name;
	_IDlib = ID;
}

void User::setBorrowBook(Book* brbook)
{
	_borrowBook.push_back(brbook);
}

void User::printBorrowBook()
{
	for (int i = 0; i < _borrowBook.size(); i++)
	{
		_borrowBook[i]->outInformBook();
		cout << endl;
	}
}

void User::setIsBorrow(int x)
{
	_isBorrow = x;
}

int User::getIsBorrow()
{
	return _isBorrow;
}
