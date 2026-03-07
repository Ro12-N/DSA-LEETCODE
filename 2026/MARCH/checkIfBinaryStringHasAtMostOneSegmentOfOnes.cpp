class Solution {
public:
    bool checkOnesSegment(string s) {
       for(int i=1;i<s.size();i++){
        if(s[i]=='1' &&s[i-1]=='0') return false;
       }
       return true;
    }
};
//TC: O(n) where n is the length of the input string s
//SC: O(1) since we are using only a constant amount of extra space