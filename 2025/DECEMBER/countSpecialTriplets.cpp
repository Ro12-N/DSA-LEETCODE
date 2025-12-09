class Solution {
public:
    int specialTriplets(vector<int>& nums) {
       unordered_map<int,int>mp,t;
       for(auto i:nums) mp[i]++;
       long ans=0;
       int mod=1e9+7;
       for(auto i:nums){
          mp[i]--;
           ans=(ans+(1LL*mp[i*2]*t[i*2]))%mod;

          t[i]++;
       }
       return ans;

    }
};


// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         unordered_map<int,int>mpi,mpj;
//         int ans=0;
//         int mod=1e9+7;
//         for(auto i:nums){
//             if(i%2==0){
//                 ans=(ans+(1LL*mpj[i/2]))%mod;
//             }
//             mpj[i]=(mpj[i]+mpi[i*2])%mod;
//             mpi[i]++;
//         }


//         return ans;
//     }
// };