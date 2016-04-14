#include<iostream>
#include<stdlib.h>
#include<string>
#define ISMATCH(a,b) (a == b || (a!='\0'&& b == '.'))

using namespace std;

class Solution{
      public:
      bool isMatch(const char *s, const char *p)
        {
        
        if(*p == '\0')
              return *s=='\0';
           if(*(p+1)=='*')
            {
               while(*s != '\0' && (*p == '.' || *s == *p))
                    {
                      if(isMatch(s, p+2))
                         return true;
                       s++;
                    }
                return isMatch(s, p+2);
            }
            else if(*s!='\0' &&(*p == '.' || *s==*p))
                   return isMatch(s+1,p+1);
            return false;
        }
        bool isMatchDp(const char *s, const char *p)
         {
           int m = strlen(s);
           int n = strlen(p);
           bool dp[m][n];
           dp[0][0] = true;
           for(int i =0;i<m;i++)
             dp[i+1][0] = false;
           for(int j = 0;j<n;j++)
             dp[0][j+1] = '*' == p[j] && dp[0][j-1];
           for(int i = 0; i<m; i++)
              for(int j = 0; j< n;j++)
                {
                    if(p[j] != '*')
                       dp[i+1][j+1] = dp[i][j] && (p[j]=='.' || s[i]==p[j]);
                    else
                       dp[i+1][j+1] = dp[i+1][j-1] || dp[i+1][j] || (dp[i][j+1] && (s[i] == p[j-1]||p[j-1]=='.'));
                }
             return dp[m][n];
         }
};

int main(int argc, char **argv)
{
  Solution so;
  const char *s = "aaa";
  const char *p = "a.*";
  if(argc > 2)
    {
       s = argv[1];
       p = argv[2];
    }
    cout << s<<","<<p<<"."<<so.isMatch(s,p)<<". "<<so.isMatchDp(s,p)<<endl;
    return 0;
}

