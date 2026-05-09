class Solution {
public:
    vector<bool> getprime(int maxi){
        vector<bool>isp(maxi+1,true);
        isp[0]=isp[1]=false;
        for(int i=2;i*i<=maxi;++i){
            if(isp[i]){
                for(int j=i*i;j<=maxi;j+=i){
                    isp[j]=false;
                }
            }
        }
        return isp;
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int maxi=*max_element(nums.begin(),nums.end());
        vector<bool>p=getprime(maxi);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(0);
        vis[0]=true;
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
             while(sz--){
                 int i=q.front();
                 q.pop();
                 if(i==n-1) return steps;
                 for(int ni:{i-1,i+1}){
                     if(ni>=0 &&ni<n && !vis[ni]){
                         vis[ni]=true;
                         q.push(ni);
                     }
                 }
                 if(p[nums[i]]){
                     int v=nums[i];
                     for(int m=v;m<=maxi;m+=v){
                         for(auto j:mp[m]){
                             if(j!=i &&!vis[j]){
                                 vis[j]=true;
                                 q.push(j);
                             }
                         }
                         mp[m].clear();
                     }
                 }
             }
            steps++;
        }
        return -1;
    }
};
// TC : O(n*sqrt(max(nums))) where n is the size of the input array nums and max(nums) is the maximum value in the array.           
// SC : O(n) as we are using additional data structures to store the prime numbers, the mapping of values to indices, and the visited array.