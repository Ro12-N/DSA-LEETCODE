class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        for(auto i:s){
            freq[i-'a']++;
        }
        string ans="";
        char mid='/';
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            if(freq[i]%2==1 && mid=='/'){
                mid=i+'a';
            }
            int curr=freq[i]/2;
            while(curr--){
                ans+=char(i+'a');
            }
        }
        string l=ans;
        reverse(l.begin(),l.end());
        return (mid=='/')?(ans+l):ans+mid+l;

    }
};
// Time Complexity: O(n) where n is the length of the input string s, since we iterate through the string to count character frequencies and then construct the palindrome.
// Space Complexity: O(1) since the frequency array has a fixed size of 26, regardless of the input size.