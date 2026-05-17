class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0;
        int r = n-1;
        int count = 0;
        while(l<=r){
            if(l==r ){
                count++;
                return count;
            }
            if(people[l]+people[r] <= limit && (l!=r)){
                count++;
                l++;r--;
            }
            else {
                if(people[r] <= limit){
                    count++; 
                    r--;
                }
            }
        }
        return count;
    }
};