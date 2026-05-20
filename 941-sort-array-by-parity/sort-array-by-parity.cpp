class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            // left odd and right even
            if (nums[left] % 2 > nums[right] % 2) {
                swap(nums[left], nums[right]);
            }

            // move left if even
            if (nums[left] % 2 == 0) {
                left++;
            }

            // move right if odd
            if (nums[right] % 2 == 1) {
                right--;
            }
        }

        return nums;
    }
};