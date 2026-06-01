class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long curr=mass;
        for(auto i:asteroids){
            if(curr<i) return false;
            curr+=i;
        }
        return true;
    }
};
// TC O(nlogn) due to sorting   
// SC O(1) if we ignore the space taken by sorting, otherwise O(n)