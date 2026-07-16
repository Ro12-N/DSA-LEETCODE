class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                if (num >= low && num <= high)
                    res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// Time Complexity: O(1) since the number of sequential digits is limited and does not depend on the input size
// Space Complexity: O(1) for storing the result, as the maximum number of sequential digits is constant (there are only 36 possible sequential digit numbers).