class Solution {
class RangeSegmentTree{
private:
    int n; 
    vector<int> minVal; 
    vector<int> maxVal;
    vector<int> lazy;
    void push(int cur, int l, int r){
        if(lazy[cur] != 0){
            minVal[cur] += lazy[cur];
            maxVal[cur] += lazy[cur];
            if(l != r){
                lazy[2*cur+1] += lazy[cur];
                lazy[2*cur+2] += lazy[cur];
            }
            lazy[cur] = 0;
        }
    }
    int queryInt(int cur, int l, int r){
        push(cur, l, r);
        if(minVal[cur] > 0 || maxVal[cur] < 0) return n;
        if(l == r) return l;
        int mid = (l + r) / 2; 
        int res = queryInt(2*cur+1, l, mid);
        if(res == n) res = queryInt(2*cur+2, mid+1, r);
        return res;
    }
    void rangeAddInt(int cur, int l, int r, int ql, int qr, int val){
        push(cur, l, r);
        if(r < ql || qr < l) return;
        if(ql <= l && r <= qr){
            lazy[cur] += val;
            push(cur, l, r);
            return;
        }
        int mid = (l + r)/2;
        rangeAddInt(2*cur+1, l, mid, ql, qr, val);
        rangeAddInt(2*cur+2, mid+1, r, ql, qr, val);
        maxVal[cur] = max(maxVal[2*cur+1], maxVal[2*cur+2]);
        minVal[cur] = min(minVal[2*cur+1], minVal[2*cur+2]);
    }
    
public:
    RangeSegmentTree(int n){
        this->n = n;
        minVal.resize(4*n, 0);
        maxVal.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }
    int queryZeroIndex(){ 
        return queryInt(0, 0, n-1);
    }
    void rangeAdd(int ql, int qr, int val){
        rangeAddInt(0, 0, n-1, ql, qr, val);
    }
};
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int prev[100001]; 
        memset(prev, -1, sizeof(prev));

        int res = 0;
        RangeSegmentTree segTree(n);
        for(int i=0; i<n; ++i){
            int val = nums[i];
            segTree.rangeAdd(prev[val]+1, i, 1-2*(val%2));
            prev[val] = i;
            int minZeroInd = segTree.queryZeroIndex();
            res = max(res, i - minZeroInd + 1);
        }
        return res;
    }
};
// Time Complexity: O(n log n) where n is the number of elements in the array due to the segment tree operations.
// Space Complexity: O(n) where n is the number of elements in the array due to