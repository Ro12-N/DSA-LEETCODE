class Solution {
public:
    int maximum69Number (int num) {
        int idx=0;
        int val=num;
        int ans=-1;
        while(val){
            int d=val%10;
            if(d==6) ans=idx;
            val/=10;

            idx++;
        }
        if(ans==-1) return num;
        return num+3*pow(10,ans);
    }
};