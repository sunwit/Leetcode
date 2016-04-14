#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector< vector<int> > threeSum(vector<int> &num)
{
   vector< vector<int> > result;
   sort(num.begin(), num.end());
   int n = num.size();
   for(int i = 0;i<n-2;i++)
   {
   if(i>0 && num[i-1]==num[i]) continue;
   int a = num[i];
   int low = i+1;
   int high = n-1;
   while(low < high)
   {
     int b = num[low];
     int c = num[high];
     if(a+b+c==0)
     {
      vector<int> v;
      v.push_back(a);
      v.push_back(b);
      v.push_back(c);
      result.push_back(v);
      while(low<n-1 && num[low]==num[low+1]) low++;
      while(high>0 && num[high]==num[high-1]) high--;
      low++;
      high--;
     }
     else if (a+b+c>0)
     {
       while(high>0 && num[high]==num[high-1]) high--;
          high--;
     }
     else{
       while(low<n-1 && num[low]==num[low+1]) low++;
          low++;
     }
   }
   }
   return result;
}

void printMatrix(vector< vector<int> > &matrix)
{
   for(int i = 0; i<matrix[i].size();i++)
   {
     printf("{");
     for(int j=0; j<matrix[i].size();j++)
        printf("%3d", matrix[i][j]);
     printf("}\n");
   }
   cout<<endl;
}
 

int main()
{
int a[]={-1,1,1,1,-1,-1,0,0,0};
vector<int> n(a, a+sizeof(a)/sizeof(int));
vector< vector<int> > result = threeSum(n);
printMatrix(result);
return 0;
}

