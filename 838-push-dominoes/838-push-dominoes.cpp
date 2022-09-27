class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int left = 0, right = 0;
        
        while(right < n) {
            // case 1. skip '.'
            if(dominoes[right] == '.') {
                right++;
                continue;
            } else if((dominoes[right] == dominoes[left]) || (dominoes[left] == '.' && dominoes[right] == 'L')) {
                // case 2. both ends equal, set everything in middle equal
                for(int k = left; k < right; k++) {
                    dominoes[k] = dominoes[right];
                }
            } else if(dominoes[left] == 'L' && dominoes[right] == 'R') {
                // Case 3. L...R do nothing
            } else if (dominoes[left] == 'R' && dominoes[right] == 'L') {
                // Case 4. left end is R, right end is L
                //  R...L -> RR.LL
                int mid = (right-left-1)/2;
                for(int k = 1; k <= mid; k++) {
                    dominoes[right-k] = 'L';
                    dominoes[left + k] = 'R';
                }
            }
            left = right;
            right++;
        }
        // case 5. if the left dominoe is `R`, then fill all 'R' till the end
        // e.g. LL.R. -> LL.RR
        if (dominoes[left] == 'R') {
            for (int k = left; k < n; k++) 
                dominoes[k] = 'R';
        }
        return dominoes;
    }
};

/*
union find

L L R R
represents two diff groups

R R . L L 
. is in both R and L groups so this stays up

R . . . L
should be R R . L L

loop once for Rights. Loop again for Lefts

*/
