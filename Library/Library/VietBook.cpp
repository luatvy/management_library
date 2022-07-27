#include "VietBook.h"

VietBook::VietBook()
{
}

VietBook::VietBook(const VietBook& vbook) :Book(vbook)
{
}

VietBook::~VietBook()
{
	_typeBook = "";
}

VietBook& VietBook::operator=(const VietBook& vbook)
{
	if (this == &vbook)
		return *this;

	Book::operator=(vbook);

	return *this;
}

void VietBook::enterInformBook()
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
	cout << "Nhap gia sach: ";
	cin >> _priceBook;
}

void VietBook::outInformBook()
{
	cout << "Loai sach: " << _typeBook << endl;
	cout << "Ma sach: " << _codeBook << endl;
	cout << "Ten sach: " << _titleBook << endl;
	cout << "Tac gia: " << _authorBook << endl;
	cout << "Nha xuat ban: " << _publishBook << endl;
	cout << "Gia sach: " << _priceBook << endl;
}

void VietBook::setInformBook(string code, string title, string author, string publish, double price)
{
	_codeBook = code;
	_titleBook = title;
	_authorBook = author;
	_publishBook = publish;
	_priceBook = price;
}

void VietBook::setCodeBook(string code)
{
	_codeBook = code;
}

void VietBook::setAuthorBook(string author)
{
	_authorBook = author;
}

void VietBook::setTitleBook(string title)
{
	_titleBook = title;
}

void VietBook::setPublishBook(string publish)
{
	_publishBook = publish;
}

void VietBook::setPriceBook(double price)
{
	_priceBook = price;
}

void VietBook::setISBN(string isbn)
{
}

string VietBook::getTypeBook()
{
	return _typeBook;
}

string VietBook::getCodeBook()
{
	return _codeBook;
}

string VietBook::getAuthorBook()
{
	return _authorBook;
}

string VietBook::getTileBook()
{
	return _titleBook;
}

string VietBook::getPublishBook()
{
	return _publishBook;
}

double VietBook::getPriceBook()
{
	return _priceBook;
}

string VietBook::getISBNBook()
{
	return "";
}

void VietBook::setBorrow(int x)
{
	_checkBorrow = x;
}

int VietBook::checkBorrow()
{
	return _checkBorrow;
}
