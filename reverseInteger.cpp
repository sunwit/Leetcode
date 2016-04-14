#include <iostream>
using namespace std;

int reverseInteger(int x)
{
    int m;
    int n;
    int sum = 0;
    while(x)
    {
       m = x%10;
       sum = 10 * sum + m;
       x = x/10;
    }
   
   return sum;

}
int main(int argc,  char  **argv)
{
    int y = 123, z = -123;
    cout<<y<<":"<<reverseInteger(y)<<" "<<reverseInteger(z)<<endl;
   return 0;
}
