class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            int curr=0;
            for(int j=i;j<n;j++){
                if(!st.count(nums[j])){
                     if(nums[j]%2) curr++;
                     else curr--;
                }
                st.insert(nums[j]);
                if(curr==0)
               ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
// Time Complexity: O(n^2) where n is the number of elements in the array
// Space Complexity: O(n) where n is the number of elements in the array due to the unordered_set used to store the unique elements in the current subarray.