// C program for implementation of KMP pattern searching 
// algorithm
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;
void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    // cout<<*lps<<endl;
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      { cout<<j<<" "<<M<<endl;
        cout<<"Found pattern at index "<< i-j<<endl;
        j = lps[j-1];
        ///cout<<"j is "<<j<<endl;
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
        { //cout<<"pre-"<<j<<endl;
		 j = lps[j-1];
		// cout<<"i is "<<i<<"  j is "<<j<<endl;
		}
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // length of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
    
    // the loop calculates lps[i] for i = 1 to M-1
   // cout<<*pat<<endl;
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
       	//cout<<"i="<<i<<" "<<"len="<<len<<endl;
		//cout<<pat[i]<<" "<< pat[len]<<endl;
         len++;
         lps[i] = len;
        cout<<"lps["<<i<<"]--"<<lps[i]<<endl;
         i++;
       }
       else // (pat[i] != pat[len])
       { // cout<<"i="<<i<<" "<<"len="<<len<<endl;
       	  //cout<<"--"<<" "<<pat[i]<<" "<< pat[len]<<endl;
         if (len != 0)
         { 
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
          // cout<<lps[i]<<endl;
          cout<<"lps["<<i<<"]--"<<lps[i]<<endl;
           i++;
         }
       }
    }
}
 
// Driver program to test above function
int main()
{
   char *txt = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
   char *pat = "aaaa";
   KMPSearch(pat, txt);
   return 0;
}
