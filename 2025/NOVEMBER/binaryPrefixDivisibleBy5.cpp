class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int curr=0;
        for(auto i:nums){
            curr=(curr*2+i)%5;
           ans.push_back(curr%5==0);
        }
        return ans;
        
    }
};