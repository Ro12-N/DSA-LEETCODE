class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>prev(n,0);
        prev[0]=nums[0]==target;
        for(int i=1;i<n;i++){
            prev[i]+=prev[i-1]+(nums[i]==target);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int curr=prev[j]-(i>0?prev[i-1]:0);
                if((2*curr)>j-i+1) ans++;
            }
        }
        return ans;
    }
};
// TC : O(n^2) since we are traversing the string twice
// SC : O(n) since we are using extra space for prefix sum array