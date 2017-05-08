#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string val;
    cout<<"Enter the String : ";
    cin>>val;
    cout<<endl;
    int i;
    int m=val.length();
    cout<<"length of string is :"<< m<<endl;
    string res[m];
    int n=0;
    
    for(i=1;i<m;i++)
    {
       if(val.at(i-1)>val.at(i))
       {  
	     
		 
	        string temp=val.substr(0,i-1)+val.at(i-1)+val.substr(i+1,m);
	       // cout<<temp<<endl;
	        res[n]=temp;
	        n++;
	     
	   }
	   else{
	   
		 
	        string temp=val.substr(0,i-1)+val.at(i)+val.substr(i+1,m);
	        //cout<<temp<<endl;
	        res[n]=temp;
	        n++;
	     
	   		
	   	
	   }	
	}
    
    for(i=0;i<m;i++)
    { cout<<res[i]<<endl;
	}
	cout<<"After Sorting";
	for(i=0;i<m;i++)
	{
	  for(int j=0;j<m;j++)
       {  if(res[j]>res[j+1])
          { string temp;
             temp=res[j];
             res[j]=res[j+1];
             res[j+1]=temp;
		  }
	    
	   }
   }
   
     
    for(i=0;i<m;i++)
    { cout<<res[i]<<endl;
	}
	
	cout<<"Result is :"<<res[1];
	
    return 0;
}
