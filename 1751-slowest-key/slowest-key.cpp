class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        
        // First key duration
        int maxDuration = releaseTimes[0];
        char ans = keysPressed[0];

        // Check remaining keys
        for (int i = 1; i < releaseTimes.size(); i++) {
            
            int duration = releaseTimes[i] - releaseTimes[i - 1];

            // If larger duration found
            if (duration > maxDuration) {
                maxDuration = duration;
                ans = keysPressed[i];
            }

            // If same duration, take lexicographically larger character
            else if (duration == maxDuration && keysPressed[i] > ans) {
                ans = keysPressed[i];
            }
        }

        return ans;
    }
};