class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int>s;
        for(int i =0;i<n;i++) {
            if(operations[i]!="+" && operations[i]!="C" && operations[i]!="D"){
                s.push(stoi(operations[i]));
            }
            else if(operations[i]=="+"){
                int a = s.top();
                s.pop();
                int b =s.top();
                s.pop();
                s.push(b);
                s.push(a);
                s.push(a+b);
            }
            else if(operations[i]=="C"){
                s.pop();
            }
            else if(operations[i]=="D"){
                int x = s.top();
                s.push(2*x);
            }
        }
        int res =0;
        while(!s.empty()){
            res = res+s.top();
            s.pop();
        }
        return res;
    }
};