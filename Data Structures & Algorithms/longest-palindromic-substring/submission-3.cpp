class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        int start =0;
        int len =1;
        vector<vector<bool>>v(n, vector<bool>(n,false));
        for(int i =0;i<n;i++){
            v[i][i]= true;
        }
        for(int i =0;i<n-1;i++){
            if(s[i]==s[i+1]){
                v[i][i+1]= true;
                if (len<2) {
                len = 2;
                start =i;
                }
            }
        }
        for(int gap =2;gap<n;gap++){
            for(int i =0;i<n-gap;i++){
                int j = gap +i;
                if(s[i]==s[j]&&v[i+1][j-1]){
                    v[i][j]=true;
                    if (gap + 1 > len) {
                        start = i;
                        len = gap + 1;
                    }
                }
            }
        }
    return s.substr(start, len);
    }
};
