class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto i:nums){
            int curr=0;
            int n=i;
            while(n){
                curr+=(n%10);
                n/=10;
            }
            ans=min(ans,curr);
        }
        return ans;
    }
};
// TC : O(N*log10(max(nums[i]))) where N is the size of the input array and max(nums[i]) is the maximum element in the array. This is because we need to calculate the digit sum for each element in the array, and the number of digits in an integer is proportional to log10 of that integer.
// SC : O(1) since we are using only a constant amount of extra space to store the minimum digit sum.