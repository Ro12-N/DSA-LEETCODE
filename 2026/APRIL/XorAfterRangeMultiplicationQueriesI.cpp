class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int mod=1e9+7;
        for(auto i:queries){
            int s=i[0];
            int e=i[1];
            int k=i[2];
            int v=i[3];
            int j=s;
            while(j<=e){
                  nums[j]=(1LL*nums[j]*v)%mod;
                  j+=k;
            }
        }
        int xr=0;
        for(auto i:nums){
            xr^=i;
        }
        return xr;
    }
};
// Time Complexity: O(q * n) 
// Space Complexity: O(1)