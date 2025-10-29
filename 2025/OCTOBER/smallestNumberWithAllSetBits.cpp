class Solution {
public:
    int smallestNumber(int n) {
        int ans=0;
        for(int i=0;i<31;i++){
            ans|=(1<<i);
            if(ans>=n) return ans;
        }
        return -1;
    }
};