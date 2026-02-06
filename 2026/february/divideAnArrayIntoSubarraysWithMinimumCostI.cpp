class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
        int a=INT_MAX;
        int b=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(a>nums[i]){
                b=a;
                a=nums[i];
            }else if(b>nums[i]) b=nums[i];
        }
        return ans+a+b;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)