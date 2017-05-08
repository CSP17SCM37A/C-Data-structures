#include <string>
#include <list>
#include <iostream>

using namespace std;

typedef list<string>::iterator LI;
LI find_person ( list <string>& L, LI& p, const unsigned& M )
{
/*This routine is called 
to locate the M-th name in the list L, and the list iterator p refers to that 
name, where LI is defined as: typedef list <string> :: iterator LI;*/



list <string> q = p; // for debugging purposes only
unsigned i = 1;
cout << "Q" << i << ": " << *q << " ";
while (i < M)
{   
	p++;//iterate through until we've moved M spaces
	q++;
	
	if (p == L.end() && i == 1) //trying to tell it that if it's at a blank space, 
	{p = L.begin();				//and at the beginning of the loop, iterate one more  
	p++;						//time after resetting
	}
	
	else if (p == L.end() && i > 1) //else, just reset it.
		p = L.begin();
		
	cout << "Q" << i << ": " << *q << " ";	
	i++;
}
cout << "Q" << i << ": " << *q << endl;

return p;


}


int main(void){
   list<string> cir;
   cir.push_back("1");
   cir.push_back("2");
   cir.push_back("3");
    cir.push_back("4");
   cir.push_back("5");
   
   
   LI pos1(cir.begin());
   while(1 < cir.size()){
      LI pos2(find_person(cir, pos1, 2));
      cout << "Removing: " << *pos2 << endl;
      pos1 = cir.erase(pos2);
   }
   cout << "Last: " << cir.front() << endl;
   return 0;
}
