class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int idx=(i+nums[i])%n;
                ans[i]=nums[idx];
            }
            else if(nums[i]<0){
                int idx=(i+nums[i])%n;
                if(idx<0) idx+=n;
                ans[i]=nums[idx];
            }
        }
        return ans;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)