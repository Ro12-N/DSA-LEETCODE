class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums){
            sum=(sum+i)%p;
        }
        int t=sum%p;
        if(t==0) return 0;
        int ans=n;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int curr=0;
        for(int i=0;i<n;i++){
            curr=(curr+nums[i])%p;
           int f=(curr-t+p)%p;
           if(mp.count(f)) ans=min(ans,i-mp[f]);

            mp[curr]=i;
        }
        return ans==n?-1:ans;
    }
};