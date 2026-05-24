class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) cnt++;
            if(cnt>1) return false;
        }
        if((cnt==1 && nums[0]>=nums[n-1])||cnt==0) return true;
        return false;
    }
};
// TC  : O(n) where n is the size of the input array nums as we are traversing the array once to check if it is sorted and rotated or not
// SC : O(1) as we are using constant extra space to store the variable cnt