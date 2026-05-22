class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        // Step 1: First k elements ka sum nikalo
        long long sum = 0;
        
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // Maximum sum ko store karo
        long long maxSum = sum;

        // Step 2: Sliding Window use karo
        for(int i = k; i < nums.size(); i++) {
            
            // Naya element add karo
            sum += nums[i];

            // Purana element hatao
            sum -= nums[i - k];

            // Maximum sum update karo
            maxSum = max(maxSum, sum);
        }

        // Step 3: Average return karo
        return (double)maxSum / k;
    }
};