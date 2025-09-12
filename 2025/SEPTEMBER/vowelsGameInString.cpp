class Solution {
public:
    bool doesAliceWin(string s) {
        for(auto i:s){
            if(i=='a'||i=='e'||i=='o'||i=='i'||i=='u') return true;
        }
        return false;
    }
};