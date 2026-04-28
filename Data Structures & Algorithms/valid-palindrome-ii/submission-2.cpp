class Solution {
public:
    bool ispalindrome(string s){
        int l = 0;
        int h = s.size()-1;
        while(l<=h){
            if(s[l]==s[h]){
                l++;h--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l =0;
        int h = s.size()-1;
        int count = 0;
        while(l<=h){
            if(s[l]==s[h]){
                l++;h--;
            }
            else {
                return ispalindrome(s.substr(l+1, (h-l)))||
                        ispalindrome(s.substr(l, (h-l)));
            }
        }
        return true;
    }
};