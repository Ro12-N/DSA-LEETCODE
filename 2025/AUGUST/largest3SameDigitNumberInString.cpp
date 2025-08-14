class Solution {
public:
    string largestGoodInteger(string num) {
        int cnt=0;
        int maxi=INT_MIN;
        int prev=-1;
        for(auto i:num){
              if(i!=prev){
                cnt=1;
              }else{
                cnt++;
              }
              if(cnt>2) maxi=max(maxi,i-'0');
              prev=i;
        }
        if(maxi==INT_MIN) return "";
        return string(3,maxi+'0');
    }
};