#include "Library.h"

int compareToLowerStr(string x, string y);

Library::Library()
{
	_book.clear();
	_user.clear();
}

Library::Library(const Library& lib)
{
	_book = lib._book;
	_user = lib._user;
}

Library::~Library()
{
	_book.clear();
	_user.clear();
}

Library& Library::operator=(const Library& lib)
{
	if (this == &lib)
		return *this;

	_book.clear();
	_user.clear();

	_book = lib._book;
	_user = lib._user;

	return *this;
}

void Library::enterBookLib()
{
	int n;
	cout << "SO LUONG SACH CAN NHAP: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
	enterAgain:
		int loai;
		cout << "NHAP LOAI SACH (0:VietBook, 1:ForeignBook): ==> ";
		cin >> loai;

		if (loai != 1 && loai != 0)
		{
			cout << "### BAN NHAP SAI LOAI SACH ###" << endl;
			cout << "### VUI LONG NHAP LAI ###" << endl;
			goto enterAgain;
		}

		if (loai == 0)
		{
			VietBook* viet = new VietBook;
			string title, code, author, publish;
		againn1:;
			double price;
			cin.ignore();
			cout << "Nhap ma sach: ";
			getline(cin, code);
			for (int i = 0; i < _book.size(); i++)
			{
				if (code == _book[i]->getCodeBook())
				{
					cout << "### MA SACH DA TON TAI ###" << endl;
					cout << "### VUI LONG NHAP LAI MA SACH KHAC ###" << endl;
					goto enterAgain;
					goto againn1;
				}
			}
			cout << "Nhap ten sach: ";
			getline(cin, title);
			cout << "Nhap ten tac gia: ";
			getline(cin, author);
			cout << "Nhap nha xuat ban: ";
			getline(cin, publish);
			cout << "Nhap gia sach: ";
			cin >> price;
			viet->setInformBook(code, title, author, publish, price);
			_book.push_back(viet);
		}

		if (loai == 1)
		{

			ForeignBook* foreign = new ForeignBook;
			string title, code, author, publish, isbn;
		againn2:;
			double price;
			cin.ignore();
			cout << "Nhap ma sach: ";
			getline(cin, code);
			for (int i = 0; i < _book.size(); i++)
			{
				if (code == _book[i]->getCodeBook())
				{
					cout << "### MA SACH DA TON TAI ###" << endl;
					cout << "### VUI LONG NHAP LAI MA SACH KHAC ###" << endl;
					goto againn2;
				}
			}
			cout << "Nhap ten sach: ";
			getline(cin, title);
			cout << "Nhap ten tac gia: ";
			getline(cin, author);
			cout << "Nhap nha xuat ban: ";
			getline(cin, publish);
			cout << "Nhap ISBN: ";
			getline(cin, isbn);

			for (int i = 0; i < _book.size(); i++)
			{
				if (isbn == _book[i]->getISBNBook() && _book[i]->getTypeBook() == "ForeignBook")
				{
					cout << "### ISBN DA TON TAI ###" << endl;
					cout << "### VUI LONG NHAP ISBN KHAC ###" << endl;
					goto againn2;
				}
			}
			cout << "Nhap gia sach: ";
			cin >> price;
			foreign->setInformBook(code, title, author, publish, price, isbn);
			_book.push_back(foreign);
		}
	}
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::enterUserLib()
{
	int n;
	cout << "NHAP SO LUONG User: ";
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		User* us = new User;
	id1:;
		string name, id;
		cout << "Nhap ten User: ";
		getline(cin, name);
		cout << "Nhap ID thu vien: ";
		getline(cin, id);

		for (int i = 0; i < _user.size(); i++)
		{
			if (_user[i]->getIDUser() == id)
			{
				cout << "### ID USER DA TON TAI ###" << endl;
				cout << "### VUI LONG NHAP ID MOI ###" << endl;
				goto id1;
			}
		}
		us->setUser(name, id);
		_user.push_back(us);
	}
	cout << "=== HOAN THANH " << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::outListBookLib()
{
	cout << "=== BOOK IN LIBRARY ===" << endl << endl;
	for (int i = 0; i < _book.size(); i++)
	{
		cout << "=== STT " << i + 1 << " ===" << endl;
		_book[i]->outInformBook();
		cout << endl;
	}
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::outUserInLib()
{
	cout << "=== USER IN LIBRARY ===" << endl << endl;
	for (int i = 0; i < _user.size(); i++)
	{
		cout << "=== STT " << i + 1 << " ===" << endl;
		_user[i]->outUser();
		cout << endl;
	}
	cout << "=== HOAN THANH " << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::outBorrowInLib()
{
	for (int i = 0; i < _borrow.size(); i++)
	{
		_borrow[i]->outInforBorrow();
		cout << endl;
	}
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::editBookLib()
{
editNext:
	int flag = 0;
	cin.ignore();
	cout << "=== CHINH SUA THEO MA SACH ===" << endl;
	string code;
	cout << "Nhap ma sach: ";
	getline(cin, code);

	for (int i = 0; i < _book.size(); i++)
	{

		if (_book[i]->getCodeBook() == code && _book[i]->getTypeBook() == "VietBook")
		{
			flag = 1;
		enterAgain1:;
			int loai;
			cout << "Chinh sua:" << endl;
			cout << "\t1. Chinh sua ten sach." << endl;
			cout << "\t2. Chinh sua ma sach." << endl;
			cout << "\t3. Chinh sua ten tac gia." << endl;
			cout << "\t4. Chinh sua nha xuat ban." << endl;
			cout << "\t5. Chinh sua gia sach." << endl;
			cout << "==> ";
			cin >> loai;

			switch (loai)
			{
			case 1:
			{
				cin.ignore();
				string name;
				cout << "Nhap ten sach moi: ";
				getline(cin, name);
				_book[i]->setTitleBook(name);
				break;
			}
			case 2:
			{
			ms:;
				cin.ignore();
				string code;
				cout << "Nhap ma sach moi: ";
				getline(cin, code);
				for (int i = 0; i < _book.size(); i++)
				{
					if (code == _book[i]->getCodeBook())
					{
						cout << "### MA SACH DA TON TAI ###" << endl;
						cout << "### VUI LONG NHAP MA SACH KHAC ###" << endl;
						goto ms;
					}
				}
				_book[i]->setCodeBook(code);
				break;
			}
			case 3:
			{
				cin.ignore();
				string author;
				cout << "Nhap ten tac gia moi: ";
				getline(cin, author);
				_book[i]->setAuthorBook(author);
				break;
			}
			case 4:
			{
				cin.ignore();
				string NXB;
				cout << "Nhap ten NXB moi: ";
				getline(cin, NXB);
				_book[i]->setPublishBook(NXB);
				break;
			}
			case 5:
			{
				double price;
				cout << "Nhap gia moi: ";
				cin >> price;
				_book[i]->setPriceBook(price);
				break;
			}
			default:
			{
				cout << "### BAN NHAP SAI CHUC NANG ###" << endl;
				cout << "### VUI LONG NHAP LAI ###" << endl;
				goto enterAgain1;
			}
			}
		}
		else
			if (_book[i]->getCodeBook() == code && _book[i]->getTypeBook() == "ForeignBook")
			{
				flag = 1;
			enterAgain2:;
				int loai;
				cout << "Chinh sua:" << endl;
				cout << "\t1. Chinh sua ten sach." << endl;
				cout << "\t2. Chinh sua ma sach." << endl;
				cout << "\t3. Chinh sua ten tac gia." << endl;
				cout << "\t4. Chinh sua nha xuat ban." << endl;
				cout << "\t5. Chinh sua gia sach." << endl;
				cout << "\t6. Chinh sua ISBN." << endl;

				cout << "==> ";
				cin >> loai;

				switch (loai)
				{
				case 1:
				{
					cin.ignore();
					string name;
					cout << "Nhap ten sach moi: ";
					getline(cin, name);
					_book[i]->setTitleBook(name);
					break;
				}
				case 2:
				{
				ms2:;
					cin.ignore();
					string code;
					cout << "Nhap ma sach moi: ";
					getline(cin, code);
					for (int i = 0; i < _book.size(); i++)
					{
						if (code == _book[i]->getCodeBook())
						{
							cout << "### MA SACH DA TON TAI ###" << endl;
							cout << "### VUI LONG NHAP MA SACH KHAC ###" << endl;
							goto ms2;
						}
					}
					_book[i]->setCodeBook(code);
					break;
				}
				case 3:
				{
					cin.ignore();
					string author;
					cout << "Nhap ten tac gia moi: ";
					getline(cin, author);
					_book[i]->setAuthorBook(author);
					break;
				}
				case 4:
				{
					cin.ignore();
					string NXB;
					cout << "Nhap ten NXB moi: ";
					getline(cin, NXB);
					_book[i]->setPublishBook(NXB);
					break;
				}
				case 5:
				{
					double price;
					cout << "Nhap gia moi: ";
					cin >> price;
					_book[i]->setPriceBook(price);
					break;
				}
				case 6:
				{
				ms3:;
					cin.ignore();
					string ISBN;
					cout << "Nhap ISBN moi: ";
					getline(cin, ISBN);
					for (int i = 0; i < _book.size(); i++)
					{
						if (ISBN == _book[i]->getISBNBook() && _book[i]->getTypeBook() == "ForeignBook")
						{
							cout << "### ISBN DA TON TAI ###" << endl;
							cout << "### VUI LONG NHAP ISBN KHAC ###" << endl;
							goto ms3;
						}
					}
					_book[i]->setISBN(ISBN);
					break;
				}
				default:
				{
					cout << "### BAN NHAP SAI CHUC NANG ###" << endl;
					cout << "### VUI LONG NHAP LAI ###" << endl;
					goto enterAgain2;
				}
				}
			}
	}

	if (flag == 0)
		cout << "### KHONG TIM THAY ###" << endl;
	int next;
	cout << "BAN CO MUON TIEP TUC CHINH SUA (0:STOP, 1:NEXT)" << endl;
	cout << "==> ";
	cin >> next;
	if (next == 1)
	{
		system("cls");
		goto editNext;
	}
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::findBookLib()
{
enterAgain:;
	cout << "=== TIM KIEM SACH ===" << endl << endl;
	cout << "Chon cach thuc tim kiem:" << endl;
	cout << "\t1. Tim kiem theo ten sach." << endl;
	cout << "\t2. Tim kiem theo ma sach." << endl;
	cout << "\t3. Tim kiem theo ten tac gia." << endl;
	cout << "\t4. Tim kiem theo nha xuat ban." << endl;
	cout << "\t5. Tim kiem theo gia sach." << endl;
	cout << "\t6. Tim kiem theo ISBN." << endl;
	cout << "==> ";
	int loai;
	cin >> loai;

	switch (loai)
	{
	case 1:
	{
		int flag = 0;
		string name;
		cout << "Nhap ten sach: ";
		cin.ignore();
		getline(cin, name);
		cout << endl;
		for (int i = 0; i < _book.size(); i++)
		{
			if (compareToLowerStr(_book[i]->getTileBook(), name) == 1)
			{
				_book[i]->outInformBook();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "### KHONG TIM THAY ###" << endl;
		}
		int next;
		cout << "BAN CO MUON TIEP TUC TIM KIEM (0:STOP, 1:NEXT)" << endl;
		cout << "==> ";
		cin >> next;
		if (next == 0)
			break;
		else
			if (next == 1)
			{
				system("cls");
				goto enterAgain;
			}
	}
	case 2:
	{
		int flag = 0;
		string code;
		cout << "Nhap ma sach: ";
		cin.ignore();
		getline(cin, code);
		cout << endl;

		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getCodeBook() == code)
			{
				_book[i]->outInformBook();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "### KHONG TIM THAY ###" << endl;
		}
		int next;
		cout << "BAN CO MUON TIEP TUC TIM KIEM (0:STOP, 1:NEXT)" << endl;
		cout << "==> ";
		cin >> next;
		if (next == 0)
			break;
		else
			if (next == 1)
			{
				system("cls");
				goto enterAgain;
			}
	}
	case 3:
	{
		int flag = 0;
		string author;
		cout << "Nhap ten tac gia: ";
		cin.ignore();
		getline(cin, author);
		cout << endl;

		for (int i = 0; i < _book.size(); i++)
		{
			if (compareToLowerStr(_book[i]->getAuthorBook(), author) == 1)
			{
				_book[i]->outInformBook();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "### KHONG TIM THAY ###" << endl;
		}
		int next;
		cout << "BAN CO MUON TIEP TUC TIM KIEM (0:STOP, 1:NEXT)" << endl;
		cout << "==> ";
		cin >> next;
		if (next == 0)
			break;
		else
			if (next == 1)
			{
				system("cls");
				goto enterAgain;
			}
	}
	case 4:
	{
		int flag = 0;
		string publisher;
		cout << "Nhap ten NXB: ";
		cin.ignore();
		getline(cin, publisher);
		cout << endl;

		for (int i = 0; i < _book.size(); i++)
		{
			if (compareToLowerStr(_book[i]->getPublishBook(), publisher) == 1)
			{
				_book[i]->outInformBook();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "### KHONG TIM THAY ###" << endl;
		}
		int next;
		cout << "BAN CO MUON TIEP TUC TIM KIEM (0:STOP, 1:NEXT)" << endl;
		cout << "==> ";
		cin >> next;
		if (next == 0)
			break;
		else
			if (next == 1)
			{
				system("cls");
				goto enterAgain;
			}
	}
	case 5:
	{
		int flag = 0;
		double price;
		cout << "Nhap gia sach: ";
		cin >> price;
		cout << endl;

		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getPriceBook() == price)
			{
				_book[i]->outInformBook();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "### KHONG TIM THAY ###" << endl;
		}
		int next;
		cout << "BAN CO MUON TIEP TUC TIM KIEM (0:STOP, 1:NEXT)" << endl;
		cout << "==> ";
		cin >> next;
		if (next == 0)
			break;
		else
			if (next == 1)
			{
				system("cls");
				goto enterAgain;
			}
	}
	case 6:
	{
		int flag = 0;
		string ISBN;
		cout << "Nhap ISBN: ";
		cin.ignore();
		getline(cin, ISBN);
		cout << endl;

		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getISBNBook() == ISBN)
			{
				_book[i]->outInformBook();
				cout << endl;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "### KHONG TIM THAY ###" << endl;
		}
		int next;
		cout << "BAN CO MUON TIEP TUC TIM KIEM (0:STOP, 1:NEXT)" << endl;
		cout << "==> ";
		cin >> next;
		if (next == 0)
			break;
		else
			if (next == 1)
			{
				system("cls");
				goto enterAgain;
			}
	}
	default:
		cout << "### BAN NHAP SAI PHUONG THUC TIM KIEM ###." << endl;
		cout << "### VUI LONG NHAP LAI ###" << endl;
		goto enterAgain;
	}
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::addBookLib()
{
	cout << "NHAP SO LUONG SACH CAN THEM: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
	enterAgain:
		int loai;
		cout << "NHAP LOAI SACH (0:VietBook, 1:ForeignBook): ==> ";
		cin >> loai;

		if (loai != 1 && loai != 0)
		{
			cout << "### BAN NHAP SAI LOAI SACH ###" << endl;
			cout << "### VUI LONG NHAP LAI LOAI SACH ###" << endl;
			goto enterAgain;
		}
		else
			if (loai == 0)
			{
				VietBook* viet = new VietBook;
				viet->enterInformBook();
				_book.push_back(viet);
			}
			else
				if (loai == 1)
				{
					ForeignBook* foreign = new ForeignBook;
					foreign->enterInformBook();
					_book.push_back(foreign);
				}
	}
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::addBookLib(Book* book)
{
	_book.push_back(book);
}

void Library::delBookLib()
{
delNext:;
	cout << "=== XOA SACH TRONG THU VIEN ===" << endl << endl;
	int chucnang;
	cout << "\t1.Xoa theo ten sach: " << endl;
	cout << "\t2.Xoa theo ten tac gia: " << endl;
	cout << "\t3.Xoa theo ma sach: " << endl;
	cout << "\t4.Xoa theo ten NXB: " << endl;
	cout << "\t5.Xoa theo gia sach: " << endl;
	cout << "\t6.Xoa theo ISBN: " << endl;
	int flag = 0;
	cout << "==> ";
	cin >> chucnang;
	switch (chucnang)
	{
	case 1:
	{
		string name;
		cout << "Nhap ten sach: ";
		cin.ignore();
		getline(cin, name);
		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getTileBook() == name)
			{
				flag = 1;
				if (_book[i]->checkBorrow() == 1)
				{
					cout << "### SACH CO NGUOI MUON, KHONG THE XOA ###" << endl;
					break;
				}
				_book[i]->setAuthorBook("");
				_book[i]->setCodeBook("");
				_book[i]->setPriceBook(0);
				_book[i]->setPublishBook("");
				_book[i]->setTitleBook("");
				_book.erase(_book.begin() + i);
				i--;

			}
		}
		break;
	}
	case 2:
	{
		string author;
		cout << "Nhap ten tac gia: ";
		cin.ignore();
		getline(cin, author);
		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getAuthorBook() == author)
			{
				flag = 1;
				if (_book[i]->checkBorrow() == 1)
				{
					cout << "### SACH CO NGUOI MUON, KHONG THE XOA ###" << endl;
					break;
				}
				_book[i]->setAuthorBook("");
				_book[i]->setCodeBook("");
				_book[i]->setPriceBook(0);
				_book[i]->setPublishBook("");
				_book[i]->setTitleBook("");
				_book.erase(_book.begin() + i);
				i--;
			}
		}break;
	}
	case 3:
	{
		string code;
		cout << "Nhap ten ma sach: ";
		cin.ignore();
		getline(cin, code);
		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getCodeBook() == code)
			{
				flag = 1;
				if (_book[i]->checkBorrow() == 1)
				{
					cout << "### SACH CO NGUOI MUON, KHONG THE XOA ###" << endl;
					break;
				}
				_book[i]->setAuthorBook("");
				_book[i]->setCodeBook("");
				_book[i]->setPriceBook(0);
				_book[i]->setPublishBook("");
				_book[i]->setTitleBook("");
				_book.erase(_book.begin() + i);
				i--;
			}
		}break;
	}
	case 4:
	{
		string nxb;
		cout << "Nhap ten NXB: ";
		cin.ignore();
		getline(cin, nxb);
		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getPublishBook() == nxb)
			{
				flag = 1;
				if (_book[i]->checkBorrow() == 1)
				{
					cout << "### SACH CO NGUOI MUON, KHONG THE XOA ###" << endl;
					break;
				}
				_book[i]->setAuthorBook("");
				_book[i]->setCodeBook("");
				_book[i]->setPriceBook(0);
				_book[i]->setPublishBook("");
				_book[i]->setTitleBook("");
				_book.erase(_book.begin() + i);
				i--;
			}
		}break;
	}
	case 5:
	{
		double price;
		cout << "Nhap gia sach: ";
		cin >> price;

		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getPriceBook() == price)
			{
				flag = 1;
				if (_book[i]->checkBorrow() == 1)
				{
					cout << "### SACH CO NGUOI MUON, KHONG THE XOA ###" << endl;
					break;
				}
				_book[i]->setAuthorBook("");
				_book[i]->setCodeBook("");
				_book[i]->setPriceBook(0);
				_book[i]->setPublishBook("");
				_book[i]->setTitleBook("");
				_book.erase(_book.begin() + i);
				i--;
			}
		}break;
	}
	case 6:
	{
		string isbn;
		cout << "Nhap ISBN: ";
		cin.ignore();
		getline(cin, isbn);
		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getISBNBook() == isbn && _book[i]->getTypeBook() == "ForeignBook")
			{
				flag = 1;
				if (_book[i]->checkBorrow() == 1)
				{
					cout << "### SACH CO NGUOI MUON, KHONG THE XOA ###" << endl;
					break;
				}
				_book[i]->setAuthorBook("");
				_book[i]->setCodeBook("");
				_book[i]->setPriceBook(0);
				_book[i]->setPublishBook("");
				_book[i]->setTitleBook("");
				_book.erase(_book.begin() + i);
				i--;
			}
		}break;
	}
	default:
	{
		cout << "### BAN NHAP SAI PHUONG THUC XOA ###." << endl;
		cout << "### VUI LONG NHAP LAI ###." << endl;
		goto delNext;
	}
	}


	if (flag == 0)
		cout << "### KHONG TIM THAY MA SACH ###" << endl;

	int next;
	cout << "BAN CO MUON TIEP TUC CHINH SUA (0:STOP, 1:NEXT)" << endl;
	cout << "==> ";
	cin >> next;
	if (next == 1)
	{
		system("cls");
		goto delNext;
	}
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::editUserLib()
{
editNext:;
	cin.ignore();
	cout << "=== CHINH SUA THONG TIN NGUOI DUNG ===" << endl << endl;
	cout << "Nhap ID thu vien: ";
	string id;
	getline(cin, id);
	int flag = 0;
	for (int i = 0; i < _user.size(); i++)
	{
		if (_user[i]->getIDUser() == id)
		{
		enterMode:;
			flag = 1;
			cout << "\t1. Chinh sua ten." << endl;
			cout << "\t2 .Chinh sua ID." << endl;
			cout << "==> ";
			int loai;
			cin >> loai;

			switch (loai)
			{
			case 1:
			{
			entername:;
				cin.ignore();
				string name;
				cout << "Nhap ten moi: ";
				getline(cin, name);
				for (int j = 0; j < _user.size(); j++)
				{
					if (_user[j]->getNameUser() == name)
					{
						cout << "### TEN DA TON TAI ###" << endl;
						cout << "### VUI LONG NHAP LAI ###" << endl;
						goto entername;
					}
				}
				_user[i]->setNameUser(name);
				break;
			}
			case 2:
			{
			enterid:;
				cin.ignore();
				string ID;
				cout << "Nhap ID moi: ";
				getline(cin, ID);
				for (int j = 0; j < _user.size(); j++)
				{
					if (_user[j]->getIDUser() == ID)
					{
						cout << "### ID DA TON TAI ###" << endl;
						cout << "### VUI LONG NHAP LAI ###" << endl;
						goto enterid;
					}
				}
				_user[i]->setIDUser(ID);
				break;
			}
			default:
			{
				cout << "### NHAP SAI CHUC NANG ###" << endl;
				cout << "### VUI LONG NHAP LAI ###" << endl;
				goto enterMode;
			}
			}
		}
	}

	if (flag == 0)
	{
		cout << "### ID KHONG TON TAI ###" << endl;
	}
	int next;
	cout << "BAN CO MUON TIEP TUC CHINH SUA (0:STOP, 1:NEXT)" << endl;
	cout << "==> ";
	cin >> next;
	if (next == 1)
	{
		system("cls");
		goto editNext;
	}
	cout << "=== HOAN THANH " << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::findUserLib()
{
enterchucnang:;
	cout << "=== TIM KIEM NGUOI DUNG ===" << endl << endl;
	cout << "\t1. Tim theo ten." << endl;
	cout << "\t2. Tim theo ID." << endl;
	int chucnang, flag = 0;
	cout << "==> ";
	cin >> chucnang;

	switch (chucnang)
	{
	case 1:
	{
		cin.ignore();
		string name;
		cout << "Nhap ten: ";
		getline(cin, name);
		cout << endl;
		for (int j = 0; j < _user.size(); j++)
		{
			if (compareToLowerStr(_user[j]->getNameUser(), name) == 1)
			{
				flag = 1;
				_user[j]->outUser();
				cout << endl;
			}
		}
		break;
	}
	case 2:
	{
		cin.ignore();
		string ID;
		cout << "Nhap ID user: ";
		getline(cin, ID);
		cout << endl;
		for (int j = 0; j < _user.size(); j++)
		{
			if (_user[j]->getIDUser() == ID)
			{
				flag = 1;
				_user[j]->outUser();
				cout << endl;
			}
		}
		break;
	}
	default:
	{
		cout << "### BAN NHAP SAI CHUC NANG ###" << endl;
		cout << "### VUI LONG NHAP LAI ###" << endl;
		goto enterchucnang;
	}
	}

	if (flag == 0)
	{
		cout << "### KHONG TON TAI ###" << endl;
	}
	int next;
	cout << "BAN CO MUON TIEP TUC CHINH SUA (0:STOP, 1:NEXT)" << endl;
	cout << "==> ";
	cin >> next;
	if (next == 1)
	{
		system("cls");
		goto enterchucnang;
	}
	cout << "=== HOAN THANH " << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::addUserLib()
{
	int n;
	cout << "NHAP SO LUONG USER CAN THEM: ";
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		User* us = new User;
	id1:;
		string name, id;
		cout << "Nhap ten User: ";
		getline(cin, name);
		cout << "Nhap ID thu vien: ";
		getline(cin, id);

		for (int i = 0; i < _user.size(); i++)
		{
			if (_user[i]->getIDUser() == id)
			{
				cout << "### ID DA TON TAI ###" << endl;
				cout << "### VUI LONG NHAP LAI ID ###." << endl;
				goto id1;
			}
		}

		us->setUser(name, id);
		_user.push_back(us);
		cout << endl;
	}
	cout << "=== HOAN THANH " << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::delUserLib()
{
	cout << "=== XOA NGUOI DUNG ===" << endl << endl;
	cin.ignore();
	string ID;
	cout << "Nhap ID user: ";
	getline(cin, ID);


	for (int i = 0; i < _user.size(); i++)
	{
		if (_user[i]->getIDUser() == ID)
		{
			if (_user[i]->getIsBorrow() == 1)
			{
				cout << "### NGUOI NAY DANG MUON SACH, KHONG THE XOA ###" << endl;
				break;
			}
			_user.erase(_user.begin() + i);
			cout << "=== XOA THANH CONG ===" << endl;
		}
	}
	cout << "=== HOAN THANH " << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::addBorrowInLib()
{
	cout << "=== MUON SACH THU VIEN ===" << endl << endl;

	int account;
	int n;
	string ID;
	Date today;
	cout << "BAN DA CO ID THU VIEN (1:YES, 0:NO): ==> ";
	cin >> account;
	if (account == 1)
	{
		cin.ignore();
		cout << "NHAP ID USER: ";
		getline(cin, ID);
		cout << "NHAP SO SACH CAN MUON: ";
		cin >> n;
		cout << "NHAP NGAY MUON (vd 1/1/2020): ";
		cin >> today;
	}
	else
	{
		string name;
		cout << "=== TAO THANH VIEN THU VIEN ===" << endl;
		User* us = new User;
		cin.ignore();
	enterIDagain:;
		cout << "Tao ID library: ";
		getline(cin, ID);
		for (int i = 0; i < _user.size(); i++)
		{
			if (_user[i]->getIDUser() == ID)
			{
				cout << "### ID DA TON TAI ###" << endl;
				cout << "### VUI LONG NHAP LAI ###" << endl;
				goto enterIDagain;
			}
		}
		cout << "Tao ten user: ";
		getline(cin, name);

		us->setUser(name, ID);
		_user.push_back(us);
		cout << "Nhap so sach can muon: ";
		cin >> n;
		cout << "Nhap ngay muon (vd 11/11/2020): ";
		cin >> today;
	}

	int flag = 0;
	Borrow* brow;
	for (int size = 0; size < _borrow.size(); size++)
	{
		if (_borrow[size]->getIDBorrow() == ID)
		{
			flag = 1;
			brow = _borrow[size];
			cin.ignore();
			for (int i = 0; i < n; i++)
			{
			enterBookAgain:;
				cout << "== QUYEN " << i + 1 << " ===" << endl;
				string code;
				cout << "Nhap ma sach: ";
				getline(cin, code);
				for (int j = 0; j < _book.size(); j++)
				{
					if (code == _book[j]->getCodeBook() && _book[j]->checkBorrow() == 0)
					{
						_book[j]->setBorrow(1);
						brow->addBorrowBook(_book[j], today);
						break;
					}
					else
						if (code == _book[j]->getCodeBook() && _book[j]->checkBorrow() == 1)
						{
							cout << "### BAN NHAP SAI, SACH NAY DA CO NGUOI MUON ###" << endl;
							cout << "### VUI LONG KIEM TRA VA NHAP LAI ###" << endl;
							goto enterBookAgain;
							break;
						}
				}
			}
			break;
		}
	}

	if (flag == 0)
	{
		for (int size = 0; size < _user.size(); size++)
		{
			if (_user[size]->getIDUser() == ID)
			{
				brow = new Borrow;
				brow->addUserBorrow(_user[size]);
				_user[size]->setIsBorrow(1);

				cin.ignore();
				for (int i = 0; i < n; i++)
				{
				enterBookAgain2:;
					cout << "== QUYEN " << i + 1 << " ===" << endl;
					string code;
					cout << "Nhap ma sach: ";
					getline(cin, code);
					for (int j = 0; j < _book.size(); j++)
					{
						if (code == _book[j]->getCodeBook() && _book[j]->checkBorrow() == 0)
						{
							_book[j]->setBorrow(1);
							brow->addBorrowBook(_book[j], today);
							break;
						}
						else
							if (code == _book[j]->getCodeBook() && _book[j]->checkBorrow() == 1)
							{
								cout << "### BAN NHAP SAI, SACH NAY DA CO NGUOI MUON ###" << endl;
								cout << "### VUI LONG KIEM TRA VA NHAP LAI ###" << endl;
								goto enterBookAgain2;
							}
					}
				}
				break;
			}
		}
	}

	if (flag == 0)
		_borrow.push_back(brow);
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::addReturnInLib()
{
	cout << "=== TRA SACH THU VIEN ===" << endl << endl;

	int moneyFined = 0;
	string ID;
	int n;
	Date today;
	cout << "NHAP NGAY TRA SACH: ";
	cin >> today;
	cout << "NHAP SO SACH TRA: ";
	cin >> n;
	cin.ignore();
	cout << "NHAP ID User: ";
	getline(cin, ID);

	for (int i = 0; i < _borrow.size(); i++)
	{
		if (_borrow[i]->getIDBorrow() == ID)
		{
			for (int j = 0; j < n; j++)
			{
				string code;
				cout << "Nhap ma sach: ";
				getline(cin, code);
				for (int k = 0; k < _borrow[i]->getNumBookBorrow(); k++)
				{
					if (_borrow[i]->getCodeBookBorrow(k) == code)
					{

						moneyFined += _borrow[i]->tinhTienPhatKhiTra(today, k);
						_borrow[i]->setReturnBook(k);
						_borrow[i]->delBorrowBookAt(k);
						break;
					}
				}
			}
			if (_borrow[i]->getNumBookBorrow() == 0)
			{
				_borrow.erase(_borrow.begin() + i);
			}
		}
		break;
	}
	cout << "### BAN BI PHAT: " << moneyFined << endl;
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::listFinedPeople()
{
	cout << "=== TINH TIEN PHAT ===" << endl << endl;

	Date today;
	cout << "NHAP NGAY TINH TIEN PHAT (vd 11/11/2020): ";
	cin >> today;

	for (int i = 0; i < _borrow.size(); i++)
	{
		int moneyFined = 0;
		moneyFined = _borrow[i]->tinhTienPhatCaNhan(today);
		if (moneyFined != 0)
		{
			_borrow[i]->outInforBorrowUser();
			cout << "Tong tien phat: " << moneyFined << endl;
		}
	}
	cout << "=== HOAN THANH ===" << endl;
	cout << "=== NHAN ENTER DE TIEP TUC ===";
	_getch();
}

void Library::readFileBookLib(char* input)
{
	fstream in;
	in.open(input);

	if (in.is_open())
	{
		int n;
		in >> n;
		if (n == 0)
		{
			cout << "### KHONG CO QUYEN SACH NAO TRONG FILE ###" << endl;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			string type;
			getline(in, type);
			getline(in, type);

			if (type == "VietBook")
			{
				VietBook* vbook = new VietBook;
				string code, title, author, publish;
				double price;
				getline(in, code);
				getline(in, title);
				getline(in, author);
				getline(in, publish);
				in >> price;
				vbook->setInformBook(code, title, author, publish, price);
				_book.push_back(vbook);
			}
			else
			{
				if (type == "ForeignBook")
				{
					ForeignBook* fbook = new ForeignBook;
					string code, title, author, publish, isbn;
					double price;
					getline(in, code);
					getline(in, title);
					getline(in, author);
					getline(in, publish);
					getline(in, isbn);
					in >> price;
					fbook->setInformBook(code, title, author, publish, price, isbn);
					_book.push_back(fbook);
				}
			}
		}
	}
	else
	{
		cout << "### KHONG MO DUOC FILE LIST BOOK ###" << endl;
		return;
	}
	in.close();
}

void Library::readFileUserLib(char* input)
{
	fstream in;
	in.open(input);

	if (in.is_open())
	{
		int n;
		in >> n;
		if (n == 0)
		{
			cout << "### KHONG CO THONG TIN USER TRONG FILE ###";
			return;
		}
		string x;
		getline(in, x);

		for (int i = 0; i < n; i++)
		{
			string name, ID;
			getline(in, name);
			getline(in, ID);
			User* us = new User;
			us->setUser(name, ID);
			_user.push_back(us);
		}
	}
	else
	{
		cout << "### KHONG MO DUOC FILE USER ###" << endl;
		return;
	}
	in.close();
}

void Library::readFileBorrowLib(char* input)
{
	fstream in;
	in.open(input);

	if (in.is_open())
	{
		int n;
		in >> n;
		if (n == 0)
		{
			cout << "### KHONG CO AI MUON SACH ###" << endl;
			return;
		}
		string x;
		getline(in, x);
		for (int i = 0; i < n; i++)
		{
			string IDuser;
			getline(in, IDuser);
			Borrow* brow = new Borrow;
			for (int j = 0; j < _user.size(); j++)
			{
				if (_user[j]->getIDUser() == IDuser)
				{
					brow->addUserBorrow(_user[j]);
					_user[j]->setIsBorrow(1);
					break;
				}
			}

			int numbook;
			in >> numbook;
			getline(in, x);
			for (int j = 0; j < numbook; j++)
			{
				string code;
				Date dateborrow;
				getline(in, code);
				in >> dateborrow;
				getline(in, x);
				for (int k = 0; k < _book.size(); k++)
				{
					if (_book[k]->getCodeBook() == code && _book[k]->checkBorrow() == 0)
					{
						brow->addBorrowBook(_book[k], dateborrow);
						_book[k]->setBorrow(1);
						break;
					}
				}
			}
			_borrow.push_back(brow);
		}
	}
	else
	{
		cout << "### KHONG MO DUOC FILE LIST BOOK ###" << endl;
		return;
	}
	in.close();
}

void Library::writeFileBookLib(char* output)
{
	fstream out;
	out.open(output, ios::out);

	if (out.is_open())
	{
		out << _book.size() << endl;
		for (int i = 0; i < _book.size(); i++)
		{
			if (_book[i]->getTypeBook() == "VietBook")
			{
				out << _book[i]->getTypeBook() << endl;
				out << _book[i]->getCodeBook() << endl;
				out << _book[i]->getTileBook() << endl;
				out << _book[i]->getAuthorBook() << endl;
				out << _book[i]->getPublishBook() << endl;
				out << _book[i]->getPriceBook() << endl;
			}
			else
				if (_book[i]->getTypeBook() == "ForeignBook")
				{
					out << _book[i]->getTypeBook() << endl;
					out << _book[i]->getCodeBook() << endl;
					out << _book[i]->getTileBook() << endl;
					out << _book[i]->getAuthorBook() << endl;
					out << _book[i]->getPublishBook() << endl;
					out << _book[i]->getISBNBook() << endl;
					out << _book[i]->getPriceBook() << endl;
				}

		}
	}
	else
	{
		cout << "### KHONG MO DUOC FILE GHI LIST BOOK ###" << endl;
		return;
	}
	out.close();
}

void Library::writeFileUserLib(char* output)
{
	fstream out;
	out.open(output, ios::out);

	if (out.is_open())
	{
		out << _user.size() << endl;
		for (int i = 0; i < _user.size(); i++)
		{
			out << _user[i]->getNameUser() << endl;
			out << _user[i]->getIDUser() << endl;
		}
	}
	else
	{
		cout << "### KHONG MO DUOC FILE GHI LIST USER ###" << endl;
		return;
	}
	out.close();
}

void Library::writeFileBorrowLib(char* output)
{
	fstream out;
	out.open(output, ios::out);

	if (out.is_open())
	{
		out << _borrow.size() << endl;
		for (int i = 0; i < _borrow.size(); i++)
		{
			out << _borrow[i]->getIDBorrow() << endl;
			out << _borrow[i]->getNumBookBorrow() << endl;
			for (int j = 0; j < _borrow[i]->getNumBookBorrow(); j++)
			{
				out << _borrow[i]->getCodeBookBorrow(j) << endl;
				out << _borrow[i]->getDateBorrow(j) << endl;
			}
		}
	}
	else
	{
		cout << "### KHONG MO DUOC FILE GHI LIST USER ###" << endl;
		return;
	}
	out.close();
}

int compareToLowerStr(string x, string y)
{
	int min;
	min = x.length();
	if (min > y.length())
		min = y.length();
	for (int i = 0; i < min; i++)
	{
		if (tolower(x[i]) != tolower(y[i]))
			return 0;
	}
	if (x.length() != y.length())
		return 0;
	return 1;
}