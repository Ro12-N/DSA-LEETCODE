class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n=numberOfUsers;
        vector<int>ans(n,0);
        vector<int>timestamp(n,0);
        sort(events.begin(),events.end(),[](vector<string>&a,vector<string>&b){

             int t1=stoi(a[1]);
             int t2=stoi(b[1]);
             if(t1==t2){
                 return a[0][1]>b[0][1];
             }
             return t1<t2;

        });
        for(auto e:events){
            string s=e[0];
            int t=stoi(e[1]);
            string p=e[2];
            if(s=="OFFLINE"){
                int id=stoi(p);
              timestamp[id]=t+60;
            }else{

                if(p=="ALL"){
                    for(int i=0;i<n;i++){
                        ans[i]++;
                    }
                }
                else if(p=="HERE"){
                    for(int i=0;i<n;i++){
                        if(t>=timestamp[i])
                           ans[i]++;
                    }
                }
                else{
                stringstream iss(p);
                string word="";
                while(iss>>word){
                    int id=stoi(word.substr(2));
                     ans[id]++;
                 }
                }
            }
        }
        return ans;
    }
};