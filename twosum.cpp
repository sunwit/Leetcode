#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution{
      public:
            vector<int>  twoSum(vector<int> &numbers, int target)
            {
                int i, sum;
                vector<int> results;
                map<int, int> hmap;
                for (i = 0; i < numbers.size();  i++)
                    {
                      int num = numbers[i];
                      if (!hmap.count(target-num))
                         {
                             hmap.insert(pair<int, int>(numbers[i], i+1));

                         }
                     else if (hmap.count(target-num))
                           { results.push_back(hmap[target-numbers[i]]);
                             results.push_back(i+1);
                             break;                          
                            }
                    }
                   return results;           
            }
};

int main(){
   Solution so;
   vector<int>  sum;
   int ss,tar; 
   while(true)
   {
       cin>>ss;
       sum.push_back(ss); 
       char c = cin.get();
       if (c == '\n') break;
       
   }
   cout<<"please input the target!"<<endl;
   cin >> tar;
  vector<int> res = so.twoSum(sum, tar);
   for(vector<int>::iterator m = res.begin(); m != res.end(); m++) 
       cout << *m<<endl;
   return 0;
}
