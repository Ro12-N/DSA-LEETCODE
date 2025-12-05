class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int t=accumulate(nums.begin(),nums.end(),0);
       return (t%2==0)?nums.size()-1:0;

    }
};