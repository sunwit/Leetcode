#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<vector>

using namespace std;

const int SodukuSize = 9;
bool row_mask[SodukuSize][SodukuSize];
bool col_mask[SodukuSize][SodukuSize];
bool area_mask[SodukuSize][SodukuSize];

bool initSudukuMask(vector< vector<char> > &board)
{
 memset(row_mask,false,sizeof(row_mask));
 memset(col_mask,false,sizeof(row_mask));
 memset(area_mask,false,sizeof(area_mask));
 for(int r = 0; r<board.size();r++)
   {
     for(int c = 0; c<board[r].size();c++)
        {
            if(!isdigit(board[r][c]))
               continue;
            int idx = board[r][c]-'0'-1;
            int area = (r/3)*3+(c/3);
            if(row_mask[r][idx]||col_mask[c][idx]||area_mask[area][idx])
               return false;
            row_mask[r][idx]=col_mask[c][idx]=area_mask[area][idx]=true;
        }
   }
   return true;
}

 bool  recursiveSuduku(vector< vector<char> > &board, int row, int col)
{
  
  if(row>=SodukuSize)
     {
        return true;
      }
  if(col>=SodukuSize)
     return recursiveSuduku(board, row+1, 0);
  if(board[row][col]!='.')
    return recursiveSuduku(board, row, col+1);
  int area;
  for(int i=0;i<SodukuSize;i++)
  {
    area = (row/3)*3 + (col/3);
    if(row_mask[row][i]||col_mask[col][i]||area_mask[area][i])
        continue;
     board[row][col] = i + '1';
     row_mask[row][i]=col_mask[col][i]=area_mask[area][i]=true;
     if(recursiveSuduku(board,row,col+1)==true)
     {
         return true;
     }    
     board[row][col]='.';
     row_mask[row][i]=col_mask[col][i]=area_mask[area][i]=false;
  }
  return false;
}

 void solveSuduku(vector< vector<char> > &board)
{
  if(initSudukuMask(board)==false)
     return;
   recursiveSuduku(board,0,0);
}

int main(int argc, char **argv)
{
vector< vector<char> > bo(9, vector<char>(9)); 
char  a[9][9]={
{'5','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'8','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'}
};


for(int i=0;i<9;i++)
{
 for(int j=0;j<9;j++)
 {
     bo[i].push_back(a[i][j]); 
 //    cout<<a[i][j]<<"  ";
 }
 //cout<<endl;
}

 if(recursiveSuduku(bo,0,0))
 {
for(int i = 0;i<bo.size();i++)
  {
    for(int j=0;j<bo[i].size();j++)
          cout<<bo[i][j]<<"  ";     
    cout<<endl;
  }
  }
 return 0; 
}
