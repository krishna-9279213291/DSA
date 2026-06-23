class Solution {
public:

// Concept: Line Sweep Algorithm

// TC=O(N log N)
// SC=O(N)

    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;

        int maxi=0,ans=0,count=0;

        for(auto it:logs)
        {
            mp[it[0]]++;
            mp[it[1]]--;
        }


        for(auto it:mp)
        {
           int year=it.first;
           int value=it.second;

           count+=value;

           if(count>maxi){
            maxi=count;
            ans=year;
           }
        }

        return ans;
    }
};