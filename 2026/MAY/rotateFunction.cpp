class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=(i*nums[i]);
            sum+=nums[i];
        }
         int maxi=curr;
        for(int i=1;i<n;i++){
            curr-=(nums[n-i]*(n));
            curr+=sum;
          maxi=max(maxi,curr);
        }
        return maxi;
    }
};
// TC: O(n) for calculating the initial sum and the loop to find the maximum rotation function value.
// SC: O(1) as we are using only a constant amount of extra space.