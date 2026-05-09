class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>res;
        for(int i =0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                s.push(asteroids[i]);
            }
            else {
                   if(s.empty() || s.top()<0){
                    s.push(asteroids[i]);
                   } 
                   else {
                    bool needinsert = true;
                    while(!s.empty() && s.top()>0){
                        if(abs(asteroids[i])== abs(s.top())){
                            s.pop();
                            needinsert =  false;
                            break;
                        }
                        else if(abs(asteroids[i])> abs(s.top())) {
                            needinsert = true;
                            s.pop();
                        }
                        else {
                             needinsert =false;
                            break;
                        }
                    }
                    if(needinsert){
                         s.push(asteroids[i]);
                    }
                   }
            }
        }
        while(!s.empty()){
            int x = s.top();
            s.pop();
            res.push_back(x);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};