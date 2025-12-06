#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = (int)nums.size();
        const int MOD = 1e9 + 7;

        deque<int> dqMin, dqMax;
        vector<int> dp(n + 1, 0), pref(n + 1, 0);
        dp[0] = 1;
        pref[0] = 1;
        int L = 0;

        for (int R = 0; R < n; ++R) {
           
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[R])
                dqMax.pop_back();
            dqMax.push_back(R);

            
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[R])
                dqMin.pop_back();
            dqMin.push_back(R);

            
            while (!dqMin.empty() && !dqMax.empty() && nums[dqMax.front()] - nums[dqMin.front()] > k) {
                if (dqMin.front() == L) dqMin.pop_front();
                if (dqMax.front() == L) dqMax.pop_front();
                ++L;
            }

           
            long long val = pref[R] - (L > 0 ? pref[L - 1] : 0);
            if (val < 0) val += MOD;
            dp[R + 1] = (int)val;
            pref[R + 1] = (pref[R] + dp[R + 1]) % MOD;
        }

        return dp[n];
    }
};
