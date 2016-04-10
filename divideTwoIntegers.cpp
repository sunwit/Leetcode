#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

#define  INT_MAX 214783647
#define  INT_MIN (-INT_MAX-1)

int divide(int dividend, int divisor)
{
    int sign = (float)dividend/divisor>0?1:-1;
    unsigned int dvd = dividend>0?dividend:-dividend;
    unsigned int dvs = divisor>0? divisor:-divisor;

    unsigned int bit_num[32];
    unsigned int i = 0;
    long long d = dvs;
    bit_num[i]  = d;
    while(d<=dvd)
         bit_num[++i] = d = d<<1;
    i--;

    unsigned int result = 0;
    while(dvd>=dvs)
    {
       if(dvd>=bit_num[i])
          {
            dvd = dvd - bit_num[i];
            result = result + (1<<i);
          }
          else
           i--;
    }
    if(result>INT_MAX && sign>0)
       return INT_MAX;
    else
      return (int)result*sign;
}

int main()
{
 cout<<"0/2="<<divide(0,2)<<endl;
 cout<<"10/2="<<divide(10,2)<<endl;
 cout<<"10/3="<<divide(10,3)<<endl;
 cout<<"10/11="<<divide(10,11)<<endl;
 cout<<"-1/1="<<divide(-1,1)<<endl;
 cout<<"1/-1="<<divide(1,-1)<<endl;
 cout<<"-1/-1="<<divide(-1,-1)<<endl;
 cout<<"2147483647/10="<<divide(2147483647,10)<<endl;
 cout<<"2147483647/1="<<divide(2147483647,1)<<endl;
 cout<<"2147483647/-1="<<divide(2147483647,-1)<<endl;
 cout<<"-2147483647/-1="<<divide(-2147483647,-1)<<endl;
 return 0;
}
