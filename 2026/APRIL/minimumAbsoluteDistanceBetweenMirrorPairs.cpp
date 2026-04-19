class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                ans=min(ans,abs(i-mp[nums[i]]));
            }
            int rev=0;
            int curr=nums[i];
            while(curr){
                rev=rev*10+curr%10;
                curr/=10;
            }
            mp[rev]=i;

        }
        return ans==INT_MAX?-1:ans;
    }
};
// Time Complexity: O(n) where n is the number of elements in the input array
// Space Complexity: O(n) in worst case when all elements are distinct