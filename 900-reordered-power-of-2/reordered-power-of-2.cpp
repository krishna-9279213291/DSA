class Solution {
public:
    vector<int> countDigits(int n) {
        vector<int> freq(10, 0);

        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }

        return freq;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> target = countDigits(n);

        // Powers of 2 having at most 10 digits
        for (int power = 1; power <= 1000000000; power *= 2) {
            
            if (countDigits(power) == target) {
                return true;
            }
        }

        return false;
    }
};