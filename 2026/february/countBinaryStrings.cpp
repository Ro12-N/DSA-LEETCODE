class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>ans;
        int n=s.size();
        int i=0;
        while(i<n){
            int curr=s[i];
            int cnt=0;
            while(i<n &&s[i]==curr){
                cnt++;
                i++;
            }
            ans.push_back(cnt);
        }
        int res=0;
        for(int i=1;i<ans.size();i++){
            res+=min(ans[i-1],ans[i]);
        }
        return res;
    }
};
// TC: O(n) since we are traversing the string once to count the consecutive characters and then again to calculate the result.
// SC: O(n) since we are using a vector to store the counts of consecutive characters