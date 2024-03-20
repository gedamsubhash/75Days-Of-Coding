class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;

        int i = 0;
        while (i < nums.size()) {
            long correct = (long)nums[i] - 1; // Cast nums[i] to long before subtraction
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[correct] && correct >= 0 && correct < nums.size()) {
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            } else {
                i++;
            }
        }
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }
        return nums.size() + 1;
    }
};
