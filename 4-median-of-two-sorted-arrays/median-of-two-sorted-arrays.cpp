class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Binary search हमेशा smaller array पर
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while (low <= high) {

            // nums1 में कितने elements left side में होंगे
            int cut1 = low + (high - low) / 2;

            // Total left elements = (m+n+1)/2
            int cut2 = (m + n + 1) / 2 - cut1;

            // Boundary handling
            int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Odd number of elements
                if ((m + n) % 2 == 1) {
                    return max(left1, left2);
                }

                // Even number of elements
                int leftMax = max(left1, left2);
                int rightMin = min(right1, right2);

                return (leftMax + rightMin) / 2.0;
            }

            // nums1 का partition बहुत right चला गया
            else if (left1 > right2) {
                high = cut1 - 1;
            }

            // nums1 का partition बहुत left है
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};