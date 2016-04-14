#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX-1)

int myatoi(const char *str){
    if(str==NULL || *str == '\0')
         return 0;
    int ret = 0;
    for(;isspace(*str); str++);
    bool neg = false;
    if(*str=='-' || *str=='+'){
       neg = (*str=='-');
       str++;
    }
    for(;!isdigit(*str);str++);
    for(;isdigit(*str);str++)
    {
       int digit = (*str-'0');
       if(neg)
       {
         if(-ret < (INT_MIN + digit)/10)
             return INT_MIN;
        }
         else if(ret>(INT_MAX-digit)/10)
         {
          return INT_MAX;
         }
       ret = 10*ret+digit;
    }
    return neg?-ret:ret;
}


int main(){
     printf("\"%s\" = %d\n", "123", myatoi("123"));
     printf("\"%s\" = %d\n", "   123", myatoi("   123"));
     printf("\"%s\" = %d\n", "+123", myatoi("+123"));
     printf("\"%s\" = %d\n", "123ABC", myatoi("123ABC"));
     printf("\"%s\"= %d\n", " abc123ABC", myatoi(" abc123ABC"));
     printf("\"%s\" = %d\n", "2147483647", myatoi("2147483647"));
     printf("\"%s\" = %d\n", "-2147483648", myatoi("-2147483648"));
     printf("\"%s\" = %d\n", "2147483648", myatoi("2147483648"));
     printf("\"%s\" = %d\n", "-2147483649", myatoi("-2147483649"));
     return 0;
}
