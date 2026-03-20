class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<pair<int,int>>>curr(n,vector<pair<int,int>>(m,{0,0}));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X') curr[i][j].first++;
                else if(grid[i][j]=='Y') curr[i][j].second++;
                if(i>0) {
                    curr[i][j].first+=curr[i-1][j].first;
                    curr[i][j].second+=curr[i-1][j].second;
                }
                if(j>0) {
                    curr[i][j].first +=curr[i][j-1].first;
                    curr[i][j].second +=curr[i][j-1].second;
                }
                if(i>0 &&j>0) {
                    curr[i][j].first -=curr[i-1][j-1].first;
                     curr[i][j].second -=curr[i-1][j-1].second;
                }
                if(curr[i][j].first>0&&curr[i][j].first==curr[i][j].second) ans++;
            }
        }
        return ans;
    }
};
// TC: O(n*m) where n is number of rows and m is number of columns
// SC: O(n*m) as we are using an extra 2D vector to store the count of X and Y in the submatrix from (0,0) to (i,j).