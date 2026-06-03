class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                int finish1 = max(landStartTime[i] + landDuration[i],
                                  waterStartTime[j]) + waterDuration[j];
                int finish2 = max(waterStartTime[j] + waterDuration[j],
                                  landStartTime[i]) + landDuration[i];
                ans = min(ans, min(finish1, finish2));
            }
        }

        return ans;
    }
};
// Time Complexity: O(n*m) where n and m are the sizes of landStartTime and waterStartTime respectively.
// Space Complexity: O(1) as we are using only a constant amount of extra space