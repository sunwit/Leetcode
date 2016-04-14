#include<stdio.h>
#include<stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int reverse(int x){
    int y = 0;
    int n;
    while(x)
    {
       n = x%10;
       if(y > INT_MAX/10 || y < INT_MIN/10){
         return 0;
       }
       y = y*10 + n;
       x = x/10;
    }
    return y;
}

#define TEST(n,e) printf("%12d => %-12d   %s!\n", n, reverse(n), e==reverse(n)?"passed":"failed")


int main(int argc, char **argv)
{
     TEST(123, 321);
     TEST(-123, -321);
     TEST(-100, -1);
     TEST(1002, 2001);


     TEST(1463847412, 2147483641);
     TEST(-2147447412, -2147447412);
     TEST(2147447412,2147447412);
     

     TEST(1000000003, 0);
     TEST(2147483647,0);
     TEST(-2147483647,0);

     if(argc<2)
       return 0;
     else
       {
          printf("\n");
          for(int i = 1; i<argc; i++)
             {
                int n = atoi(argv[i]);
               printf("%12d => %-12d  %s!\n", n, reverse(n), reverse(reverse(n))==n?"passed":"failed");
             }
       }
       return 0;
}
