#pragma once
#include"Book.h"

class ForeignBook :public Book
{
private:
	string _typeBook = "ForeignBook";
	string _ISBN;

public:

	ForeignBook();
	ForeignBook(const ForeignBook& fbook);
	~ForeignBook();
	ForeignBook& operator=(const ForeignBook& vbook);

	void enterInformBook();
	void outInformBook();
	void setInformBook(string code, string title, string author, string publish, double price, string isbn);
	void setCodeBook(string code);
	void setAuthorBook(string author);
	void setTitleBook(string title);
	void setPublishBook(string publish);
	void setPriceBook(double price);
	void setISBN(string isbn);
	void setBorrow(int x);

	int checkBorrow();
	string getTypeBook();
	string getCodeBook();
	string getAuthorBook();
	string getTileBook();
	string getPublishBook();
	double getPriceBook();
	string getISBNBook();

};

