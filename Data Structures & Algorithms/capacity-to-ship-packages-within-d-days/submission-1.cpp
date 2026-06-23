class Solution {
public:
    int isDay(vector<int>& weights, int maxcapacity) {
        int count = 1;
        int l =0;
        int r = weights.size();
        int curr =0;
        while(l<r){
            if(curr+weights[l]>maxcapacity){
                count++;
                curr = weights[l];
            }
            else {
                curr = curr+weights[l];
            }
            l++;
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = 0;
        int n = weights.size();
        int sum = 0;
        for(int i =0;i<n;i++) {
            maxi = max(weights[i], maxi);
            sum = sum+weights[i];
        }
        int ans = maxi;
        while(maxi<=sum) {
            int mid = (maxi+sum)/2;
            int count= isDay(weights, mid);
             if(count <= days){
                ans = mid;
                sum = mid-1;
            }
            else {
                maxi = mid+1;
            }
        }
        return ans;
    }
};