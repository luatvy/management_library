#pragma once
#include<iostream>
using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	~Date();
	Date(const Date& ntn);
	Date(int day, int month, int year);
	Date& operator=(const Date& ntn);

	void setDate(const Date& date);
	void setDate(int day, int month, int year);

	Date operator+=(int x);
	Date& operator++();
	Date operator++(int);
	Date& operator-=(int x);
	Date& operator--();
	Date operator--(int);

	bool operator<(const Date& ntn);
	bool operator<=(const Date& ntn);
	bool operator>(const Date& ntn);
	bool operator>=(const Date& ntn);
	bool operator!=(const Date& ntn);

	friend istream& operator>>(istream& is, Date& ntn);
	friend ostream& operator<<(ostream& os, const Date& ntn);

	int DateTrue();
};

void sortDate(Date* date, int count);