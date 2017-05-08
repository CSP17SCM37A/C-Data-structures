#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
/*Function to return max sum such that no two elements
 are adjacent */
int FindMaxSum(int arr[], int n)
{
  int incl = arr[0];
  int excl = 0;
  int excl_new;
  int i;
 
  for (i = 1; i < n; i++)
  {
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl;
      cout<<"e"<<" "<<excl_new<<"\n";
     /* current max including i */
     incl = excl + arr[i];
     excl = excl_new;
     cout<<"i,c"<<incl<<" "<<excl<<"\n";
  }
 
   /* return max of incl and excl */
   return ((incl > excl)? incl : excl);
}
 
/* Driver program to test above function */
int main()
{
  int arr[] = {5, 6, 10, 100, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("%d \n", FindMaxSum(arr, 6));
  return 0;
}
