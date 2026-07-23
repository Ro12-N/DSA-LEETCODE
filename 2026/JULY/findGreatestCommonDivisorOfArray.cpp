class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a=nums[0];
        int b=nums[0];
        for(auto i:nums){
            a=max(a,i);
            b=min(b,i);
        }
        return __gcd(a,b);
    }
};
// Time Complexity: O(n) where n is the size of the input array nums. This is because we are iterating through the array once to find the maximum and minimum values.
// Space Complexity: O(1) since we are using a constant amount of extra space.