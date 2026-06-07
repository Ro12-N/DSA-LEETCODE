class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto i:nums) sum+=i;
        vector<int>ans(n);
        int curr=0;
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            ans[i]=abs(curr-sum);
            curr+=nums[i];
        }
        return ans;
    }
};
// TimeComplexity: O(N);
// SpaceComplexity: O(N);