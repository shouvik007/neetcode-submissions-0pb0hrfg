class Solution {
public:
    void merge(vector<int>& nums, int l , int mid, int h){
        int n1 = mid-l+1;
        int n2 = h-mid;
        vector<int>left(n1);
        vector<int>right(n2);
        for(int i =0;i<n1;i++){
            left[i]=nums[l+i];
        }
        for(int i =0;i<n2;i++){
            right[i]=nums[mid+1+i];
        }
        int i =0;
        int k =l;
        int j =0;
        while(i<n1&&j<n2){
            if(left[i]<=right[j]){
                nums[k]=left[i];
                i++;
            }
            else {
                nums[k]=right[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<n2){
            
            nums[k]=right[j];
            k++;
            j++;
        }
    }
    void mergesort(vector<int>& nums, int l , int h){
        if(l>=h){
            return ;
        }
        int mid = (l+h)/2;
        mergesort(nums, l, mid);
        mergesort(nums, mid+1, h);
        merge(nums, l , mid, h);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int h = n-1;
        mergesort(nums, i,h);
        return nums;
    }
};