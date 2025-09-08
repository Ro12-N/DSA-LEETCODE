class Solution {
public:
bool solve(int val){
       while(val){
        if(val%10==0) return false;
          val/=10;
       }
       return true;
}
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(solve(i)&& solve(n-i)) return {i,n-i};
        }
        return {};
    }
};