class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(auto i:nums){
            ans=(ans+i)%k;
        }
        return ans;
    }
};