#include <map>
#include <iostream>
#include  <vector>
using namespace std;


class TwoSum{
      private:
         map<int, int> num;
      public:
         void add(int number, int itt){
               num.insert(make_pair(number, itt));
         }
         void out(){
              for(map<int, int>::iterator i = num.begin(); i != num.end(); i++)       
                 cout<<i->first<<" "<<i->second<<endl;
         }

         vector<int> find(int value){
              int one, two;
              vector<int> result;
              for(map<int, int>::iterator  j  = num.begin();  j != num.end(); j++)
              {
                  one = j->first;
                  two = value - one;
                  if (num.find(two) != num.end()) 
                     {
                         result.push_back((j->second) + 1);
                         map<int, int>::iterator k = num.find(two);                   
                         result.push_back((k->second) + 1);
                         break;
                     } 
               }
                  return result;
         }
};


int main(){
     int tar;
     TwoSum ts;
     cout<<"please input the numbers!"<<endl;
     int it = 0;
     while(true){
          int c;
          cin>>c;
          ts.add(c, it);         
          it++;
          char cc = cin.get();
          if(cc == '\n')
            break;
     }
     ts.out();
     cout<<"please input the target!"<<endl;
     cin>>tar;
     vector<int> res = ts.find(tar);
     for(vector<int>::iterator k = res.begin(); k != res.end(); k ++)
              cout<< *k<<endl;
}
