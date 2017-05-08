// This program prints a calendar for a year.
// The user enters the year, after which
// the year and calendar are printed to the
// file calendar.dat.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
void open_or_die( ofstream& out );
void print_calendar( int year, ofstream& out );
int get_day_code( int year );
bool get_leap_code( int year );

int main() {
   ofstream outfile;
   open_or_die( outfile );
   int year;
   cout << "Enter the year: ";
   cin >> year;
   print_calendar( year, outfile );
   return 0;
}

void open_or_die( ofstream& out ) {
   out.open( "calendar.dat" );
   if ( !out ) {
      cerr << "Unable to open calendar.dat" << endl;
      exit( EXIT_FAILURE );
   }
}

// print_calendar prints the calendar specified
// by parameter year to the output file specified
// by parameter out.
void print_calendar( int year, ofstream& out ) {
   int day_code, month, day, days_in_month;
   bool leap_code;
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

// get_day_code returns the day on which January
// 1 of the specified year begins. The return
// value is coded as: 0 is Sunday, 1 is Monday,
// and so on.
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