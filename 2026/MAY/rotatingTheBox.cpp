class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
            int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> res(n, vector<char>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i][j] = boxGrid[j][i];
            }
        }
        for(auto &i:res){
            reverse(i.begin(),i.end());
        }
        for(int j=0;j<m;j++){
              deque<int>q;
            for(int i=n-1;i>=0;i--){
                if(res[i][j]=='*'){
                    q.clear();
                }
                if(res[i][j]=='#'){
                    if(!q.empty()){
                        res[q.front()][j]='#';
                        q.pop_front();
                        res[i][j]='.';
                    }
                }
                if(res[i][j]=='.') q.push_back(i);
            }
        }
        return res;

    }
};
// TC : O(m*n) where m and n are the number of rows and columns in the input box grid respectively
// SC : O(m*n) as we are using an additional 2D vector to store