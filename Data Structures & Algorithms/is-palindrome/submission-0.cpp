class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        string val = "";
        for(int i =0;i<s.size();i++){
            if(isalnum((unsigned char)s[i])){
                val += tolower((unsigned char)s[i]);
            }
            
        }
        int h  = val.size()-1;
        while(l<=h){
            if(val[l]!=val[h]) {
                return false;
            }
            l++;h--;
        }
        return true;
    }
};
