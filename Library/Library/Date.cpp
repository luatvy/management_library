#include"Date.h"


Date::Date()
{
	_day = 0;
	_month = 0;
	_year = 0;
}


Date::~Date()
{
	_day = 0;
	_month = 0;
	_year = 0;
}

Date::Date(const Date& ntn)
{
	_day = ntn._day;
	_month = ntn._month;
	_year = ntn._year;
}
Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}

Date& Date::operator=(const Date& ntn)
{
	_day = ntn._day;
	_month = ntn._month;
	_year = ntn._year;
	return*this;
}

void Date::setDate(const Date& date)
{
	_day = date._day;
	_month = date._month;
	_year = date._year;
}

void Date::setDate(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}


Date Date::operator+=(int x)
{
	for (int i = 0; i < x; i++)
		(*this)++;
	return *this;
}
Date& Date::operator++()
{
	int namNhuan = 0;
	if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
		namNhuan = 1;

	if (_day == 31 && _month == 12)
	{
		_year++;
		_day = 1;
		_month = 1;
	}
	else
		if ((_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10) && _day == 31)
		{
			_day = 1;
			_month++;
		}
		else
			if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day == 30)
			{
				_day = 1;
				_month++;
			}
			else
				if (_month == 2 && namNhuan == 0 && _day == 28)
				{
					_day = 1;
					_month++;
				}
				else
					if (_month == 2 && namNhuan == 1 && _day == 29)
					{
						_day = 1;
						_month++;
					}
					else
					{
						_day++;
					}
	return*this;
}
Date Date::operator++(int)
{
	Date temp(*this);
	++(*this);

	int namNhuan = 0;
	if (temp._year % 400 == 0 || (temp._year % 4 == 0 && temp._year % 100 != 0))
		namNhuan = 1;

	if (temp._day == 31 && temp._month == 12)
	{
		temp._year++;
		temp._day = 1;
		temp._month = 1;
	}
	else
		if ((temp._month == 1 || temp._month == 3 || temp._month == 5 || temp._month == 7 || temp._month == 8 || temp._month == 10) && temp._day == 31)
		{
			temp._day = 1;
			temp._month++;
		}
		else
			if ((temp._month == 4 || temp._month == 6 || temp._month == 9 || temp._month == 11) && temp._day == 30)
			{
				temp._day = 1;
				temp._month++;
			}
			else
				if (temp._month == 2 && namNhuan == 0 && temp._day == 28)
				{
					temp._day = 1;
					temp._month++;
				}
				else
					if (temp._month == 2 && namNhuan == 1 && temp._day == 29)
					{
						temp._day = 1;
						temp._month++;
					}
					else
					{
						temp._day++;
					}

	return temp;
}
Date& Date::operator-=(int x)
{
	for (int i = 0; i < x; i++)
		(*this)--;
	return *this;
}
Date& Date::operator--()
{
	int namNhuan = 0;
	if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
		namNhuan = 1;

	if (_day == 1 && _month == 1)
	{
		_year--;
		_day = 31;
		_month = 12;
	}
	else
		if ((_month == 1 || _month == 2 || _month == 4 || _month == 6 || _month == 9 || _month == 11) && _day == 1)
		{
			_day = 31;
			_month--;
		}
		else
			if ((_month == 5 || _month == 7 || _month == 10 || _month == 12) && _day == 1)
			{
				_day = 30;
				_month--;
			}
			else
				if (_month == 3 && namNhuan == 0 && _day == 1)
				{
					_day = 28;
					_month--;
				}
				else
					if (_month == 3 && namNhuan == 1 && _day == 1)
					{
						_day = 29;
						_month--;
					}
					else
					{
						_day--;
					}
	return*this;
}
Date Date::operator--(int)
{
	Date temp(*this);
	--(*this);

	int namNhuan = 0;
	if (temp._year % 400 == 0 || (temp._year % 4 == 0 && temp._year % 100 != 0))
		namNhuan = 1;

	if (temp._day == 1 && temp._month == 1)
	{
		temp._year--;
		temp._day = 31;
		temp._month = 12;
	}
	else
		if ((temp._month == 1 || temp._month == 2 || temp._month == 4 || temp._month == 6 || temp._month == 9 || temp._month == 11) && temp._day == 1)
		{
			temp._day = 31;
			temp._month--;
		}
		else
			if ((temp._month == 5 || temp._month == 7 || temp._month == 10 || temp._month == 12) && temp._day == 1)
			{
				temp._day = 30;
				temp._month--;
			}
			else
				if (temp._month == 3 && namNhuan == 0 && temp._day == 1)
				{
					temp._day = 28;
					temp._month--;
				}
				else
					if (temp._month == 3 && namNhuan == 1 && temp._day == 1)
					{
						temp._day = 29;
						temp._month--;
					}
					else
					{
						temp._day--;
					}
	return temp;
}

