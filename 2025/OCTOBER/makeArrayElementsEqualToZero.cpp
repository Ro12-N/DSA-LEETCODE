class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int tsum=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        int currsum=0;
        for(auto i:nums){
            currsum+=i;
            if(i==0){
                int val=tsum-currsum;
                if(currsum==val) ans+=2;
                else if(abs(currsum-val)==1) ans++;
            }
        }
        return ans;
    }
};

//O(n)




// class Solution {
// public:
// bool solveleft(int curr,vector<int>&nums){
//     vector<int>temp=nums;
//     int t=1;
//     while(curr>=0 && curr<nums.size()){
//          if(t){
//             if(temp[curr]==0) curr--;
//             else{
//                 temp[curr]-=1;
//                 t=1-t;
//                 curr++;
//             }
//          }else{
//              if(temp[curr]==0) curr++;
//             else{
//                 temp[curr]-=1;
//                 t=1-t;
//                 curr--;
//             }
//          }
//     }
//     int sum=accumulate(temp.begin(),temp.end(),0);
//     return sum==0;
// }
// bool solveright(int curr,vector<int>&nums){
//     vector<int>temp=nums;
//     int t=1;
//     while(curr>=0 && curr<nums.size()){
//          if(t){
//             if(temp[curr]==0) curr++;
//             else{
//                 temp[curr]-=1;
//                 t=1-t;
//                 curr--;
//             }
//          }else{
//              if(temp[curr]==0) curr--;
//             else{
//                 temp[curr]-=1;
//                 t=1-t;
//                 curr++;
//             }
//          }
//     }
//     int sum=accumulate(temp.begin(),temp.end(),0);
//     return sum==0;
// }
//     int countValidSelections(vector<int>& nums) {
//         int n=nums.size();
//         int ans=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]==0){
//                 ans+=solveleft(i,nums);
//                 ans+=solveright(i,nums);
//             }
//         }
//         return ans;
//     }
// };

// // TC:O(n^2)
// // sc:O(n)