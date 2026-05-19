class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(int num : nums) {
            int digits = 0;

            // count digits
            while(num > 0) {
                digits++;
                num /= 10;
            }

            // check even digits
            if(digits % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};