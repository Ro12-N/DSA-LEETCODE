class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        vector<int>f(100,0);
        for(auto i:nums){
            if(f[i]) ans.push_back(i);
            f[i]++;
        }
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/
//TC : O(N)
//SC : O(1) since constraints are small