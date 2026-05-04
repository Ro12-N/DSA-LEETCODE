class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
         s+=s;
         return s.find(goal)!=string::npos;
    }
};
// TC : O(n) where n is the length of the input string s
// SC : O(1) as we are using only constant space to store the concatenated