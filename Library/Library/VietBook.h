#pragma once
#include"Book.h"

class VietBook :public Book
{
private:
	string _typeBook = "VietBook";
public:

	VietBook();
	VietBook(const VietBook& vbook);
	~VietBook();
	VietBook& operator=(const VietBook& vbook);

	void enterInformBook();
	void outInformBook();
	void setInformBook(string code, string title, string author, string publish, double price);

	void setCodeBook(string code);
	void setAuthorBook(string author);
	void setTitleBook(string title);
	void setPublishBook(string publish);
	void setPriceBook(double price);
	void setISBN(string isbn);

	string getTypeBook();
	string getCodeBook();
	string getAuthorBook();
	string getTileBook();
	string getPublishBook();
	double getPriceBook();
	string getISBNBook();
	void setBorrow(int x);
	int checkBorrow();

	/*void addBook();
	void delBook();
	void findBook();
	void editBook();*/
};

