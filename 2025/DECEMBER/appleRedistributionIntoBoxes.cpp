class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int m=capacity.size();
        sort(capacity.rbegin(),capacity.rend());
        int sum=accumulate(apple.begin(),apple.end(),0);
        int i=0;
        while(sum>0&&i<m){
            int curr=min(sum,capacity[i]);
            sum-=curr;
            i++;

        }

        return i;
    }
};

// Time Complexity: O(N log N) due to sorting
// Space Complexity: O(1)