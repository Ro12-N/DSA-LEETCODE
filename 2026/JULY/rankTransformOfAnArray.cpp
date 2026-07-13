class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mp;
        int rnk=1;
        set<int>st(arr.begin(),arr.end());
        for(auto i:st){
            mp[i]=rnk++;
        }
        vector<int>ans;
        for(auto i:arr){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
// Time Complexity: O(n log n) where n is the number of elements in the array
// Space Complexity: O(n) for storing the rank mapping and the answer array