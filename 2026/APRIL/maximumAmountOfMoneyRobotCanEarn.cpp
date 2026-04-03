class Solution {
public:
int n,m;
int dp[501][501][3];
int solve(int i,int j,int nu,vector<vector<int>>&coins){
    if(i>=n||j>=m) return INT_MIN;
     if(i==n-1 &&j==m-1){
        if(coins[i][j]<0 && nu>0) return 0;
        return coins[i][j];
     }
     if(dp[i][j][nu]!=INT_MIN) return dp[i][j][nu];

    int take=coins[i][j]+max(solve(i+1,j,nu,coins),solve(i,j+1,nu,coins));
    int skip=INT_MIN;
    if(coins[i][j]<0 &&nu>0){
        skip=max(solve(i+1,j,nu-1,coins),solve(i,j+1,nu-1,coins));
    }
    return dp[i][j][nu]= max(take,skip);
}
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k]=INT_MIN;
                }
            }
        }
        return solve(0,0,2,coins);
    }
};
// TC: O(n*m*3) due to the three-dimensional DP array.
// SC: O(n*m*3) for the DP array.
