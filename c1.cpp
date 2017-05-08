
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

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
//	~Date() ;
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
  // compute the day code
    static void print( int yr, ostream& out); // print the calendar for entire year
	static bool isLeap(int yr) ;
	static  int dayCode(int yr ) ;


	static Date & toDate(int yr, int dayOfyear) ;

	char *str() ;  // in "mm/dd/yyyy"  format
	string toString() ;  // Sat Aug 05 2006  format
   

	static void print( int year, int mon, ostream & out) ; // print the calendar for the given 
	                                       // month of the given yearr

friend ostream & operator <<(ostream & out , Date& rhs ) ;
friend istream& operator>>(istream & in , Date &rhs) ;


};


int Date::getYear()
{
    return *year;

}
int Date::getMonth()
{
    return *month;

}
int Date::getDay()
{
    return *day;

}

Date::Date()
{
    year = new int(1);
    month = new int(1);
    day = new int(1);
    doy = new int(1);
   
}


Date::Date(int yr, int mon, int day1 )
{
    year = new int(yr);
    month = new int(1);
    day = new int(1);
    
}

Date::Date(Date &other) {
	 year = new int(other.getYear());
    month = new int(other.getMonth());
    day = new int(other.getDay());
    
	
}

Date & Date::operator=(Date & rhs)
{  
    if (this != &rhs)
    {                         
    *year = rhs.getYear();
    *month = rhs.getMonth();
    *day = rhs.getDay();
    }
    else
        return *this;
}

int Date::dayOfYear()
{
	return ( *year + ( *year - 1 ) / 4 - ( *year - 1 ) / 100
            + ( *year - 1 ) / 400 ) % 7;
}


bool isLeap(int yr)
  {
  	 return yr % 4 == 0 && yr % 100 != 0
          || yr % 400 == 0;
  	
 }
 int dayCode(int yr ) 
 {
 		return ( yr + ( yr - 1 ) / 4 - ( yr - 1 ) / 100
            + ( yr - 1 ) / 400 ) % 7;
 }
 
Date getCurrentDate() {

 time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;

}

void open_or_die( ofstream& out );
void print_calendar( int year, ofstream& out );
void print_month_calendar( int year,int month, ofstream& out );
void Holidays(int year,ofstream& out);      
int get_day_code( int year );
bool get_leap_code( int year );



void Date:: print( int yr, ostream& out) { 

   int day_code, month, day, days_in_month;
   bool leap_code;
   int year=yr;
   out << year;

   // get_day_code returns the day on which January
   // 1 of year begins. The return value is coded
   // as: 0 is Sunday, 1 is Monday, and so on.
   day_code = get_day_code( year );

   // get_leap_code returns true, if year is a
   // leap year; and false, otherwise.
   leap_code = get_leap_code( year );
   
 

   // month is coded as 1 for Jan, 2 for Feb,
   // and so on.
   for ( month = 1; month <= 12; month++ ) {
      // print name and set days_in_month
      switch ( month ) {
      case 1:
         out << "\n\nJanuary";
         days_in_month = 31;
         break;
      case 2:
         out << "\n\nFebruary";
         if ( leap_code )
            days_in_month = 29;
         else
            days_in_month = 28;
         break;
      case 3:
         out << "\n\nMarch";
         days_in_month = 31;
         break;
      case 4:
         out << "\n\nApril";
         days_in_month = 30;
         break;
      case 5:
         out << "\n\nMay";
         days_in_month = 31;
         break;
      case 6:
         out << "\n\nJune";
         days_in_month = 30;
         break;
      case 7:
         out << "\n\nJuly";
         days_in_month = 31;
         break;
      case 8:
         out << "\n\nAugust";
         days_in_month = 31;
         break;
      case 9:
         out << "\n\nSeptember";
         days_in_month = 30;
         break;
      case 10:
         out << "\n\nOctober";
         days_in_month = 31;
         break;
      case 11:
         out << "\n\nNovember";
         days_in_month = 30;
         break;
      case 12:
         out << "\n\nDecember";
         days_in_month = 31;
         break;
      }

      out << "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n";

      // advance to correct position for first day
      for ( day = 1; day <= day_code * 5; day++ )
         out << " ";

      // print the dates for one month
      for ( day = 1; day <= days_in_month; day++ ) {
         // field width is 3 because day names
         // are 3 characters.
         out << setw( 3 ) << day;
         if ( ( day + day_code ) % 7 > 0 ) // before Sat?
            // move 2 spaces to next day in same week.
            // (2 spaces separate the day names.)
            out << "  ";
         else  // skip to next line to start with Sun
            out << endl;
      }

      // set day_code for next month to begin
      day_code = ( day_code + days_in_month ) % 7;
   }
}


int get_day_code( int year ) {
   return ( year + ( year - 1 ) / 4 - ( year - 1 ) / 100
            + ( year - 1 ) / 400 ) % 7;
}

