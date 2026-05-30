class Solution {
public:
    int averageValue(vector<int>& nums) {
        
        int sum = 0;
        int count = 0;

        for(int num : nums) {
            
            // even and divisible by 3
            if(num % 6 == 0) {
                sum += num;
                count++;
            }
        }

        // if no such number exists
        if(count == 0)
            return 0;

        return sum / count;
    }
};