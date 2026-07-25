class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=1;
        while(ans<=n) ans*=2;
        return ans;
    }
};
// Time Complexity: O(1) since the function performs a constant number of operations regardless of the input size.
// Space Complexity: O(1) since the function uses a constant amount of space regardless of the input size.