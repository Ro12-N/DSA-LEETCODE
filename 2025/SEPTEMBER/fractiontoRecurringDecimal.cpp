class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans="";
        if(denominator==0) return "0";
        if((long long)denominator* (long long)numerator  <0) ans+='-';
      long long d= labs(denominator);
      long long n=labs(numerator);
        long long curr=n /d;
        ans+=to_string(curr);
        long long remain=n %d;
        if(remain==0) return ans;
        ans+='.';
        unordered_map<int,int>mp;
        while(remain!=0){
            mp[remain]=ans.size();
            remain*=10;
            ans+=to_string(remain/d);
            remain%=d;
            if(mp.count(remain)){
                ans.insert(mp[remain],"(");
                ans+=')';
                break;
            }
        }
        return ans;

    }
};