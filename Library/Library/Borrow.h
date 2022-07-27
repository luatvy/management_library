#pragma once
#include"Date.h"
#include"User.h"
#include"Book.h"
#include<vector>

class Borrow
{
private:
	User* _user;
	vector<Book*> _book;
	vector<Date> _dayBorrow;

public:

	Borrow();
	Borrow(const Borrow& brow);
	~Borrow();
	Borrow& operator=(const Borrow& brow);

	void addBorrowBook(Book* book, Date date);
	void addReturnBook(Book* book, Date date);
	void addUserBorrow(User* user);

	void outInforBorrowUser();
	void outInforBorrow();

	int tinhTienPhatCaNhan(Date today);
	int tinhTienPhatKhiTra(Date today, int index);

	void setReturnBook(int x);
	int delBorrowBookAt(int x);
	int getNumBookBorrow();
	string getIDBorrow();
	string getCodeBookBorrow(int x);
	Date getDateBorrow(int x);
};

