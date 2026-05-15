class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int>mp;
        int val=nums.size()-1;
        for(auto i:nums){
            if(i>val) return false;
            if(i<val && mp[i]) return false;
            mp[i]++;
        }
        return mp[val]==2;
    }
};
// TC : O(n) where n is the number of elements in the input array. We iterate through the array once to count the occurrences of each element.
// SC : O(n) in the worst case, if all elements in the input array are distinct. We use an unordered_map to store the count of each element, which can take up to O(n) space in the worst case.