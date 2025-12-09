class Solution {
public:
    int specialTriplets(vector<int>& nums) {
       unordered_map<int,int>mp,t;
       for(auto i:nums) mp[i]++;
       long ans=0;
       int mod=1e9+7;
       for(auto i:nums){
          mp[i]--;
           ans=(ans+(1LL*mp[i*2]*t[i*2]))%mod;

          t[i]++;
       }
       return ans;

    }
};