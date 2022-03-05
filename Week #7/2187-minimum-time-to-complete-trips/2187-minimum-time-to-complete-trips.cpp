class Solution {
public:
    long long numOfTripsForGivenTime(vector<int>& time, long long givenTime){
        long long  totalTrips = 0;
        for(auto t : time){
            long long  val = t;
            totalTrips += (givenTime / val);
        }
        return totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        // binary search
        long long  minTime = 1;
        long long  maxTime = 1e14;
        while(minTime < maxTime){
            long long  mid = minTime + (maxTime - minTime)/2;
            if(numOfTripsForGivenTime(time, mid) >= totalTrips)
                maxTime = mid;
            else
                minTime = mid + 1;
           
        }
         return minTime;
    }
};

