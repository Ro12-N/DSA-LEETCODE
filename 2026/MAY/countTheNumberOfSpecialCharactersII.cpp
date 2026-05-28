class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt=0;
        vector<int>v(52,-1);
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(ch>='a'&&ch<='z'){
                v[ch-'a']=i;
            }else 
                if(v[ch-'A'+26]==-1) v[ch-'A'+26]=i;
        }
        for(int i=0;i<26;i++){
            if(v[i]!=-1 && v[i+26]!=-1 && v[i]<v[i+26]) cnt++;
        }
        
        return cnt;
    }
};
// TC : O(n) where n is the length of the input string word as we are traversing the string once to count the occurrences of each character and then performing a check to find the common characters.
// SC : O(1) as we are using a constant amount of space to store the indices of lowercase and uppercase characters in the vector v, and the cnt variable takes O(1) space.