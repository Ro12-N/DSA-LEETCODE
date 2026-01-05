class Solution {
public:
int solve(int num){
    int cnt=0;
    int sum=0;
    for(int f=1;f*f<=num;f++){
        if(num%f==0){
            int other=num/f;
            if(other==f){
                cnt++;
                sum+=f;
            }else{
                cnt+=2;
                sum+=(f+other);
            }
        }
        if(cnt>4) return 0;
    }


    return cnt==4?sum:0;
}
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto i:nums){
            ans+=solve(i);
        }
        return ans;
    }
};
// Time Complexity: O(N*sqrt(M)) where N is the size of nums and M is the maximum number in nums
// Space Complexity: O(1)
