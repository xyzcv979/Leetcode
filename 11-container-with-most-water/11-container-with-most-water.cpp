class Solution {
public:
    int maxArea(vector<int>& height) {
        // 2 pointer
        // move ptr of shorter line
        int maxA = 0;
        int leftPtr = 0;
        int rightPtr = height.size() - 1;
        while(leftPtr < rightPtr){
            int currHeight = min(height[leftPtr], height[rightPtr]);
            int currWidth = rightPtr - leftPtr;
            int localArea = currHeight * currWidth;
            maxA = max(localArea, maxA);
            
            if(height[leftPtr] < height[rightPtr])
                leftPtr++;
            else
                rightPtr--;
            
        }
        return maxA;
    }
};