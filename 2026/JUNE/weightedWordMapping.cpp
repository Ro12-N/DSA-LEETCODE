class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto i:words){
            int curr=0;
            for(auto j:i){
              curr=(curr+(weights[(j-'a')]))%26;
            }
           ans+=('z'-curr);
        }
        return ans;
    }
};

// TC : O(N*M) where N is the number of words and M is the average length of the words
// SC : O(N) where N is the number of words