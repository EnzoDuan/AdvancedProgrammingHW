#pragma once
#include <iostream>
#include <stdio.h>
class Time {
private:
	struct time {
		unsigned int _hour, _minute, _second;
		time() :_hour(0), _minute(0), _second(0) {}
	};
	time *selfTime;
public:
	Time() { selfTime = NULL; }
	Time(unsigned int h, unsigned int m, unsigned int s) {
		selfTime = new time;
		selfTime->_hour = h;
		selfTime->_minute = m;
		selfTime->_second = s;
	}
	~Time() { delete selfTime; }

	bool operator == (const Time& A) const;
	bool operator != (const Time& A) const;
	bool operator >= (const Time& A) const;
	bool operator <= (const Time& A) const;
	bool operator > (const Time& A) const;
	bool operator < (const Time& A) const;

	Time& operator +=(const unsigned int second);
	Time& operator -=(const unsigned int second);
	Time& operator ++();
	Time& operator --();
	void printTime() const;
	friend Time operator -(const Time& t1, const Time& t2);
};

Time operator -(const Time& t1, const Time& t2) {
	return Time(t1.selfTime->_hour - t2.selfTime->_hour,
		t1.selfTime->_minute - t2.selfTime->_minute,
		t1.selfTime->_second - t2.selfTime->_second);
}