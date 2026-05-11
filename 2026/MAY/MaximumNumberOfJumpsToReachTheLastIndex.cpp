class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) continue;

            for (int j = i + 1; j < n; j++) {
                if (abs(nums[j] - nums[i]) <= target)
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};
// TC : O(n^2) where n is the length of the input array. We have two nested loops to fill the dp array.
// SC : O(n) for the dp array that stores the maximum jumps to reach each index.