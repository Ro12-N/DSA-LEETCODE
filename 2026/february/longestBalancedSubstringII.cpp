class Solution {
public:
int solve(char a,char b,string &s){
    unordered_map<int,int>mp;
    int p=0;
    int q=0;
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=a &&s[i]!=b) {
            mp.clear();
            p=0;
            q=0;
            continue;
        }
        if(s[i]==a) p++;
        if(s[i]==b) q++;
        
        if(p==q){
          ans=max(ans,p+q);
        }
        int diff=p-q;
        if(mp.count(diff)){
            ans=max(ans,i-mp[diff]);
        }else{
            mp[diff]=i;
        }
    }
    return ans;
}
    int longestBalanced(string s) {
        int ans=0;
        int n=s.size();
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        ans=max(ans,solve('a','b',s));
        ans=max(ans,solve('b','c',s));
        ans=max(ans,solve('a','c',s));

        unordered_map<string,int>mp;
        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<n;i++){
              if(s[i]=='a') a++;
              else if(s[i]=='b') b++;
              else c++;

              if(a==b &&a==c){
                ans=max(ans,a+b+c);
              }
              int d1=a-b;
              int d2=a-c;
              string key=to_string(d1)+"_"+to_string(d2);
              if(mp.count(key)){
                ans=max(ans,i-mp[key]);
              }else mp[key]=i;
        }
        return ans;
    }
};
// Time Complexity: O(n) where n is the number of characters in the input string s
// Space Complexity: O(n) where n is the number of characters in the input string s due to the unordered_map used to store the frequency of characters and their differences.