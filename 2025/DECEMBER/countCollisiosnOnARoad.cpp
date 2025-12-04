class Solution {
public:
    int countCollisions(string directions) {
        int i=0;
        int n=directions.size();
        int j=n-1;
        while(i<n && directions[i]=='L') i++;
        while(j>=0 && directions[j]=='R') j--;
        int ans=0;
        while(i<=j){
            if(directions[i]!='S') ans++;
            i++;
        }
        return ans;
    }
};