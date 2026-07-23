class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int  m=grid.size();
        int n=grid[0].size();
       vector<vector<int>>ans(m,vector<int>(n,0));
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int newval=((i*n+j)+k)%(m*n);
            int r=newval/n;
            int c=newval%n;
            ans[r][c]=grid[i][j];
        }
       }
       return ans;
    }
};
// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the input grid. This is because we are iterating through each element of the grid once to compute its new position after shifting.
// Space Complexity: O(m*n) since we are creating a new grid of the same size as the input grid to store the shifted values.