class Solution {
public:
    int bestClosingTime(string customers) {
        int size=customers.size();
        int j=0;
        int y=0;
        for(auto i:customers) if(i=='Y') y++;
        int ans=size;
        int minpenalty=INT_MAX;
        int n=0;
        while(j<=size){
          int curr=n+y;
          if(minpenalty>curr){
            minpenalty=curr;
            ans=j;
          }
          if(j<size &&customers[j]=='Y') y--;
          else n++;

          j++;
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
