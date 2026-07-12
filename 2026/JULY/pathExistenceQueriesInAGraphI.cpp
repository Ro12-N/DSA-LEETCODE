class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int cnt=0;
        vector<int>comp(n,-1);
        comp[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff) cnt++;
            comp[i]=cnt;
        }
        vector<bool>ans;
        for(auto i:queries){
            int l=i[0];
            int r=i[1];
            ans.push_back(comp[l]==comp[r]);
        }
        return ans;
    }
};
// Time Complexity: O(n + q) where n is the length of the nums array and q is the number of queries
// Space Complexity: O(n) for storing the comp array