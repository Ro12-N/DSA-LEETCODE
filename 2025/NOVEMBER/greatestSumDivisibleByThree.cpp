class Solution {
public:
int dp[40001][3];
int solve(vector<int>&nums,int i,int m){
    if(i>=nums.size()){
        if(m==0) return 0;
        return INT_MIN;
    }
    if(dp[i][m]!=-1) return dp[i][m];
    int nt=solve(nums,i+1,m);
    int t=nums[i]+solve(nums,i+1,(m+nums[i])%3);
    return dp[i][m]= max(nt,t);

}
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,0,0);
        return max(0,ans);
    }
};