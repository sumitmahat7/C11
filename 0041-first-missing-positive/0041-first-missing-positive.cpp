class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Replace invalid numbers with n + 1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Mark existing numbers
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);

            if (num > n)
                continue;

            if (nums[num - 1] > 0)
                nums[num - 1] = -nums[num - 1];
        }

        // Find the first positive index
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        return n + 1;
    }
};