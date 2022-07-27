#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book
{
protected:
	string  _codeBook, _authorBook, _titleBook, _publishBook;
	double _priceBook;
	int _checkBorrow;
public:
	Book();
	~Book();
	Book(const Book& book);
	Book& operator=(const Book& book);

	virtual void outInformBook() = 0;

	virtual void setCodeBook(string code) = 0;
	virtual void setAuthorBook(string author) = 0;
	virtual void setTitleBook(string title) = 0;
	virtual void setPublishBook(string publish) = 0;
	virtual void setPriceBook(double price) = 0;
	virtual void setISBN(string isbn) = 0;

	virtual string getTypeBook() = 0;
	virtual string getCodeBook() = 0;
	virtual string getAuthorBook() = 0;
	virtual string getTileBook() = 0;
	virtual string getPublishBook() = 0;
	virtual double getPriceBook() = 0;
	virtual string getISBNBook() = 0;
	virtual int checkBorrow() = 0;
	virtual void setBorrow(int x) = 0;

};

