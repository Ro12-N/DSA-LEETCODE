class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) ans=min(ans,abs(i-start));
        }
        return  ans;
    }
};
// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(1) as we are using only a constant amount of extra space