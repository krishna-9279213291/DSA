class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        
        // Ensure start < destination
        if(start > destination)
            swap(start, destination);

        int directPath = 0;
        int totalDistance = 0;

        for(int i = 0; i < distance.size(); i++) {

            totalDistance += distance[i];

            // distance from start to destination
            if(i >= start && i < destination)
                directPath += distance[i];
        }

        // opposite direction
        int oppositePath = totalDistance - directPath;

        return min(directPath, oppositePath);
    }
};