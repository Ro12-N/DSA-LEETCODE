class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1) {
            arr[0]=1;
        }
        int ans=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]>1){
                arr[i]=arr[i-1]+1;
            }
            ans=max(ans,arr[i]);
        }
        return ans;
    }
};
// TC : O(nlogn) since we are sorting the array
// SC : O(1) since we are using constant space