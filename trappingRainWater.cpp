#include<stdio.h>

int trap(int a[], int n)
{
  int result = 0;
  int maxHigh = 0;
  int maxIdx = 0;
  for(int i = 0; i<n;i++)
  {
    if(a[i]>maxHigh)
    {
      maxHigh = a[i];
      maxIdx = i;
    }
  }
  
  int prevHigh = 0;
  for(int i = 0; i<maxIdx; i++)
  {
    if(a[i]>prevHigh)
      {
        prevHigh = a[i];
      }
      result = result + (prevHigh - a[i]);
  }

  prevHigh = 0;
  for(int i = n-1; i>maxIdx; i--)
  {
   if(a[i]>prevHigh)
   {
     prevHigh = a[i];
   }
   result = result + (prevHigh - a[i]);
  }
  return result;
}

#define TEST(a) printf("%d\n", trap(a, sizeof(a)/sizeof(int)))

int main(int argc, char **argv)
{
  int a[] = {2,0,2};
  TEST(a);
  int b[]={0,1,0,2,1,0,1,3,2,1,2,1};
  TEST(b);
  return 0;
}

