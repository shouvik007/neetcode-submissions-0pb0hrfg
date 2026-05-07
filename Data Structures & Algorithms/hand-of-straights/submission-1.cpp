class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        vector<int>val;
        map<int,int>m;
        int n1 = hand.size();
        if(n1 % groupSize != 0) return false;
        for(int i =0;i<hand.size();i++){
            m[hand[i]]++;
        }
        for(auto &x: m){
            if(x.second > 0){
                for(int j =1;j<groupSize;j++){
                    if(m[(x.first+j)]<x.second){
                        return false;
                    }
                    m[(x.first+j)]= m[(x.first+j)] - x.second;
                }
            }
        }
        return true;
    }
};
