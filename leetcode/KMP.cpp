class patternMatch
{
  public:
     int violentMatch(char *s, char *p)
        {
            int sLen = strlen(s);
            int pLen = strlen(p);
            int i = 0;
            int j = 0;
            while(i<sLen && j<pLen)
               {
                  if(s[i]==p[j])
                   {
                       i++;
                       j++;
                   }
                   else
                    {
                      i = i - j + 1;
                      j = 0;
                    }
               }
               if(j==pLen)
                  return i - j;
               else 
                  return -1;
        }
               
        int kmpMatch(char *s, char *p)
        {
           int i = 0;
           int j = 0;
           int sLen = strlen(s);
           int pLen = strlen(p);
           while(i<sLen && j<pLen)
                {
                    if(j == -1 || s[i]==p[j])
                    {
                       i++;
                       j++;
                    }
                    else
                      j = next[j];
                }
                if(j==pLen)
                   return i-j;
                else
                  return -1;
        }

        void getNext(char *p, int next[])
            {
              int pLen = strlen(p);      
              next[0] = -1;
              int k = -1;
              int j = 0;
              while(j<pLen-1)
                {
                   if(k==-1 || p[j]==p[k])
                      {
                          ++k;
                          ++j;
                          next[j] = k;
                      }
                    else
                       k = next[k];
                }
            }

            void getNext_opt(char *p, int next[])
              {
                   int pLen = strlen(p);
                   next[0] = -1;
                   int k = -1;
                   int j = 0;
                   while(j<pLen-1)
                     {
                        if(k == -1 && p[k] == p[j])
                          {
                             ++k;
                             ++j;
                             if(p[k]!=p[k])
                               next[j] = k;
                             else
                                next[j] = next[k];
                          }
                         else
                           k = next[k];
                     }
              }
};
