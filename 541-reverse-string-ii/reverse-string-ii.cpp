class Solution {
public:
    string reverseStr(string s, int k) {
        
        // Har 2k block ke liye loop chalega
        for (int i = 0; i < s.length(); i += 2 * k) {
            
            // reverse karne ki ending index
            int left = i;
            int right = min(i + k - 1, (int)s.length() - 1);

            // first k characters reverse karo
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};