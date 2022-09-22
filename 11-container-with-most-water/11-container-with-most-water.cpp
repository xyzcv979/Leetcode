class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxA = 0;
        
        while(left < right) {
            int rHeight = height[right];
            int lHeight = height[left];
            
            maxA = max(maxA, min(rHeight, lHeight) * (right-left));
            if(rHeight > lHeight) {
                left++;
            } else {
                right--;
            }
        }
        return maxA;
    }
};