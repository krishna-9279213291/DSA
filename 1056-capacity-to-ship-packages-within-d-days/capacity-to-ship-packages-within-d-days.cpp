class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = 0;
        int high = 0;

        // Find minimum and maximum possible capacity
        for (int w : weights) {
            low = max(low, w);
            high += w;
        }

        // Binary Search on Capacity
        while (low < high) {
            
            int mid = low + (high - low) / 2;

            int requiredDays = 1;
            int currentWeight = 0;

            // Check how many days are needed
            for (int w : weights) {
                
                if (currentWeight + w > mid) {
                    // New day
                    requiredDays++;
                    currentWeight = 0;
                }

                currentWeight += w;
            }

            // If we can ship within given days
            if (requiredDays <= days) {
                high = mid;       // Try smaller capacity
            }
            else {
                low = mid + 1;    // Need bigger capacity
            }
        }

        return low;
    }
};