class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2*k) return false;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) dp[i]=dp[i-1]+1;
        }
        for(int i=k-1;i+k<n;i++){
            if(dp[i]>=k && dp[i+k]>=k) return true;
        }
        return false;
    }
};