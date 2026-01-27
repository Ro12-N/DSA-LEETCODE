class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int mini=INT_MAX;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=1;i<n;i++){
            int v=arr[i]-arr[i-1];
            if(mini>=v){
                if(mini>v)
                ans.clear();
                mini=v;
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};
// Time Complexity: O(n log n)
// Space Complexity: O(1)