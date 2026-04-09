class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++) {
            m[s[i]]++;
            m[t[i]]--;
        }
        // for(int i=0;i<t.size();i++) {
            
        // }
        for(auto x:m){
            if(x.second>0){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<bool>visited(strs.size(), false);
        vector<vector<string>>ans;
        for(int i =0;i<strs.size();i++){
            if(visited[i]==false){
                string si = strs[i];
                vector<string>inner;
                for(int j =i+1; j<strs.size();j++){
                    if(visited[j]==false){
                        string sj = strs[j];
                           if( isAnagram(si, sj) == true){
                                visited[j]=true;
                                inner.push_back(sj);
                           }
                    }
                }
                inner.push_back(si);
                ans.push_back(inner);
                visited[i]=true;
            }
        }
        return ans;
    }
};
