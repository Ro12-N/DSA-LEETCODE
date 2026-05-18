class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.push(start);
        unordered_set<int>st;
        st.insert(start);
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(arr[f]==0) return true;
            int x=f+arr[f];
            if(x<arr.size()&& !st.count(x)){
                q.push(x);
                st.insert(x);
            }
            x=f-arr[f];
             if(x>=0&& !st.count(x)){
                q.push(x);
                st.insert(x);
            }

        }
        return false;
    }
};
// TC : O(n)
// SC : O(n)