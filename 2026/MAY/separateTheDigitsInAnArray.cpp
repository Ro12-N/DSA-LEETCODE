class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            int v=nums[i];
            while(v){
                ans.push_back(v%10);
                v/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// TC : O(m) where m is the total number of digits in all the numbers in the input array. We iterate through each number and extract its digits.
// SC : O(m) for the output array that stores the separated digits.