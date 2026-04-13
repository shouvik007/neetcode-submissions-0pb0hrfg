class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        stack<string>s2;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="/"&&tokens[i]!="*"){
                s.push(stoi(tokens[i]));
            }
            else {
                
            int x=0;
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                string op = tokens[i];
            if(op=="-"){
                x = b-a;
            }
            else if(op=="+"){
                x= b+a;
            }
            else if(op=="/"){
                x=b/a;
            }
            else if(op=="*"){
                x= a*b;
            }
            s.push(x);
            }
        }
        return s.top();
    }
};
