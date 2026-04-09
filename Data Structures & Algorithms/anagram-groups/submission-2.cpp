class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
          unordered_map<string, vector<string>> res;
        for(auto &s : str) {
            vector<int>count(26,0);
            for(auto &c :s){
                count[(c-'a')]++;
            }
            string key = "";
            for(int i =0;i<26;i++){
                key= key+ (char)('a'+i);
                key = key + to_string(count[i]);
            }
            res[key].push_back(s);
        }
         vector<vector<string>> ans;
         for(auto key : res) {
            ans.push_back(key.second);
         }
         return ans;
    }
};
