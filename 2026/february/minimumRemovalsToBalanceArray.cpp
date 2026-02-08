class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            while(i<=j && nums[j]>1LL*k*nums[i]) i++;
            int curr= n-(j-i+1);
            ans=min(ans,curr);
        }
        return ans;
    }
};
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1)