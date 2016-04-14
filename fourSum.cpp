#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector< vector<int> > threeSum(vector<int> num, int target)
{
   vector< vector<int> > result;
   sort(num.begin(),num.end());
   int n = num.size();
   for(int i = 0; i<n-2;i++)
   {
     if(i>0 && num[i]==num[i-1]) continue;
     int a = num[i];
     int low = i+1;
     int high = n-1;
     while(low<high)
     {
       int b = num[low];
       int c = num[high];
       if(a+b+c==target)
       {
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        result.push_back(v);
        while(low<n && num[low]==num[low+1]) low++;
        low++;
        while(high>0 && num[high]==num[high-1]) high--;
        high--;
       }
       else if(a+b+c > target)
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
   return result;
}

vector< vector<int> > fourSum(vector<int> &num, int target)
{
  vector< vector<int> > result;
  if(num.size()<4) return result;
  sort(num.begin(),num.end());
  for(int i=0; i<num.size()-3;i++)
  {
   if(i>0 && i<num[i-1]==num[i]) continue;
   vector<int> n(num.begin()+i+1,num.end());
   vector< vector<int> > ret = threeSum(n, target-num[i]);
   for(int j = 0; j<ret.size();j++)
   {
    ret[j].insert(ret[j].begin(),num[i]);
    result.push_back(ret[j]);
   }
  }
  return result;
}  


int printMatrix(vector< vector<int> > &vv)
{
 for(int i = 0; i<vv.size();i++)
 {
   cout<<"[";
   for(int j=0;j<vv[i].size();j++)
   cout<<" "<<vv[i][j];
   cout<<"]"<<endl;
 }
 return 0;
}


int main()
{
 int a[] = {1,0,-1,0,-2,2};
 vector<int> n(a, a+6);
 int t = 0;
 vector< vector<int> > v = fourSum(n,t);
 printMatrix(v);

 n.clear();
 cout<<endl;
 int b[]={-1,-5,-5,-3,2,5,0,4};
 n.insert(n.begin(),b,b+8);
 t = -7;
 v = fourSum(n,t);
 printMatrix(v);
 return 0;
}






