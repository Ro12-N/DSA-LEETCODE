class Solution {
public:
    int minimumDeletions(string s) {
        int a=0;
        for(auto i:s) if(i=='a')a++;
        int ans=INT_MAX;
        int b=0;
        for(auto i:s){
            if(i=='a')a--;
            ans=min(ans,a+b);
            if(i=='b') b++;
        }
        return ans;
    }
};
// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1)