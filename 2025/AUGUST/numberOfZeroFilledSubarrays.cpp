class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long cnt=0;
        for(auto i:nums){
            if(i==0) cnt++;
            else{
               ans+=(cnt)*(cnt+1)/2;
                cnt=0;
            }
        }
        ans+=(cnt)*(cnt+1)/2;
        
        return ans;
    }
};