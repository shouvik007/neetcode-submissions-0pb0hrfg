class Solution {
public:
    bool checkValidString(string s) {
        stack<int>so;
        stack<int>ss;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(') {
                so.push(i);
            }
            else if(s[i]=='*'){
                ss.push(i);
            }
            else {
                if(!so.empty()){
                    so.pop();
                }
                else if(!ss.empty()) {
                    ss.pop();
                }
                else {
                    return false;
                }
            }
        }
        while(!so.empty()){
            if(ss.empty()){
                return false;
            }
            if(so.top()<ss.top()){
                so.pop();
                ss.pop();
            }
            else {
                return false;
            }
        }
        return true;
    }
};
