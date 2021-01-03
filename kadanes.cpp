#include<iostream>
#include<climits>
using namespace std;
int maxSubarraySum(int a[], int size) 
{ 
   int total_max = INT_MIN;   
   int max_now = 0; 
   // Traversing in Array
   for (int i = 0; i < size; i++) 
   {   
        max_now = max(a[i], max_now+a[i]); 
         // Comparing the Current Maximum Sum with Previous One
        total_max = max(total_max, max_now); 
   } 
   return total_max; 
} 
int main()
{
      int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
      int size = sizeof(a)/sizeof(a[0]);
      cout<<"Max Subarray Sum is "<<maxSubarraySum(a,size);
}
