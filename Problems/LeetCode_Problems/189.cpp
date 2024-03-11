class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>nums2;
        for(int i=0;i<n;i++)
            nums2.push_back(nums[i]);
        for(int i = 0;i < n;i++)
            nums[(i+k)%n]=nums2[i];
    }
};