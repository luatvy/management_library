#include "Book.h"

Book::Book()
{
	_codeBook = "";
	_authorBook = "";
	_titleBook = "";
	_publishBook = "";
	_priceBook = 0;
	_checkBorrow = 0;
}

Book::~Book()
{
	_codeBook = "";
	_authorBook = "";
	_titleBook = "";
	_publishBook = "";
	_priceBook = 0;
	_checkBorrow = 0;
}

Book::Book(const Book& book)
{
	_codeBook = book._codeBook;
	_authorBook = book._authorBook;
	_titleBook = book._titleBook;
	_publishBook = book._publishBook;
	_priceBook = book._priceBook;
	_checkBorrow = book._checkBorrow;
}

Book& Book::operator=(const Book& book)
{
	if (this == &book)
		return *this;

	_codeBook = book._codeBook;
	_authorBook = book._authorBook;
	_titleBook = book._titleBook;
	_publishBook = book._publishBook;
	_priceBook = book._priceBook;
	_checkBorrow = book._checkBorrow;

	return *this;
}
