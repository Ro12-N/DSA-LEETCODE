class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,long long>sum;
        unordered_map<int,int>freq;
        vector<long long>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(freq.count(nums[i])){
               ans[i]+= (1LL*i*freq[nums[i]])-sum[nums[i]];
            }
            freq[nums[i]]++;
            sum[nums[i]]+=i;
        }
        sum.clear();
        freq.clear();
         for(int i=nums.size()-1;i>=0;i--){
            if(freq.count(nums[i])){
               ans[i]+= sum[nums[i]]-(1LL*i*freq[nums[i]]);
            }
            freq[nums[i]]++;
            sum[nums[i]]+=i;
        }
        return ans;
    }
};
// Time complexity:O(N)
// Space Complexity:O(N)