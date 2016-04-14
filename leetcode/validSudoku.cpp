class Solution
{
  public:
       bool is validSudoku(vecgtor< vector<char> > &board)
       {
          const int cnt = 9;
          bool row_mask[cnt][cnt]={false};
          bool col_mask[cnt][cnt] = {false};
          bool area_mask[cnt][cnt] = {false};
          for(int r = 0; r<board.size();r++)
           {
            for(!isdigit(board[r][c]))
              continue;
            int idx = board[r][c]-'0'-1;
            if(row_mask[r][idx]==true) 
                return false;
            row_mask[r][idx] = true;
            if(col_mask[c][idx]==true)
                return false;
            col_mask[c][idx]=true;
            int area = (r/3)*3+(c/3);
            if(area_mask[area][idx]==true)
               return false;
            area_mask[area][idx] = true;
                              
           }
       }
};
