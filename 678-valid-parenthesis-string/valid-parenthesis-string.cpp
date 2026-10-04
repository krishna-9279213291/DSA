class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // minimum possible open brackets
        int high = 0;  // maximum possible open brackets

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else { // '*'
                // '*' can be ')', '(' or empty
                low--;      // assume '*' = ')'
                high++;     // assume '*' = '('
            }

            // We cannot have negative possible open brackets
            if (high < 0)
                return false;

            // Minimum cannot be negative
            low = max(low, 0);
        }

        // If zero open brackets is possible, string is valid
        return low == 0;
    }
};