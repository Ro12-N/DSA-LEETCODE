class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=0;i<=35;i++){
            long long val=(long long)num1-(long long)num2*i;
            if(val<0) return -1;
            int a=__builtin_popcountll(val);
            if(a<=i &&i<=val) return i;
        }
        return -1;
    }
};