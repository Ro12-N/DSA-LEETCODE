class Solution {
public:
    int n;
    int dp[100001][3];
    vector<int> nextIdx;

    int solve(vector<vector<int>>& events, int idx, int cnt) {
        if (cnt == 2 || idx >= n) return 0;
        if (dp[idx][cnt] != -1) return dp[idx][cnt];

        int skip = solve(events, idx + 1, cnt);
        int take = events[idx][2] + solve(events, nextIdx[idx], cnt + 1);

        return dp[idx][cnt] = max(skip, take);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        memset(dp, -1, sizeof(dp));

        nextIdx.resize(n);
        for (int i = 0; i < n; i++) {
            int key = events[i][1];
            nextIdx[i] = upper_bound(
                events.begin(),
                events.end(),
                vector<int>{key, INT_MAX, INT_MAX}
            ) - events.begin();
        }

        return solve(events, 0, 0);
    }
};

// Time Complexity: O(N log N)
// Space Complexity: O(N)     
