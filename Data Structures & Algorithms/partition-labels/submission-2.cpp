class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>res;
        int n = s.size();
        unordered_map<char, pair<int,int>> m;
        for(int i =0;i<n;i++){
            if(m.find(s[i])== m.end()){
                m[s[i]]={i,i};
            }
            else {
                m[s[i]].second =i;
            }
        }
        vector<pair<int,int>>v;
        for(auto x:m){
            v.push_back(x.second);
        }
        sort(v.begin(), v.end());
        int l = v[0].first;
        int r = v[0].second;
        for(int i =1;i<v.size();i++){
            int l2 = v[i].first;
            int r2 = v[i].second;
            if(r>=l2){
                r = max(r,r2);
            }
            else {
                res.push_back(r-l+1);
                l = l2;
                r = r2;
            }
        }
        res.push_back(r-l+1);
        return res;
    }
};
