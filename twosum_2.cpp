#include <iostream>
#include <vector>
using namespace std;

class Solution{
      public:
         vector<int> twoSum(vector<int> &numbers, int target)
         {
             vector<int> result;
             int low = 0;
             int high = numbers.size()-1;
             while(low < high)
             {
                if(numbers[low] + numbers[high] == target)
                    {
                      result.push_back(low + 1);
                      result.push_back(high + 1);
                      break;
                    }
                else
                   numbers[low] + numbers[high] > target ? high-- : low++;                
             }    
             return result;
         }
};

int main(){
    Solution so;
    vector<int> sum;
    int tar;
    while(true)
    {
        int c;
        cin>>c;
        sum.push_back(c);
        char cc = cin.get();
        if (cc == '\n')
          break;         
    }
    for(vector<int>::iterator i = sum.begin(); i != sum.end(); i++)
          cout<<*i<<endl;
    cout<<"please input the target!"<<endl;
    cin>>tar;
    vector<int> res = so.twoSum(sum, tar);
    for(vector<int>::iterator j = res.begin(); j != res.end(); j++)
        cout<< *j<<endl;
    return 0;
}
