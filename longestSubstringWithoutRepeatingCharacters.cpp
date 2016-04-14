#include <iostream>
#include <map>
using namespace std;

class Solution{
   public:
      int lengthOfLongestSubstring1(string s){
           map<char, int> m;
           int maxlen = 0;
           int lastRepeatPods = -1;
           for(int i = 0; i < s.size(); i++)
              {
                 if(m.find(s[i]) != m.end() && lastRepeatPods < m[s[i]])
                     lastRepeatPods = m[s[i]];
                 if(i - lastRepeatPods > maxlen)
                       maxlen = i - lastRepeatPods;                  
                   m[s[i]] = i;
               }             
      return maxlen;
}
 int lengthOfLongestSubstring(string s){
      const int MAX_CHARS = 256;
      int m[MAX_CHARS];
      memset(m, -1, sizeof(m));
      int maxlen = 0;
      int lastRepeatPods = -1;
      for(int i = 0; i < s.size(); i++ )
      {
         if(m[s[i]] != -1 && lastRepeatPods < m[s[i]])
            lastRepeatPods = m[s[i]];
         if(i - lastRepeatPods > maxlen)
             maxlen = i - lastRepeatPods;
         m[s[i]] = i;
      }
     return maxlen;
 } 
};

int main(int argc, char *argv[]){
         Solution so;
         string s1 = "abcabcbb", s2 = "bbbbbb", s3 = "bbabcdd";
         cout<<s1<<":"<<"first"<<so.lengthOfLongestSubstring1(s1)<<"second"<<so.lengthOfLongestSubstring(s1)<<endl;
         cout<<s2<<":"<<"first"<<so.lengthOfLongestSubstring1(s2)<<"second"<<so.lengthOfLongestSubstring(s2)<<endl;
         cout<<s3<<":"<<"first"<<so.lengthOfLongestSubstring1(s3)<<"second"<<so.lengthOfLongestSubstring(s3)<<endl;
         if(argc > 1)
           cout<< argv[1]<<":"<<"first"<<so.lengthOfLongestSubstring1(argv[1])<<"second"<<so.lengthOfLongestSubstring(argv[1])<<endl;
           return 0;
             
          


}