bool Date::operator<(const Date& ntn)
{
	if (_year < ntn._year)
		return true;
	else
		if (_year == ntn._year)
		{
			if (_month < ntn._month)
				return true;
			else
				if (_month > ntn._month)
					return false;
				else
				{
					if (_month == ntn._month)
					{
						if (_day < ntn._day)
							return true;
						else
							return false;
					}
				}
		}
		else
			return false;

}
bool Date::operator<=(const Date& ntn)
{
	if (_year > ntn._year)
		return false;
	else
		if (_year < ntn._year)
			return true;
		else
			if (_year == ntn._year)
			{
				if (_month > ntn._month)
					return false;
				else
					if (_month < ntn._month)
						return true;
					else
					{
						if (_day <= ntn._day)
							return true;
						return false;
					}
			}
}
bool Date::operator>(const Date& ntn)
{
	if (_year > ntn._year)
		return true;
	else
		if (_year == ntn._year)
		{
			if (_month > ntn._month)
				return true;
			else
				if (_month < ntn._month)
					return false;
				else
				{
					if (_month == ntn._month)
					{
						if (_day > ntn._day)
							return true;
						else
							return false;
					}
				}
		}
		else
			return false;

}
bool Date::operator>=(const Date& ntn)
{
	if (_year < ntn._year)
		return false;
	else
		if (_year > ntn._year)
			return true;
		else
			if (_year == ntn._year)
			{
				if (_month < ntn._month)
					return false;
				else
					if (_month > ntn._month)
						return true;
					else
					{
						if (_day >= ntn._day)
							return true;
						return false;
					}
			}
}

bool Date::operator!=(const Date& ntn)
{
	if (_day != ntn._day || _month != ntn._month || _year != ntn._year)
	{
		return true;
	}
	return false;
}

istream& operator>>(istream& is, Date& ntn)
{
	char c;
	is >> ntn._day >> c >> ntn._month >> c >> ntn._year;
	return is;
}
ostream& operator<<(ostream& os, const Date& ntn)
{
	if (ntn._day < 10)
		os << "0" << ntn._day;
	else
		os << ntn._day;
	os << "/";
	if (ntn._month < 10)
		os << "0" << ntn._month;
	else
		os << ntn._month;
	os << "/" << ntn._year;
	return os;
}

int Date::DateTrue()
{
	int namNhuan = 0;
	if (_year <= 0)
		return 0;
	if (_month <= 0 || _month > 12)
		return 0;
	if (_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0))
		namNhuan = 1;
	if (_day <= 0 || _day > 31)
		return 0;
	switch (_month)
	{
	case 2:
	{
		if (namNhuan == 1 && _day > 29)
			return 0;
		else
			if (namNhuan == 0 && _day > 28)
				return 0;
		break;
	}
	case 4: case 6: case 9: case 11:
	{
		if (_day > 30)
			return 0;
		break;
	}
	default:
		break;
	}
	return 1;
}

void sortDate(Date* date, int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
			if ((date[i] < date[j]) == true)
			{
				Date temp = date[i];
				date[i] = date[j];
				date[j] = temp;
			}
	}
}