// get_leap_code returns true, if the specified
// year is a leap year; and false, otherwise.
bool get_leap_code( int year ) {
   return year % 4 == 0 && year % 100 != 0
          || year % 400 == 0;
}


void open_or_die( ofstream& out ) {
   out.open( "calendar.dat" );
   if ( !out ) {
      cerr << "Unable to open calendar.dat" << endl;
      exit( EXIT_FAILURE );
   }
}






void Holidays(int yr,ofstream& out){
	
	int daysInMonth[2][13] = { { 0,31,28,31,30,31,30,31,31,30,31,30,31} ,
							{ 0,31,29,31,30,31,30,31,31,30,31,30,31} };
	
out<<endl;out<<endl;
out<<"\t\t\tHOLIDAYS                               ";
out<<endl;
out<<"*************************************************************";
out<<endl;	
out<<"\tNew year                   -  ";
int day = get_day_code( yr );
    int result = day;
 out<<"1"<<"/"<<"1"<<"/"<<yr;
out<<endl;

out<<"\tMartin Luther King Birthday-  "; 
int days = get_day_code( yr );
     result = 0;
    if(days>1)
        result=1+2*7+7-days+1;
    else
        result=1+7*2+1-days;

    
out<<"1"<<"/"<<result<<"/"<<yr; out<<endl;
out<<"\tvalentine day              -  "; 
  out<<"2"<<"/"<<"14"<<"/"<<yr; out<<endl;

out<<"\tPresident Day              -  ";
   int p;
    result = (get_day_code(yr) + 31)%7 ;
    if(result>1)
        p=1+2*7+7-result+1;
    else
        p=1+7*2+1-result;

out<<"2"<<"/"<<p<<"/"<<yr; out<<endl;


out<<"\tStPatrikDay                -  ";
out<<"3"<<"/"<<17<<"/"<<yr; out<<endl;

out<<"\tAprilFool                  -  ";
out<<"4"<<"/"<<"1"<<"/"<<yr; out<<endl;

out<<"\tMother Day                 -  ";
    int leap = get_leap_code(  yr );
    day = 0, days = 0;
    for (int i = 1; i<5; i++)
        days += daysInMonth[leap][i];
     int M;
    result = ( get_day_code(yr)+days) % 7;
    if(result>0)
        M=1+7+7-result;
    else
        M=8;

   out<<"5"<<"/"<<M<<"/"<<yr; out<<endl;


out<<"\tMemorial Day               -  ";
  leap = get_leap_code(  yr );
     day = 0, days = 0;
    for (int i = 1; i<6; i++)
        days += daysInMonth[leap][i];
    int m;
    result = (get_day_code(yr) + days-1) % 7; //31st may
    if(result>1)
        m=31-(result-1);
    else
        m=31-(6+result);
    

out<<"5"<<"/"<<m<<"/"<<yr; out<<endl;


out<<"\tFather Day                 -  ";
     leap = get_leap_code(  yr );
     day = 0, days = 0;
    for (int i = 1; i<6; i++)
        days += daysInMonth[leap][i];
    int  F;
    result = (get_day_code(yr) + days) % 7;
    if (result> 0)
        F = 1+7*2+7-result;
    else 
        F = 1+7*2;
    


out<<"6"<<"/"<<F<<"/"<<yr; out<<endl;

out<<"\tIndependence Day           -  ";
    

out<<"7"<<"/"<<"4"<<"/"<<yr; out<<endl;

out<<"\tLabor Day                  -  ";
     leap = get_leap_code(  yr );
     day = 0, days = 0;
    for (int i = 1; i<9; i++)
        days += daysInMonth[leap][i];
    int  L;
    result = (get_day_code(yr) + days) % 7;
    if(result>1)
        L=1+7-result+1;
    else
        L=1+1-result;

    

out<<"9"<<"/"<<L<<"/"<<yr; out<<endl;

out<<"\tColumbus Day               -  ";
    leap = get_leap_code(  yr );
    day = 0, days = 0;
    for (int i = 1; i<10; i++)
        days += daysInMonth[leap][i];
    result = (get_day_code(yr)+days ) % 7;
    int C = 0;
    if(result>1)
        C=1+7+7-result+1;
    else
        C=1+7+1-result;

    

out<<"10"<<"/"<<C<<"/"<<yr; out<<endl;

out<<"\tHalloween Day              -  ";
       
out<<"11"<<"/"<<1<<"/"<<yr; out<<endl;
out<<"\tElection Day               -  ";
    leap = get_leap_code(  yr );
     day = 0, days = 0;
    for (int i = 1; i<11; i++)
        days += daysInMonth[leap][i];
     result = (get_day_code(yr) + days) % 7;
    int E = 0;
    if(result>1)
        E=1+7-result+2;
    else
        E=1+2-result;



out<<"11"<<"/"<<E<<"/"<<yr; out<<endl;

out<<"\tVeterans Day               -  ";
out<<"11"<<"/"<<"11"<<"/"<<yr; out<<endl;

out<<"************************************************************";
out<<endl;

	
}

