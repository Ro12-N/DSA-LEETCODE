class Solution {
public:
int n,m;
int mod=1e9+7;
int solve(vector<vector<int>>&grid,int k,int i,int j,int sum,vector<vector<vector<int>>>&dp){
    if(i>=n||j>=m) return 0;
    if(i==n-1&& j==m-1){
        if((sum+grid[i][j])%k==0) return 1;
        return 0;
    }
    if(dp[i][j][sum]!=-1) return dp[i][j][sum];
    int newsum = (sum + grid[i][j]) % k;
    int right=solve(grid,k,i,j+1,newsum,dp);
    int down=solve(grid,k,i+1,j,newsum,dp);
    return dp[i][j][sum]=  (right+down)%mod;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve(grid,k,0,0,0,dp);
    }
};