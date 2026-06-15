class Solution {
public:
int n,m;
int solve(int i,int j,int k,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(k<0) return INT_MIN;
    if(i>=n||j>=m) return INT_MIN;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(i==n-1 &&j==m-1){
        int curr=min(grid[i][j],1);
        if(k-curr>=0) return grid[i][j];
        else return INT_MIN;
    }
    int right=grid[i][j]+solve(i,j+1,k-min(grid[i][j],1),grid,dp);
    int down=grid[i][j]+solve(i+1,j,k-min(grid[i][j],1),grid,dp);
    return dp[i][j][k]= max(right,down);
}
    int maxPathScore(vector<vector<int>>& grid, int k) {
         n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans=solve(0,0,k,grid,dp);
        if(ans<0) return -1;
        return ans; 

    }
};
//TC:O(n*m*k)
//SC:O(n*m*k)