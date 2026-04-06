class Solution {
public:
    bool judgeCircle(string moves) {
         int a=0;
         int b=0;
         for(auto i:moves){
            if(i=='R') a++;
            else if(i=='L') a--;
            else if(i=='U') b++;
            else b--;
         }
         return a==0 &&b==0;
    }
};
// TIME: O(n) where n is the length of the moves string         
// SPACE: O(1) since we are using only a constant amount of extra space to store the counts of moves