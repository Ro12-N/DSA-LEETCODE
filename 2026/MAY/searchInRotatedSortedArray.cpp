class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n=nums.size();
      int s=0;
      int e=n-1;
      while(s<=e){
        int mid=(s+e)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[s]<=nums[mid]){
            if(nums[s]<=target && target<=nums[mid]){
                e=mid-1;
            }else s=mid+1;
        }else{
            if(nums[mid]<=target && target<=nums[e]){
                s=mid+1;
            }else e=mid-1;
        }
      }
      return -1;

    }
};
// TC : O(logn) where n is the size of the input array nums as we are using binary search to find the target element in the rotated sorted array
// SC : O(1) as we are using constant extra space to store the variables s