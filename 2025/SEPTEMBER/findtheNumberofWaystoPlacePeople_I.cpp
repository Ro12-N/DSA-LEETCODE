class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int a=points[i][0];
            int b=points[i][1];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int c=points[j][0];
                int d=points[j][1];
                if(a<=c && b>=d){
                    bool flag=true;
                    for(int k=0;k<n;k++){
                        if(k==i || k==j) continue;
                        int e=points[k][0];
                        int f=points[k][1];
                        if(a<=e &&e<=c && f<=b && f>=d){
                            flag=false;
                            break;
                        }
                    }
                    if(flag) cnt++;
                }
            }
        }
        return cnt;
    }
};