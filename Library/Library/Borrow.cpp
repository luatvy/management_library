#include "Borrow.h"

Borrow::Borrow()
{
	_book.resize(0);
	_user = NULL;
	_dayBorrow.resize(0);
}

Borrow::Borrow(const Borrow& brow)
{
	_book = brow._book;
	_user = brow._user;
	_dayBorrow = brow._dayBorrow;
}

Borrow::~Borrow()
{
	_book.clear();
	_user = NULL;
	_dayBorrow.clear();
}

Borrow& Borrow::operator=(const Borrow& brow)
{
	if (this == &brow)
		return *this;

	_book = brow._book;
	_user = brow._user;
	_dayBorrow = brow._dayBorrow;

	return *this;
}

void Borrow::addBorrowBook(Book* book, Date date)
{
	_book.push_back(book);
	_dayBorrow.push_back(date);
}

void Borrow::addReturnBook(Book* book, Date date)
{
	for (int i = 0; i < _book.size(); i++)
	{
		if (_book[i]->getCodeBook() == book->getCodeBook())
		{
			int fined = 0;
			fined = tinhTienPhatKhiTra(date, i);
			if (fined != 0)
			{
				cout << "### Tra sach tre han ###" << endl;
				cout << "### Ban bi phat: " << fined << endl;
			}
			_book.erase(_book.begin() + i);
			_dayBorrow.erase(_dayBorrow.begin() + i);
			break;
		}
	}
	cout << "TRA SACH THANH CONG" << endl;
}

void Borrow::addUserBorrow(User* user)
{
	_user = user;
}

void Borrow::outInforBorrowUser()
{
	_user->outUser();
}

void Borrow::outInforBorrow()
{
	_user->outUser();
	for (int i = 0; i < _book.size(); i++)
	{
		cout << "=== QUYEN " << i + 1 << " ===" << endl;
		_book[i]->outInformBook();
		cout << _dayBorrow[i] << endl;
	}
}



int Borrow::tinhTienPhatCaNhan(Date today)
{
	for (int i = 0; i < _dayBorrow.size(); i++)
	{
		if (_dayBorrow[i] > today)
		{
			cout << "Ban cap nhat ngay khong chinh xac (ngay cap nhap >= ngay muon)." << endl;
			return 0;
		}
	}

	int tong = 0;

	for (int i = 0; i < _dayBorrow.size(); i++)
	{
		int dem = 0;
		Date temp = _dayBorrow[i];

		while (temp != today)
		{
			dem++;
			temp++;
		}

		if (dem > 7 && _book[i]->getTypeBook() == "VietBook")
			tong += (dem - 7) * 10000;
		else
			if (dem > 7 && _book[i]->getTypeBook() == "ForeignBook")
				tong += (dem - 7) * 20000;
	}
	return tong;
}

int Borrow::tinhTienPhatKhiTra(Date today, int index)
{
	if (_dayBorrow[index] > today)
	{
		cout << "Ban cap nhat ngay khong chinh xac (ngay cap nhap >= ngay muon)." << endl;
		return 0;
	}

	Date temp = _dayBorrow[index];
	int dem = 0;
	while (today != temp)
	{
		dem++;
		temp++;
	}

	if (dem > 7 && _book[index]->getTypeBook() == "VietBook")
		return (dem - 7) * 10000;
	else
		if (dem > 7 && _book[index]->getTypeBook() == "ForeignBook")
			return (dem - 7) * 20000;
	return 0;
}

string Borrow::getIDBorrow()
{
	return _user->getIDUser();
}

int Borrow::getNumBookBorrow()
{
	return _book.size();
}

string Borrow::getCodeBookBorrow(int x)
{
	if (x >= _book.size())
		return "";
	return _book[x]->getCodeBook();
}

void Borrow::setReturnBook(int x)
{
	_book[x]->setBorrow(0);
}

int Borrow::delBorrowBookAt(int x)
{
	if (x == _book.size() - 1)
	{
		_book.pop_back();
		_dayBorrow.pop_back();
		return 1;
	}
	else
	{
		if (x >= 0 && x < _book.size())
		{
			for (int i = x; i < _book.size() - 1; i++)
			{
				_book[i] = _book[i + 1];
				_dayBorrow[i] = _dayBorrow[i + 1];

			}
			_book.pop_back();
			_dayBorrow.pop_back();
			return 1;
		}

	}
	return 0;
}

Date Borrow::getDateBorrow(int x)
{
	return _dayBorrow[x];
}

