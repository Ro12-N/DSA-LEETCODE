class Solution {
public:
    int numberOfSpecialChars(string word) {
       int l=0;
       int u=0;
       for(auto i:word){
          if(i>='a' && i<='z') l|=(1<<(i-'a'));
          else u|=(1<<(i-'A'));
       }
       l&=u;
       return __builtin_popcount(l);
    }
};
// TC : O(n) where n is the length of the input string word as we are traversing the string once to count the occurrences of each character and then performing a bitwise operation to find the common characters.
// SC : O(1) as we are using a constant amount of space to store the bitmasks for lowercase and uppercase characters, and the cnt variable takes O(1) space.