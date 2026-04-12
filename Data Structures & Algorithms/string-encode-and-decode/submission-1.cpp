class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for(int i=0;i<n;i++){
            ans =ans+to_string(strs[i].size())+"#"+strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string temp="";
        int i =0;
        while(i<s.size()){  
            int j =i;
            while(s[j]!='#') {
                j++;
            }
            int leng = stoi(s.substr(i, j-i));
            i=j+1;
            ans.push_back(s.substr(i, leng));
            i = i+leng;
        }
        return ans;
    }
};
