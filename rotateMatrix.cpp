#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

using namespace std;

void rotate(vector< vector<int> > &matrix)
{
  for(int i = 0, j = matrix.size()-1;i<j;i++,j--)
  {
    for(int k = i, d = j; k<j;k++,d--)
    {
       int t = matrix[i][k];
       matrix[i][k] = matrix[d][i];
       matrix[d][i] = matrix[j][d];
       matrix[j][d] = matrix[k][j];
       matrix[k][j] = t;
    }
  }
}

void printMatrix(vector< vector<int> > &matrix)
{
   for(int i = 0; i<matrix.size();i++)
   {
       for(int j = 0; j<matrix[i].size();j++)
       {
        printf("%3d", matrix[i][j]);
       }
       cout<<endl;
   }
   cout<<endl;
}

int main(int argc, char **argv)
{
 int n = 2;
 if(argc>1)
 {
  n = atoi(argv[1]);
 }
 vector< vector<int> > matrix;
 for(int i = 1; i<=n;i++)
 {
    vector<int>  v;
    for(int j = 1; j<=n;j++)
    {
       v.push_back((i-1)*n+j);
    }
    matrix.push_back(v);
 }


printMatrix(matrix);
rotate(matrix);
printMatrix(matrix);
return 0;
}
