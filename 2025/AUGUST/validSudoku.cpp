class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       unordered_set<string>st;
       for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
            string a=to_string(board[i][j])+"row"+to_string(i);
            string b=to_string(board[i][j])+"col"+to_string(j);
            string c=to_string(board[i][j])+"-"+to_string(i/3)+"-"+to_string(j/3);
              if(st.count(a)||st.count(b)||st.count(c)) return false;
              st.insert(a);
              st.insert(b);
              st.insert(c);
            }
        }
       } 
       return true;
    }
};