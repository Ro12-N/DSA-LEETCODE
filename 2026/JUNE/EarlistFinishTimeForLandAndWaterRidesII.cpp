class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        int l = INT_MAX, w = INT_MAX;
        int minl = INT_MAX, minw = INT_MAX;

        for (int i = 0; i < n; i++) {
            l = min(l, landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < m; i++) {
            minl = min(minl,
                       max(waterStartTime[i], l) + waterDuration[i]);
            w = min(w,
                    waterStartTime[i] + waterDuration[i]);
        }

        for (int i = 0; i < n; i++) {
            minw = min(minw,
                       max(landStartTime[i], w) + landDuration[i]);
        }

        return min(minl, minw);
    }
};
// Time Complexity: O(n + m) where n and m are the sizes of landStartTime and waterStartTime respectively.
// Space Complexity: O(1) as we are using only a constant amount of extra space