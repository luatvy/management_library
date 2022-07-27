#include"Book.h"
#include"VietBook.h"
#include"ForeignBook.h"
#include<vector>
#include"Library.h"
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	try
	{
		Library* lib = new Library;
		int mode;
		cout << "=== CHUONG TRINH QUAN LY THU VIEN ===" << endl << endl;
		cout << "\t1. LOAD THU VIEN TU FILE." << endl;
		cout << "\t2. TAO THU VIEN MOI." << endl;
		cout << "==> ";
		cin >> mode;

		if (mode == 1)
		{
			char listbook[100], listuser[100], listborrow[100];
			cout << "NHAP DUONG DAN FILE LISTBOOK: ";
			cin >> listbook;
			cout << "NHAP DUONG DAN FILE LISTUSER: ";
			cin >> listuser;
			cout << "NHAP DUONG DAN FILE LISTBORROW: ";
			cin >> listborrow;

			lib->readFileBookLib(listbook);
			lib->readFileUserLib(listuser);
			lib->readFileBorrowLib(listborrow);

			cout << "=== LOAD FILE THANH CONG ===" << endl;
			cout << "NHAN ENTER DE TIEP TUC" << endl;
			_getch();

		}
	quanlythuvien:;
		system("cls");
		cout << "=== CHUONG TRINH QUAN LY THU VIEN ===" << endl << endl;
		cout << "\t1. QUAN LY SACH." << endl;
		cout << "\t2. QUAN LY NGUOI DUNG." << endl;
		cout << "\t3. QUAN LY MUON TRA SACH." << endl;
		cout << "\t4. LUU VAO FILE VA THOAT." << endl;
		cout << "\t5. THOAT CHUONG TRINH." << endl;
		cout << "==> ";
		int quanly;
		cin >> quanly;

		switch (quanly)
		{
		case 1:
		{
		quanlysach:;
			system("cls");
			cout << "=== QUAN LY SACH ===" << endl << endl;
			cout << "\t1. NHAP SACH." << endl;
			cout << "\t2. THEM SACH." << endl;
			cout << "\t3. TIM SACH." << endl;
			cout << "\t4. XOA SACH." << endl;
			cout << "\t5. CHINH SUA SACH." << endl;
			cout << "\t6. IN SACH." << endl;
			cout << "\t7. TRO VE." << endl;
			cout << "\t8. THOAT." << endl;
			cout << "==> ";
			int qlsach;
			cin >> qlsach;

			switch (qlsach)
			{
			case 1:
			{
				system("cls");
				cout << "=== QUAN LY SACH ===" << endl << endl;
				lib->enterBookLib();
				goto quanlysach;
			}
			case 2:
			{
				system("cls");
				cout << "=== QUAN LY SACH ===" << endl << endl;
				lib->addBookLib();
				goto quanlysach;
			}
			case 3:
			{
				system("cls");
				cout << "=== QUAN LY SACH ===" << endl << endl;
				lib->findBookLib();
				goto quanlysach;
			}
			case 4:
			{
				system("cls");
				cout << "=== QUAN LY SACH ===" << endl << endl;
				lib->delBookLib();
				goto quanlysach;
			}
			case 5:
			{
				system("cls");
				cout << "=== QUAN LY SACH ===" << endl << endl;
				lib->editBookLib();
				goto quanlysach;
			}
			case 6:
			{
				system("cls");
				cout << "=== QUAN LY SACH ===" << endl << endl;
				lib->outListBookLib();
				goto quanlysach;
			}
			case 7:
			{
				goto quanlythuvien;
			}
			default:
				return 1;
				break;
			}
		}
		case 2:
		{
		quanlynguoidung:;
			system("cls");
			cout << "=== QUAN NGUOI DUNG ===" << endl << endl;
			cout << "\t1. NHAP DANH SACH USER." << endl;
			cout << "\t2. THEM USER." << endl;
			cout << "\t3. TIM KIEM THONG TIN USER." << endl;
			cout << "\t4. XOA USER." << endl;
			cout << "\t5. CHINH SUA USER." << endl;
			cout << "\t6. IN DANH SACH USER." << endl;
			cout << "\t7. TRO VE." << endl;
			cout << "\t8. THOAT." << endl;
			cout << "==> ";
			int qluser;
			cin >> qluser;

			switch (qluser)
			{
			case 1:
			{
				system("cls");
				cout << "=== QUAN NGUOI DUNG ===" << endl << endl;
				lib->enterUserLib();
				goto quanlynguoidung;
			}
			case 2:
			{
				system("cls");
				cout << "=== QUAN NGUOI DUNG ===" << endl << endl;
				lib->addUserLib();
				goto quanlynguoidung;
			}
			case 3:
			{
				system("cls");
				cout << "=== QUAN NGUOI DUNG ===" << endl << endl;
				lib->findUserLib();
				goto quanlynguoidung;
			}
			case 4:
			{
				system("cls");
				cout << "=== QUAN NGUOI DUNG ===" << endl << endl;
				lib->delUserLib();
				goto quanlynguoidung;
			}
			case 5:
			{
				system("cls");
				cout << "=== QUAN NGUOI DUNG ===" << endl << endl;
				lib->editUserLib();
				goto quanlynguoidung;
			}
			case 6:
			{
				system("cls");
				cout << "=== QUAN NGUOI DUNG ===" << endl << endl;
				lib->outUserInLib();
				goto quanlynguoidung;
			}
			case 7:
			{
				goto quanlythuvien;
			}
			default:
				return 1;
				break;
			}

		}
		case 3:
		{
		muontrasach:;
			system("cls");
			cout << "=== MUON TRA SACH ===" << endl << endl;
			cout << "\t1. NHAP USER MUON SACH." << endl;
			cout << "\t2. NHAP USER TRA SACH." << endl;
			cout << "\t3. IN DANH SACH TIEN PHAT." << endl;
			cout << "\t4. IN DANH SACH DANG MUON." << endl;
			cout << "\t5. TRO VE." << endl;
			cout << "\t6. THOAT." << endl;
			cout << "==> ";
			int qluser;
			cin >> qluser;

			switch (qluser)
			{
			case 1:
			{
				system("cls");
				cout << "=== MUON TRA SACH ===" << endl << endl;
				lib->addBorrowInLib();
				goto muontrasach;
			}
			case 2:
			{
				system("cls");
				cout << "=== MUON TRA SACH ===" << endl << endl;
				lib->addReturnInLib();
				goto muontrasach;
			}
			case 3:
			{
				system("cls");
				cout << "=== MUON TRA SACH ===" << endl << endl;
				lib->listFinedPeople();
				goto muontrasach;
			}
			case 4:
			{
				system("cls");
				cout << "=== MUON TRA SACH ===" << endl << endl;
				lib->outBorrowInLib();
				goto muontrasach;
			}
			case 5:
			{
				goto quanlythuvien;
			}
			default:
				return 1;
				break;
			}
		case 4:
		{
			system("cls");
			cout << "=== LUU FILE VA THOAT ===" << endl << endl;
			char listbook[100], listuser[100], listborrow[100];
			cout << "NHAP DUONG DAN LUU FILE LISTBOOK: ";
			cin >> listbook;
			cout << "NHAP DUONG DAN LUU FILE LISTUSER: ";
			cin >> listuser;
			cout << "NHAP DUONG DAN LUU FILE LISTBORROW: ";
			cin >> listborrow;

			lib->writeFileBookLib(listbook);
			lib->writeFileUserLib(listuser);
			lib->writeFileBorrowLib(listborrow);
			cout << "=== HOAN THANH ===" << endl;
			cout << "=== NHAN ENTER DE THOAT ===";
			_getch();
		}
		default:
			return 1;
			break;
		}
		}
		system("Pause");
		return 1;
	}
	catch (...)
	{
		cout << endl << "Have some bug." << endl;
	}
}