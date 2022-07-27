#include "ForeignBook.h"

ForeignBook::ForeignBook()
{
	_ISBN = "";
}

ForeignBook::ForeignBook(const ForeignBook& fbook) :Book(fbook)
{
	_ISBN = fbook._ISBN;
}

ForeignBook::~ForeignBook()
{
	_ISBN = "";
	_typeBook = "";
}

ForeignBook& ForeignBook::operator=(const ForeignBook& fbook)
{
	if (this == &fbook)
		return *this;

	Book::operator=(fbook);
	_ISBN = fbook._ISBN;

	return *this;
}

void ForeignBook::enterInformBook()
{
	cin.ignore();
	cout << "Nhap ma sach: ";
	getline(cin, _codeBook);
	cout << "Nhap ten sach: ";
	getline(cin, _titleBook);
	cout << "Nhap ten tac gia: ";
	getline(cin, _authorBook);
	cout << "Nhap nha xuat ban: ";
	getline(cin, _publishBook);
	cout << "Nhap ISBN: ";
	getline(cin, _ISBN);
	cout << "Nhap gia sach: ";
	cin >> _priceBook;
}

void ForeignBook::outInformBook()
{
	cout << "Loai sach: " << _typeBook << endl;
	cout << "Ma sach: " << _codeBook << endl;
	cout << "Ten sach: " << _titleBook << endl;
	cout << "Tac gia: " << _authorBook << endl;
	cout << "Nha xuat ban: " << _publishBook << endl;
	cout << "Ma ISBN: " << _ISBN << endl;
	cout << "Gia sach: " << _priceBook << endl;
}

void ForeignBook::setInformBook(string code, string title, string author, string publish, double price, string isbn)
{
	_codeBook = code;
	_titleBook = title;
	_authorBook = author;
	_publishBook = publish;
	_priceBook = price;
	_ISBN = isbn;
}

void ForeignBook::setCodeBook(string code)
{
	_codeBook = code;
}

void ForeignBook::setAuthorBook(string author)
{
	_authorBook = author;
}

void ForeignBook::setTitleBook(string title)
{
	_titleBook = title;
}

void ForeignBook::setPublishBook(string publish)
{
	_publishBook = publish;
}

void ForeignBook::setPriceBook(double price)
{
	_priceBook = price;
}

void ForeignBook::setISBN(string isbn)
{
	_ISBN = isbn;
}

void ForeignBook::setBorrow(int x)
{
	_checkBorrow = x;
}

int ForeignBook::checkBorrow()
{
	return _checkBorrow;
}

string ForeignBook::getTypeBook()
{
	return _typeBook;
}

string ForeignBook::getCodeBook()
{
	return _codeBook;
}

string ForeignBook::getAuthorBook()
{
	return _authorBook;
}

string ForeignBook::getTileBook()
{
	return _titleBook;
}

string ForeignBook::getPublishBook()
{
	return _publishBook;
}

double ForeignBook::getPriceBook()
{
	return _priceBook;
}

string ForeignBook::getISBNBook()
{
	return _ISBN;
}


