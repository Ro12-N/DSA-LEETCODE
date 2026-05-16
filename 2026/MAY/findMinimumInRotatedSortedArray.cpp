class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        int e=n-1;
        int Min=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[s]<=nums[e]) {
                 Min=min(Min,nums[s]);
                 break;
            }
            if(nums[s]<=nums[mid]){
                Min=min(Min,nums[s]);
                s=mid+1;
            }
            else{
                Min=min(Min,nums[mid]);
                e=mid-1;
            }
        }
        return Min;
    }
};
// TC : O(log n) where n is the number of elements in the input array. We use a binary search approach to find the minimum element, which takes logarithmic time.
// SC : O(1) since we are using only a constant amount of extra space to store variables and perform calculations. We are not using any additional data structures that grow with the input size.