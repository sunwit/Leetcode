#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution{
      public:
           vector<int> twoSum(vector<int> &numbers, int target)
           {
                unordered_map<int, int> m;
                vector<int> result;

               for(int i= 0; i<numbers.size(); i++)
                { 
                     if (m.find(numbers[i]) == m.end())
                           m[target - numbers[i]] = i;
                     else
                     {
                          result.push_back(m[numbers[i]] + 1);
                          result.push_back(i + 1);
                          break;
                     }
                }
            return result;
       }
};

int main(){
      Solution so;
      int tar;
      vector<int> num;
      while(true)
      {
         int c;
         cin>>c;
          num.push_back(c);
         char cc = cin.get();
         if (cc  == '\n') break;
      }
     for(vector<int>::iterator j = num.begin(); j != num.end(); j++)
         cout<< *j<<endl;
     cout<<"please input the target!"<<endl;
     cin>>tar;
     vector<int> res = so.twoSum(num, tar);
     for (vector<int>::iterator k= res.begin();  k != res.end(); k++)
         cout<< *k<<endl;
     return 0;
}
