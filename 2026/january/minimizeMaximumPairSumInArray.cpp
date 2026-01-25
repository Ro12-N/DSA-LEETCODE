class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        while(i<j){
            ans=max(ans,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};
// Time Complexity: O(n log n)
// Space Complexity: O(1)