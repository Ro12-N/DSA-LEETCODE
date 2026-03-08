class Solution {
public:
    int minFlips(string s) {
        int a=0;
        int b=0;
        int ans=INT_MAX;
        int n=s.size();
        int j=0;
        for(int i=0;i<2*n;i++){
          char p=(i%2)?'0':'1';
          char q=(i%2)?'1':'0';
          if(s[i%n]!=p) a++;
          if(s[i%n]!=q) b++;

           if(i-j+1>n){
            char x=(j%2)?'0':'1';
          char y=(j%2)?'1':'0';
          if(s[j]!=x) a--;
          if(s[j]!=y) b--;
               j++;
           }
           if(i-j+1==n)
           ans=min({ans,a,b});
        }
        return ans;
    }
};
//TC: O(n) where n is the length of the input string s
//SC: O(1) since we are using only a constant amount of extra space