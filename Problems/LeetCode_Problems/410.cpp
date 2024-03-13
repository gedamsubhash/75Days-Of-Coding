class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int i=0, j=0;
        for(int x=0; x<nums.size(); x++){
            i = (i>nums[x]) ? i : nums[x];
            j+=nums[x];
        }
        while(i<j){
            int mid=i+(j-i)/2;
            int sum=0, peices=1;
            for(auto n:nums){
                if(sum+n>mid){
                    sum=n;
                    peices++;
                }else{
                    sum+=n;
                }
            }
            if(peices>k){
                i=mid+1;
            }else{
                j=mid;
            }
        }
        return i;
    }
};