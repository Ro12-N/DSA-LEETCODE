class Solution {
public:
int minsum(vector<int>&nums){
    int n=nums.size();
    int mini=INT_MAX;
    int idx=-1;
    for(int i=0;i<n-1;i++){
        if(nums[i]+nums[i+1]<mini){
            mini=nums[i]+nums[i+1];
            idx=i;
        }
    }
    return idx;
}
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int idx=minsum(nums);
            nums[idx]+=nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            ans++;
        }
        return ans;
    }
};
// https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/
// Tc:O(n^2)
// Sc:O(1)