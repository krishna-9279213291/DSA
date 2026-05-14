class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        // Sort array in increasing order
        sort(nums.begin(), nums.end());

        // Convert negative numbers to positive
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        // Find total sum and minimum element
        int sum = 0;
        int mini = INT_MAX;

        for (int num : nums) {
            sum += num;
            mini = min(mini, num);
        }

        // If k is still odd, negate smallest element once
        if (k % 2 == 1) {
            sum -= 2 * mini;
        }

        return sum;
    }
};