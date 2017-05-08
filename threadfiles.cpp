#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include<unistd.h>
#include<string.h>

using namespace std;

#define NUM_THREADS 4
pthread_mutex_t myMutex;
struct thread_data{
int thread_id;
char *message;
};

void open_or_die( ofstream& out );
//void print( ofstream& out );

void *PrintHello(void *threadarg)
{
	pthread_mutex_lock(&myMutex);
struct thread_data *my_data;
my_data = (struct thread_data *) threadarg;
	ofstream out;
	char s1[100];
	cout<<"\n\t enter file name  (FILE NAME SHOULD ENDS WITH .DOCX)   :";
	cin>>s1;
   out.open( s1 );
   
   if ( !out ) {
      cerr << "Unable to open calendar.dat" << endl;
      exit( EXIT_FAILURE );
   }
cout << "\n\tThread ID : " << my_data->thread_id ;
cout << "\n\t Message : " << my_data->message << endl;
   return 0;
  cout << "\n\tPlease Enter the Name: ";
   char name[100];
   cin >> name;
   out<<name;
   out<<endl; 
   cout << "\n\tPlease Enter the course 1: ";
   char name1[100];
   cin >> name1;
   out<<name1;
   out<<endl; 
  
   int year;
   cout << "\n\tPlease Enter the Grade: ";
   int g1;
   cin >> g1;
   out << g1;
   out<<endl; 
   
    cout << "\n\tPlease Enter the course 2: ";
   char name2[100];
   cin >> name2;
   out<<name2;
   out<<endl; 
    
   int g2;
   cout << "\n\tPlease Enter the Grade 2: ";
   cin >>g2 ;
   out << g2;
   out<<endl; 
   
   cout << "\n\tPlease Enter the course 2: ";
   char name3[100];
   cin >> name3;
   out<<name3;
   out<<endl; 
    
   int g3;
   cout << "\n\tPlease Enter the Grade: ";
   cin >>g3 ;
   out << g3;
   out<<endl; 
   
   out << "\n\tAverage Grade: ";
   float avg;
   avg=(g1+g2+g3)/3;

   out<<avg;
   out<<endl;
   if(avg>3.5)
   {
   	out<<"Well Done!!";
   out<<endl;
   }
   else if(avg>3)
   {
   	out<<"Good!!";
   out<<endl;
   }
    else if(avg>2.5)
   {
   	out<<"Ohkk,Not Bad!!";
   out<<endl;
   }
    else if(avg<2.5)
   {
   	out<<"Need to Improve!!";
   out<<endl;
   }
   
  pthread_mutex_unlock(&myMutex);  
}






int main() {
//	ofstream outfile;
//open_or_die( outfile );
	
 pthread_t threads[NUM_THREADS];
struct thread_data td[NUM_THREADS];
pthread_mutex_init(&myMutex,0);
int rc;
int i;
for( i=0; i < NUM_THREADS; i++ ){
cout <<"creating thread, " << i << endl;
td[i].thread_id = i;
td[i].message = "Hi I am New Thrread";
 pthread_create(&threads[i], NULL,PrintHello, (void *)&td[i]);
pthread_join(threads[i], 0); 

    	

	   
}
 pthread_mutex_destroy(&myMutex);
 return 0;
}



