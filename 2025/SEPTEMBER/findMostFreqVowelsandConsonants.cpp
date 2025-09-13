class Solution {
public:
    int maxFreqSum(string s) {
       vector<int>mp(26,0);
       int a=0;
       int b=0;
       for(auto i:s){
        if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'){
            mp[i-'a']++;
            a=max(a,mp[i-'a']);
        }else{
            mp[i-'a']++;
            b=max(b,mp[i-'a']);
        }
       }
       return a+b;
    }
};