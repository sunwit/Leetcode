#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;


int myAtoi(string str){
    int sum = 0;
    int m;
    for(int i = 0; i<str.size();i++)  
    {   
       if('0'<=str[i] && str[i]<='9')
       {
        m = str[i]-'0'; 
        if(sum > (INT_MAX-m)/10 || sum < (INT_MIN+m)/10)
             return 0;
        if(str[0]!='-')
          sum = sum * 10 + m;
        else
          sum = sum * 10 - m;
       }
   }
   return sum;
}

int main(int argc, char **argv)
{
  cout<<"123"<<":"<<myAtoi("123")<<endl;
  cout<<"   123"<<":"<<myAtoi("123")<<endl;
  cout<<"+123"<<":"<<myAtoi("+123")<<endl;
  cout<<"123ABC"<<":"<<myAtoi("123ABC")<<endl;
  cout<<"abc123ABC"<<":"<<myAtoi("abc123ABC")<<endl;
  cout<<"2147483647"<<":"<<myAtoi("2147483647")<<endl;
  cout<<"-2147483647"<<":"<<myAtoi("-2147483647")<<endl;
  cout<<"2147483648"<<":"<<myAtoi("2147483648")<<endl;
  cout<<"-2147483649"<<":"<<myAtoi("-2147483649")<<endl;
  return 0;
}
