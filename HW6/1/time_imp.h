#pragma once
#include "time.h"
bool Time::operator == (const Time& A) const {
	return ((this->selfTime->_hour == A.selfTime->_hour)
		&& (this->selfTime->_minute == A.selfTime->_minute)
		&& (this->selfTime->_second == A.selfTime->_second));
}
bool Time::operator != (const Time& A) const {
	return !(*this == A);
}
bool Time::operator >= (const Time& A) const {
	Time ans = (*this - A);
	return (ans.selfTime->_hour >= 0 && ans.selfTime->_minute >= 0 && ans.selfTime->_second >= 0);
}
bool Time::operator <= (const Time& A) const {
	Time ans = (*this - A);
	return (ans.selfTime->_hour <= 0 && ans.selfTime->_minute <= 0 && ans.selfTime->_second <= 0);
}
bool Time::operator > (const Time& A) const {
	return !(*this <= A);
}
bool Time::operator < (const Time& A) const {
	return !(*this >= A);
}

Time& Time::operator +=(const unsigned int second) {
	this->selfTime->_second += second;
	if (this->selfTime->_second >= 60)
	{
		this->selfTime->_second %= 60;
		this->selfTime->_minute++;
		if (this->selfTime->_minute >= 60)
		{
			this->selfTime->_minute %= 60;
			this->selfTime->_hour++;
			this->selfTime->_hour %= 24;
		}
	}
	return *this;
}
Time& Time::operator -=(const unsigned int second) {
	this->selfTime->_second -= second;
	if (this->selfTime->_second < 0)
	{
		this->selfTime->_second += 60;
		this->selfTime->_minute--;
		if (this->selfTime->_minute < 0)
		{
			this->selfTime->_minute = 59;
			this->selfTime->_hour--;
			if (this->selfTime->_hour < 0)
				this->selfTime->_hour = 23;
		}
	}
	return *this;
}
Time& Time::operator ++() {
	if (this->selfTime->_second == 59)
	{
		this->selfTime->_second = 0;
		if (this->selfTime->_minute == 59)
		{
			this->selfTime->_minute = 0;
			this->selfTime->_hour++;
			this->selfTime->_hour %= 24;
		}
		else
			this->selfTime->_minute++;
	}
	else
		this->selfTime->_second++;
	return *this;
}
Time& Time::operator --() {
	if (this->selfTime->_second == 0)
	{
		this->selfTime->_second = 59;
		if (this->selfTime->_minute == 0)
		{
			this->selfTime->_minute = 59;
			if (this->selfTime->_hour == 0)
				this->selfTime->_hour = 23;
			else
				this->selfTime->_hour--;
		}
		else
			this->selfTime->_minute--;
	}
	else
		this->selfTime->_second--;
	return *this;
}
void Time::printTime() const {
	std::cout << selfTime->_hour << "-" << selfTime->_minute << "-" << selfTime->_second << std::endl;
}