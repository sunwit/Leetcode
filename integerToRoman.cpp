#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;

string intToRoman(int num){
       string symbol[]={"M", "CM", "D", "CD", "C", "XC", "L","XL", "X", "IX", "V", "IV", "I"};
       int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
       string result;
       for(int i = 0; num!=0; i++)
        {
          while(num>=value[i])
              {
                num = num - value[i];
                result = result + symbol[i];
              }
        }
        return result;
}

int main(int argc ,char** argv)
{
    int num = 1234;
   // if(argc>0)
 //    num = atoi(argv[1]);
    cout<<num<<":"<<intToRoman(num)<<endl;
    return 0;
}
