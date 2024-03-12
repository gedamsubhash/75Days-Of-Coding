class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int totalMax=INT_MIN, tempMax=0;
        for(int i=0; i<nums.size(); i++){
            tempMax+=nums[i];
            if(totalMax<tempMax)
                totalMax=tempMax;
            if(tempMax<0)
                tempMax=0;
        }
        return totalMax;
    }
};