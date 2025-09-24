class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream a(version1);
        stringstream b(version2);
        vector<int>p,q;
        string word="";
        while(getline(a,word,'.')){
            p.push_back(stoi(word));
        }
        word="";
         while(getline(b,word,'.')){
            q.push_back(stoi(word));
        }
        int maxi=max(p.size(),q.size());
        while(p.size()<maxi || q.size()<maxi){
            if(p.size()<maxi) p.push_back(0);
            if(q.size()<maxi) q.push_back(0);
        }
        for(int i=0;i<maxi;i++){
            if(p[i]>q[i]) return 1;
            else if(p[i]<q[i]) return -1;
        }


        return 0;
    }
};