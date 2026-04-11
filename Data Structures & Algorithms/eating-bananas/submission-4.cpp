    class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int n =piles.size();
            int m = 0;
            
            for(int i =0;i<n;i++){
                m = max(piles[i],m);
            }
            if(h<piles.size()){
                return -1;
            }
            else if(h==piles.size()){
                return m;
            }
            int l =1;
            int r = m;
            int ans =m ;
            while(l<=r){
                int mid = (l+r)/2;
                int t =0;
                for(int j =0;j<n;j++){
                    if(piles[j]<mid){
                        t++;
                    }
                    else {
                        if(piles[j]%mid != 0)
                            t = t +(piles[j]/mid)+1;
                        else
                            t = t +(piles[j]/mid);
                    }
                }
                if(t>h) {
                    l = mid+1;
                }
                else {
                    ans =mid;
                    r= mid-1;
                }
            }
            return ans;
        }
    };
