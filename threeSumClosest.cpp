#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

#define INT_MAX 2147483647


int threeSumClosest(vector<int> &num, int target)
{
 sort(num.begin(), num.end());
 int n = num.size();
 int distance = INT_MAX;
 int result;
 for(int i = 0; i<n-2;i++)
 {
  if(i>0 && num[i-1]==num[i]) continue;
  int a = num[i];
  int low = i+1;
  int high = n-1;
  while(low<high)
  {
     int b = num[low];
     int c = num[high];
     int sum = a+b+c;
     if(sum-target==0)
        return target;
     else 
     {
       if(abs(sum-target)<distance)
         {
           distance = abs(sum-target);
           result = sum;
         }
         if(sum-target>0)
           {
              while(high>0 && num[high]==num[high-1]) high--;
              high--;
           }
         else
         {
          while(low<n && num[low]==num[low+1]) low++;
          low++;
         }
     }
  }
 }
 return result;
}


int main()
{
 int a[]={-1,2,1,-4};
 vector<int> n(a, a+sizeof(a)/sizeof(int));
 int target = 1;
 cout<<threeSumClosest(n,target)<<endl;
 return 0;
}