void print_month_calendar( int year,int month, ofstream& out ) {
   int day_code, Month=month, day, days_in_month;
   bool leap_code;
   out << year<<endl;
   out<<month;

   // get_day_code returns the day on which January
   // 1 of year begins. The return value is coded
   // as: 0 is Sunday, 1 is Monday, and so on.
 day_code = get_day_code( year );
   
   // get_leap_code returns true, if year is a
   // leap year; and false, otherwise.
   leap_code = get_leap_code( year );

   // month is coded as 1 for Jan, 2 for Feb,
   // and so on.
   
  

for ( Month = 1; Month <= 12; Month++ ) {
	
	if(Month<=month){
	
      // print name and set days_in_month
    
      // print name and set days_in_month
      switch ( Month ) {
      case 1:
         out << "\n\nJanuary";
         days_in_month = 31;
         break;
      case 2:
         out << "\n\nFebruary";
         if ( leap_code )
            days_in_month = 29;
         else
            days_in_month = 28;
         break;
      case 3:
         out << "\n\nMarch";
         days_in_month = 31;
         break;
      case 4:
         out << "\n\nApril";
         days_in_month = 30;
         break;
      case 5:
         out << "\n\nMay";
         days_in_month = 31;
         break;
      case 6:
         out << "\n\nJune";
         days_in_month = 30;
         break;
      case 7:
         out << "\n\nJuly";
         days_in_month = 31;
         break;
      case 8:
         out << "\n\nAugust";
         days_in_month = 31;
         break;
      case 9:
         out << "\n\nSeptember";
         days_in_month = 30;
         break;
      case 10:
         out << "\n\nOctober";
         days_in_month = 31;
         break;
      case 11:
         out << "\n\nNovember";
         days_in_month = 30;
         break;
      case 12:
         out << "\n\nDecember";
         days_in_month = 31;
         break;
      }
      
     
      
      out << "\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n";

      // advance to correct position for first day
      for ( day = 1; day <= day_code * 5; day++ )
         out << " ";

      // print the dates for one month
      for ( day = 1; day <= days_in_month; day++ ) {
         // field width is 3 because day names
         // are 3 characters.
         out << setw( 3 ) << day;
         if ( ( day + day_code ) % 7 > 0 ) // before Sat?
            // move 2 spaces to next day in same week.
            // (2 spaces separate the day names.)
            out << "  ";
         else  // skip to next line to start with Sun
            out << endl;
      }

      // set day_code for next month to begin
       day_code = ( day_code + days_in_month ) % 7;
   }
   
}
}






menu (){
	cout <<"\n\tOptions:";
	cout <<"\n\tEnter 1 to print calendar for whole year";
	cout <<"\n\tEnter 2 to print calendar for a given month of a given year";
	cout <<"\n\tEnter 3 to print the important dates of a given year";
	cout <<"\n\tEnter 4 to quit";
	cout <<"\n\n\tPlease enter your choice: ";
}



int main() {

	ofstream outfile;
	string choice = "", cont = "y";
	int option=0;
	int month, year;
	do{
			
	menu ();
	cin >> option;
	if (option == 1){
	       	open_or_die( outfile );
	
		cout << "\n\tPlease Enter the year (XXXX): ";
		cin >> year;
	
		cout << "\n\tDo you want to write a file too? ";
		cin >> choice;
		if (choice == "y" || choice == "Y" || choice == "yes"|| choice == "Yes" || choice == "YES"){
			
		}
		cout << "Calendar " << year << endl;
		
		Date:: print(  year,outfile);
	
		
		
	
		
	}
	else if (option == 2){
		
			 open_or_die( outfile );
		cout << "\n\tPlease enter 1 for a single month ";
		cout << "\n\t             2 for a calendar year ";
		cout << "\n\tPlease enter your choice: ";
		cin >> option;
		cout << "\n\tDo you want to write a file too? ";
		cin >> choice;
		if (choice == "y" || choice == "Y" || choice == "yes"|| choice == "Yes" || choice == "YES"){
			
		}
		cout << "\n\tPlease Enter the year (XXXX) and month(1-12): ";
		cin >> year >> month;
		
		cout << "Calendar " << year << endl;
	
         print_month_calendar( year,month, outfile );
               
                
		
	}
	else if (option == 3){
		
			open_or_die( outfile );
		cout << "\n\tPlease Enter the year (XXXX): ";
		cin >> year;
		
		cout << "\n\tDo you want to write a file too? ";
		cin >> choice;
		if (choice == "y" || choice == "Y" || choice == "yes"|| choice == "Yes" || choice == "YES"){
			
		}
		cout << "The important dates for the year " << year << endl;
		
	        Holidays(year,outfile);  
	}
	else if (option == 4){
		exit (EXIT_FAILURE);
		
	}
	cout << "Do you want to continue for another run? ";
	cin >> cont;
	}while (cont == "y" || cont == "Y" || cont == "yes"|| cont == "Yes" || cont == "YES");
   
   
                        


   
	
  
   return 0;
}



