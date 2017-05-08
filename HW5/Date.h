#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;
	  static const char*Monthname[]= {"","Jan","FEB","MAR","APR", "MAY", "JUN","JUL",
		"AUG", "SEP","OCT", "NOV","DEC"};
	   static const char*dayOfWeek[] = {"Sun","Mon","Tue","Wed","Thu","Fri", "Sat"} ;
	   static const int days[2][13]= { {0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31} } ;
class Date{

private:
	int *year;
	int *month ;
	int *day;
	int *doy   ;   // day of year

public:
	int getYear() ;
	int getMonth() ;
	int getDay() ;
	static Date getCurrentDate() ;
	Date() ;  // set to current day 
	
	Date(int yr, int mon= 1, int day = 1) ;
	Date(Date&other) ;
	int dayOfYear() ;
	Date & operator =(Date & rhs) ;
	~Date() ;
	int operator-(Date & rhs) ;  // returns difference in number of days
	Date & operator+(int n) ;  // n can be either positive or negative
	Date & operator++() ; // prefix
	Date& operator++(int) ;  // postfix
	Date & operator--() ;  // prefix
	Date & operator --(int) ;  // postfix
	bool operator>(Date & rhs) ;   // newer
	bool operator >= (Date & rhs) ;
	bool operator<(Date & rhs) ;  // older
	bool operator <=(Date & rhs) ;
	bool operator==(Date & rhs) ;
	static int isLeap(int yr) ;
	static  int dayCode(int yr, int mon  , int day ) ;  // compute the day code



	static Date & toDate(int yr, int dayOfyear) ;

	char *str() ;  // in "mm/dd/yyyy"  format
	string toString() ;  // Sat Aug 05 2006  format
    static void print( int yr, ostream & out = cout); // print the calendar for entire year

	static void print( int year, int mon, ostream & out = cout) ; // print the calendar for the given 
	                                       // month of the given yearr

friend ostream & operator <<(ostream & out , Date& rhs ) ;
friend istream& operator>>(istream & in , Date &rhs) ;


};


#endif