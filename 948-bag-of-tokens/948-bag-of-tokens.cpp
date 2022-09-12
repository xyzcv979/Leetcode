class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxScore = 0;
        int score = 0;
        int left = 0, right = tokens.size()-1;
        
        sort(tokens.begin(), tokens.end());
        
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