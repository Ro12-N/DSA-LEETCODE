class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        int prev=INT_MIN;
        for(auto i:nums){
            int mini=i-k;
            if(prev<mini){
                prev=mini;
                cnt++;
            }else if(prev<i+k){
                prev=prev+1;
                cnt++;
            }
        }
        return cnt;
        
    }
};