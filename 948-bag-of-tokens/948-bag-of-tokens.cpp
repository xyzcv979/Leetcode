class Solution {
public:
    int maxScore;
    int bagOfTokensScore(vector<int>& tokens, int power) {
        maxScore = 0;
        int score = 0;
        
        sort(tokens.begin(), tokens.end());
        
        int left = 0, right = tokens.size()-1;
        
        while(left <= right) {
            if(score == 0 && power == 0)
                break;
            
            int minToken = tokens[left];
            int maxToken = tokens[right];
            
            if(power >= minToken) {
                score++;
                power -= minToken;
                left++;
            } else if(score >= 1) {
                score--;
                power += maxToken;
                right--;
            } else {
                break;
            }
            
            maxScore = max(maxScore, score);
        }
        
        return maxScore;
    }
};

/*
1 2 3 4, power = 2

play 1, power = 1, score = 1
play 4, power = 5, score = 0
play 3, power = 2, score = 1
play 2, power = 0, score = 2

return max score


play minimum you can with power
play maximum you can with score

but, idea is to get max score
so can't just use up all score

use up all power if poss

*/