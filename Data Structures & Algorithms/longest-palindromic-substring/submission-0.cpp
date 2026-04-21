class Solution {
public:
    string longestPalindrome(string s) {
        int start =0;
        int len = 0;
        int n = s.size();
        for(int i =0;i<s.size();i++){
            int l =i, r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                if(r-l+1 > len){
                    start = l;
                    len = r-l+1;
                }
                l--;r++;
            }
             l = i; 
              r = i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                if(r-l+1 > len){
                    start = l;
                    len = r-l+1;
                }
                l--;r++;
            }
        }
        return s.substr(start, len);
    }
};
