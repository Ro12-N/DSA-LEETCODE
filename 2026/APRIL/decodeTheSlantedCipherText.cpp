class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        string ans="";
        int cols=n/rows;
        for(int j=0;j<cols;j++){
            for(int idx=j;idx<n;idx+=cols+1){
                ans+=encodedText[idx];
            }
        }
        while(!ans.empty() && ans.back()==' ') ans.pop_back();
        return ans;
    }
};
// TIME: O(n) where n is the length of the encodedText string
// SPACE: O(n) where n is the length of the encodedText string 