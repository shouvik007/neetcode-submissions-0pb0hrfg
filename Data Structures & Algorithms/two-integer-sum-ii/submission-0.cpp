class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>v;
        int h =numbers.size()-1;
        int l =0;
        while(l<h){
            int sum = numbers[l]+numbers[h];
            if(sum==target){
                v.push_back(l+1);
                v.push_back(h+1);
                return v;
            }
            else {
                if(sum >target){
                    h--;
                }
                 else l++;
            }

        }
        return v;
    }
};
