class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
         if (n == 0) return 0;
        int count =0;
        vector<vector<int>>v(n,vector<int>(n,0));
        for(int i =0;i<n;i++){
            v[i][i]=1;
            count++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                v[i][i+1]=1;
                count++;
            }
        }
    
        for(int gap =2;gap<n;gap++){
            for(int i =0;i<n-gap;i++){
                int j = gap+i;
                if(s[i]==s[j]&& v[i+1][j-1]==1){
                    v[i][j]=1;
                    count++;
                }
            }
        }
        return count;
    }
};
