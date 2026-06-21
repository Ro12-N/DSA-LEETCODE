class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int curr=0;
        for(auto i:gain){
            curr+=i;
            ans=max(ans,curr);
        }
        return ans;
    }
};
// TC : O(n) since we are traversing the entire array
// SC : O(1) since we are using constant space