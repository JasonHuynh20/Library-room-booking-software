#include "Date.h"

int MAX_DURATION = 3;

const std::string Date::months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const std::string Date::smonths[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};

//constructors
Date::Date(){
	setDate(1901,1,1, 1, 1);
}

Date::Date(int y, int m, int d, int h, int dur){
	setDate(y,m,d,h,dur);
}


//setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setHour(int h){
	if(h < 0){
		hour = 0;
		return;
	}else if(h > 23){
		hour = 23;
		return;
	}
	hour = h;
}

void Date::setDuration(int d){
	if( d < 1){
		duration = 1;
		return;
	}

	if(d > MAX_DURATION){
		duration = MAX_DURATION;
		return;
	}

	duration = d;
}

void Date::setDate(int y, int m, int d, int h, int dur){
	setMonth(m);
	setDay(d);
	setYear(y);
	setHour(h);
	setDuration(dur);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}


//getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
const string& Date::getMonthName(){return months[month-1];}


//other

bool Date::lessThan(Date& d){
	if (year == d.year){
		if (month == d.month){
			if(day == d.day){
				return hour < d.hour;
			}else{
				return day < d.day;
			}
		}else{
			return month  < d.month;
		}
	}else{
		return year < d.year;
	}
}

void Date::print(){
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear()<<endl;
}

int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

bool Date::overlaps(Date& d){
	if (year != d.year or month != d.month or day != d.day) {
		return false;
	}

	int range = hour + duration;
	if (range <= d.hour or d.hour + d.duration <= hour) {
		return false;
	}

	return true;
}
