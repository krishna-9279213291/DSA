class Solution {
public:
    int countDigitOne(int n) {
        long long nextDigit = 10;
        long long currentDigit = 1;
        long long globalSum = 0;

        long long div, mod;
        //iterate through every digit/sequence
        while (n >= currentDigit) {
            //number of "completed" 1-subsequences
            div = n / nextDigit;
            //last mod numbers can possibly contain last 1-subsequence
            mod = n % nextDigit;
            globalSum += div * currentDigit;
            //if this last 1-subsequence exists, it might be "completed" or not
            if (mod >= currentDigit) {
                //before this last 1-subsequence, we have (currentDigit-1) zeroes.
                //(currentDigit-1) means 9, 99, 999,...
                //(currentDigit*2-1) means 19, 199, 1999...
                globalSum += std::min(mod, currentDigit * 2 - 1) - (currentDigit - 1);
            }
            nextDigit *= 10;
            currentDigit *= 10;
        }

        return static_cast<int>(globalSum);
    }
};