#include <iostream>
using namespace std;

int binarySearch(int A[], int low, int high, int key){
     while(low <= high){
          int mid = low + (high - low)/2;
          if(key == A[mid]) return mid;
          if(key > A[mid])
             low = mid + 1;
          else
             high = mid - 1;
     }
     return low;
}

double findMedianSortedArrayHelper(int A[], int m, int B[], int n, int lowA, int highA, int lowB, int highB){
        int mid = lowA + (highA - lowA)/2;
        int pos = binarySearch(B, lowB, highB, A[mid]);
        int num = mid + pos;
        if(num == (m + n)/2)
          {         
              if((m+n)%2 == 1)        
               return A[mid];
              int next;
              if(mid>0 && pos>0)
                 next = A[mid-1]>B[pos-1]? A[mid-1]:B[pos-1];
              else if(pos>0)
                   next = B[pos-1];
              else if(mid>0)
                   next = A[mid-1];
              return (next + A[mid])/2.0;
          }
         if(num<(m+n)/2)
         {
               lowA = mid + 1;
               lowB = pos;
               if(highA-lowA>highB-lowB)
                 return findMedianSortedArrayHelper(A,m,B,n,lowA,highA,lowB,highB);
               else
                 return findMedianSortedArrayHelper(B,n,A,m,lowB,highB,lowA,highA);
               
         }
         if(num>(m+n)/2)
           {
              highA = mid-1;
              highB = pos - 1;
              if(highA-lowA>highB-lowB)
                 return findMedianSortedArrayHelper(A,m,B,n,lowA,highA,lowB,highB);
              else
                 return findMedianSortedArrayHelper(B,n,A,m,lowB,highB,lowA,highA);
           }
}

double findMedianSortedArray(int A[],int m, int B[], int n){
       if(m == 0 && n == 0)
          return 0.0;
       if(m == 0)
          return  n%2==1? B[n/2]:(B[n/2-1]+B[n/2])/2.0;
       if(n == 0)
          return m%2==1? A[m/2]:(A[m/2-1]+A[m/2])/2.0;
       if(m>n)
          return findMedianSortedArrayHelper(A,m,B,n,0,m-1,0,n-1);
       else
          return findMedianSortedArrayHelper(B,n,A,m,0,n-1,0,m-1);
}

int main(){
   int r1[] = {1};
   int r2[] = {2};
   int n1 = sizeof(r1)/sizeof(r1[0]);
   int n2 = sizeof(r2)/sizeof(r2[0]);
   cout<<"median is 1.5:"<<findMedianSortedArray(r1,n1,r2,n2)<<endl;

 int r3[]={1,12,15,26,38};
  int  r4[]={2,13,17,30,45,50};
   int n3 = sizeof(r3)/sizeof(r3[0]);
   int n4 = sizeof(r4)/sizeof(r4[0]);
   cout<<"median is 17:"<<findMedianSortedArray(r3,n3,r4,n4)<<endl;
  
  return 0;
}
