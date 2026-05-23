class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // agar mid wala character target se bada hai
            if (letters[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // agar target se bada character nahi mila
        // to first character return kar do
        return letters[left % letters.size()];
    }
};