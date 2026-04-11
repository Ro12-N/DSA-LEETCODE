class Solution {
public:
    int minimumDistance(vector<int>& nums) { 
        int ans=INT_MAX;
        unordered_map<int,deque<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            if(mp[nums[i]].size()>3) mp[nums[i]].pop_front();
            if(mp[nums[i]].size()==3) ans=min(ans,2*(mp[nums[i]].back()-mp[nums[i]].front()));
        }
        return ans==INT_MAX?-1:ans;
    }
};
// Time Complexity: O(n) 
// Space Complexity: O(n) in worst case when all elements are distinct