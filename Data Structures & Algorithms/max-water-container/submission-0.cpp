class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = 0;
        int l =0;
        int h = heights.size()-1;
        while(l<=h){
            int curr = min(heights[l],heights[h])*(h-l);
            maxi = max(maxi,curr);
            if(heights[l]>=heights[h]){
                h--;
            }
            else {
                l++;
            }
        }
        return maxi;
    }
};
