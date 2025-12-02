class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long ans=0;
        int prevlines=0;
        int mod=1e9+7;
        unordered_map<int,int>mp;
        for(auto &i:points) mp[i[1]]++;
        for(auto &it:mp){
            int cnt=it.second;
            long long lines=(long long)cnt*(cnt-1)/2;
            ans+=lines*prevlines;
            prevlines+=lines;
        }
        return ans%mod;
    }
};

// tc: O(N)
// sc: O(N)
