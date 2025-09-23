class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int cnt=0;
        int maxi=INT_MIN;
        vector<int>mp(101,0);
        for(auto i:nums){
            mp[i]++;
            if(mp[i]>maxi){
                cnt=1;
                maxi=mp[i];
            }else if(mp[i]==maxi) cnt++;
        }
        return cnt*maxi;
    }
};