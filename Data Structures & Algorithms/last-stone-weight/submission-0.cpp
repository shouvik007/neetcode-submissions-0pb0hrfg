class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       int n = stones.size();
       while(stones.size()>1){
        sort(stones.begin(),stones.end());
        int x = stones[stones.size()-1];
        int y = stones[stones.size()-2];
        int curr = x-y;
        stones.pop_back();
        stones.pop_back();
        if(curr!=0){
            stones.push_back(curr);
        }
       }
       return stones.empty() ? 0:stones[0];
    }
};
