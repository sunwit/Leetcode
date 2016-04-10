#include<iostream>

using namespace std;

int jump(int A[], int n)
{
 if(n<=1) return 0;
 int steps = 0;
 int coverPos = 0;
 for(int i = 0; i<=coverPos && i<n;)
 {
  if(coverPos<A[i]+i)
    {
      coverPos = A[i]+i;
      steps++;
    }
    if(coverPos >= n-1)
     {
        return steps;
     }
     int nextPos = 0;
     int maxDistance = 0;
     for(int j = i+1; j<=coverPos;j++)
     {
        if(A[j]+j>maxDistance)
        {
           maxDistance = A[j]+j;
           nextPos = j;
        }
     }
     i = nextPos;
 }
 return steps;
}

void printArray(int a[], int n)
{
  cout<<"{";
  for(int i = 0; i<n;i++)
  {
     if(i) cout<<",";
     cout<<a[i];
  }
  cout<<"}"<<endl;
}

int main(int argc, char **argv)
{
#define TEST(a) printArray(a, sizeof(a)/sizeof(a[0])); cout<<jump(a,sizeof(a)/sizeof(a[0]))<<endl;
int a1[]={0};
TEST(a1);

int a2[]={2,3,1,1,4};
TEST(a2);
return 0;
}
