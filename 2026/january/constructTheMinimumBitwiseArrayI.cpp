class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto i:nums){
            //10
            if(i==2){
                ans.push_back(-1);
                continue;
            }
              bool f=true;
            for(int j=0;j<32;j++){
                if(i &(1<<j)) continue;
                int curr=(i^(1<<(j-1)));
                ans.push_back(curr);
                f=false;
                break;
            }
            if(f) ans.push_back(-1);
        }
        return ans;
    }
};
// https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/
// Tc:O(n*32)   
// Sc:O(1)