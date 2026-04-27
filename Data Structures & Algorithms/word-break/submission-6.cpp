class Solution {
public:

    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>m;
        for(auto x:wordDict){
            m[x]++;
        }
        if(s.length()<1){
            return false;
        }
        if(s.length()==1){
            if(m[s]==1){
                return true;
            }
            else {
                return false;
            }
        }
        vector<int>v(s.size(),0);
        return search(0,0,s,m,v);
    }
    bool search(int i , int j ,string& s, unordered_map<string, int>& m, vector<int>& v) {
        if (i == s.size()) return true; 
        if (j == s.size()) return false;
        string st = s.substr(i, j-i+1);
        if(v[i]!=0 && j ==i){
            return (v[i]==1);
        }
        if(m.find(st)!=m.end()){
            if(search(j+1,j+1, s, m,v)) {
                v[i]=1;
                return true;
            }
        }
        if (search(i,j+1, s, m,v)){
            return true;        
        };
        if(j==i){
            v[i]=-1;
        }
        return false;
    }
};
