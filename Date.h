#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

extern int MAX_DURATION;

using namespace std;

class Date {

	public:
		//constructor
		Date();
		Date(int year, int month, int day, int hour, int duration);

		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setHour(int);
		void setDuration(int);
		void setDate(int y, int m, int d, int h, int dur);
		void setDate(Date&);

		//getters
		int getDay();
		int getMonth();
		int getYear();
		const string& getMonthName();

		//other
		bool lessThan(Date& d);
		void print();
		bool overlaps(Date& d);

	private:
		//functions
		int getMaxDay();

		//variables
		int day;
		int month;
		int year;
		int hour;
		int duration;

		static const string months[12];
		static const string smonths[12];

};
#endif
