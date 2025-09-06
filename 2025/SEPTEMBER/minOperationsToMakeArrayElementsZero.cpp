class Solution {
public:
long long solve(int &l,int &r){
    long long L=1;
    long long steps=0;
    long long s=1;

    while(L<=r){
       long long R=4*L-1;
       long long a=max(L,(long long)l);
       long long b=min((long long)r,R);
       if(a<=b){
        steps+=(b-a+1)*s;
       }
       s++;
       L*=4;
    }
    return steps;
}
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;
        for(auto i:queries){
            int l=i[0];
            int r=i[1];
            ans+=(solve(l,r)+1)/2;
        }
        return ans;
    }
};