class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxBanana = *max_element(piles.begin(), piles.end());
        
        int left = 1, right = maxBanana;
        while(left <= right) {
            int midEatingSpeed = left + (right - left) / 2;
            long int hourSpent = 0;
            
            for(int pile : piles) {
                hourSpent += pile / midEatingSpeed + (pile % midEatingSpeed != 0);
            }
            
            if(hourSpent <= h) {
                right = midEatingSpeed - 1;
            } else {
                left = midEatingSpeed + 1;
            }
        }
        return left;
    }
};

/*
choose some k to subtract from piles[i]
do this h times to eat all bannanas
want min k


brute force:
try k == 1
increment k until you eat all bananas by h

binary search:
using binary search not on sorted array elements but on the eating speed.
left = 1 banana per hour
right = max poss bananas eaten per hour which is the max of the piles array

we know that if some num k is valid, k + 1 is also valid
therefore, we know that if some k is not valid, k - 1 is also not valid


*/