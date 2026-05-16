class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.count("0000")) return -1;
        queue<string>q;
        q.push("0000");
        int level =0;
        // vector<int>v = nextpossiblenumbers("0000");
        unordered_map<string, bool>vis;
        vis["0000"] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
            string curr = q.front();
            q.pop();
            vector<string>v = nextpossiblenumbers(curr);
            for(int i = 0;i<v.size();i++){
                if(v[i]==target){
                    return level+1;
                }
                else if(!visit.count(v[i]) && !vis[v[i]]){
                    vis[v[i]] = true;
                    q.push(v[i]);
                }
            }
        }
        level++;
    }
        return -1;
    }
    vector<string>nextpossiblenumbers(string s){
        vector<string>res;
        for(int i =0;i<4;i++){
            string copy = s;
            //down
            copy[i]= (s[i]=='9'?'0':s[i]+1) ;
            res.push_back(copy);
            //up
            copy[i]= (s[i]=='0'?'9':s[i]-1);
            res.push_back(copy);
        }
        return res;
    }
};