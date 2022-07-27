#pragma once
#include"Book.h"
#include"ForeignBook.h"
#include"VietBook.h"
#include"User.h"
#include<vector>
#include"Borrow.h"
#include"Date.h"
#include<fstream>
#include<conio.h>
using namespace std;

class Library
{
private:
	vector<Book*> _book;
	vector<User*> _user;
	vector<Borrow*> _borrow;
public:

	Library();
	Library(const Library& lib);
	~Library();
	Library& operator=(const Library& lib);

	void enterBookLib();
	void enterUserLib();

	void outListBookLib();
	void outUserInLib();
	void outBorrowInLib();

	void editBookLib();
	void findBookLib();
	void addBookLib();
	void addBookLib(Book* book);
	void delBookLib();

	void editUserLib();
	void findUserLib();
	void addUserLib();
	void delUserLib();

	void addBorrowInLib();
	void addReturnInLib();
	void listFinedPeople();

	void readFileBookLib(char* input);
	void readFileUserLib(char* input);
	void readFileBorrowLib(char* input);

	void writeFileBookLib(char* output);
	void writeFileUserLib(char* output);
	void writeFileBorrowLib(char* output);
};

