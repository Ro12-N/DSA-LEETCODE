class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int mx=INT_MIN;
        for(auto i:nums){
            mx=max(mx,i);
            ans.push_back(__gcd(i,mx));
        }
        sort(ans.begin(),ans.end());
        long long res=0;
        for(int i=0;i<n/2;i++){
           res+=__gcd(ans[i],ans[n-i-1]);
        }
        return res;
    }
};
// Time Complexity: O(n log n) due to the sorting of the ans vector, where n is the size of the input nums vector. The GCD calculations are O(log(max(nums))) for each pair, but since we are only calculating GCD for n/2 pairs, this does not dominate the overall complexity.
// Space Complexity: O(n) for storing the ans vector, which holds the GCD values for each element in nums.git 