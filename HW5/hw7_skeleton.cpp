#include <iostream>
#include <string>
#include <iomanip>
#include "Date.h"
#include <fstream>

using namespace std;

void app1() ;
void app2() ;
void print_calendar( int year );
char *major[]={"New Year Day","MLK Birthday","Valentine's Day","President Day","St.Patrick's Day","April Fools","May Day","Mother's Day",
	"Memorial Day","Father's Day","Independence Day","Labor Day",
	"Columbus Day","Halloween","Election Day", "Veterans Day","Thanksgiving Day", "Christmas"};
char * dayofweek[] = {"Sunday", "Monday", "Tuesday","Wednesday", "Thursday", "Friday", "Saturday"};

void print_calendar( int year, ostream &out );


void menu() {
	cout << "\n\t\tType 1 for major holidays ";
	cout << "\n\t\tType 2 for Calendar  ";
	cout <<"\n\t\tType 3 to quit.";
	cout << "\n\n\t\tPlease enter your choice :";;
		
}
int main() {
	
	int choice ;
	cout << endl << endl << "\tWelcome to CSC404  Holidays/  Calendar System: \n\n";
	while (true) {
		menu() ;
		cin >> choice ;

		switch(choice) {
		case 1:  app1() ; break ;
		case 2 : app2() ; break ;
		case 3: break ;
		default:  cout << "\n\n\t\tInvalid choice \n"; break;
		} 
		if ( choice == 3 ) break ;

	}

	cout << "\n\n\tThank you for using U.S. Major Holidays Calendar System! \n";
	cout << "\n\n\t\tBye! \n\n";
	return 0 ;
}




///////////////////////////////
Date NewYear(int yr) {
	Date tmp(1,1,yr) ;
	return tmp ;
}
// MLK day third monday of January
Date MLKDay(int yr) {

// put your code here
}

Date Valentine(int yr) {
	return Date(2,14,yr) ;
}

Date PresidentDay(int yr) {  // 3rd monday of Febraury

// put your code here

}
Date StPatrick(int yr) {  //mar 17

	Date temp(3,17,yr) ;
	return temp;
}

Date AprilFool(int yr){
	return Date(4,1,yr) ;
}

Date MayDay(int yr) {  // May ist
	Date tmp(5,1,yr) ;
	return tmp ;
} 
Date MotherDay(int yr) {  // 2nd sunday in may
// put your code here

}
Date MemorialDay(int yr) {  
// function that returns a Date object which is the date for Memoriial day of year yr

// put your code here

}

Date FatherDay(int yr) {  // 3rd sunday in June
// put your code here
}

Date IndependenceDay(int yr) {  // July 4

	Date tmp(7,4,yr) ;
	return tmp;
}


Date Labor(int yr) {
	
// function that returns a Date object which is the date for Labor day of  the year yr
// put your code here
}

Date Columbus(int yr) {  // second monday of october

// put your code here
}

Date Halloween(int yr) {
	Date tmp(11,1,yr) ;    // november 1st, a day after Halloween
	return --tmp  ;
}
Date ElectionDay(int yr) {  // 1st tuesday after 1st monday in november
// put your code here
}

 Date VeteransDay(int yr ) {    // Nov 11

	Date temp(11,11,yr) ;
	return temp;

}

 Date thanksgiving (int yr) {
// function that returns a Date object which is the date for Thanksgiving of the year yr
//  the fourth thursday of Novemeber


// put your code here
}

 Date xmas(int yr) {
	 return Date(12,25,yr) ;
 }


 // an array of  function pointers
Date   (*fp[18])(int)= { NewYear, MLKDay,Valentine,PresidentDay,StPatrick,AprilFool,MayDay,MotherDay,MemorialDay,
                           FatherDay,IndependenceDay,Labor,Columbus, Halloween,ElectionDay,VeteransDay,thanksgiving,xmas } ; 


void process(   Date (*fun)(int), int yr, int index){

	Date d = fun(yr) ;


	// put your code here
}


void app1() {

	
	int yr ;

	while(true) {

		cout << "\tPlease enter the year (4 digits) or -1  to quit: " ;
		cin >> yr ;
		if ( yr < 0 ) break ;
		cout <<  "\n\n\t\tMajor holidays for year " << yr << endl << endl;


		for (int i = 0 ; i < 18 ; i++ ) process(fp[i],yr,i) ;

		cout << endl << endl;
	}

}

void app2() {

	
	int yr ;
	char resp[10];
	string filename; 
	ofstream out;

	cout << "\n\tDo your want to write to a file?";
	cin >> resp;

	if ( resp[0] == 'y' || resp[0] == 'Y'){
		cout << "\n\tPlease enter the file name: ";
		cin >> filename;
		filename += ".txt";
		out.open ( filename, ios::app );
	}
	
	while(true) {

		cout << "\tPlease enter the year (4 digits) or -1  to quit: " ;
		cin >> yr ;
		if ( yr < 0 ) break ;
		cout <<  "\n\n\t\tCalendar for year " << yr << endl << endl;

		if ( resp[0] == 'y' || resp[0] == 'Y' ) print_calendar(yr,out) ;
		else print_calendar(yr,cout) ;
		
		cout << endl << endl;
	}
	if (resp[0] == 'y' || resp[0] == 'Y' ) out.close() ;
}

void print_calendar( int year, ostream &out ) {
 // put your code here
}



