class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int j=0;
            int k=i-1;
            while(j<k){
                int v=nums[j]+nums[k];
                if(v>nums[i]) {
                    ans+=k-j;
                    k--;
                }else{
                     j++;
                }
            }
        }
        return ans;
    }
};