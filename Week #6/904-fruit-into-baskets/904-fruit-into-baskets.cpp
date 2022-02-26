class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> fruitTable;
        int leftPtr = 0, rightPtr = 0;
        int maxLen = 0;
        for(; rightPtr < fruits.size(); rightPtr++){
            fruitTable[fruits[rightPtr]]++;
            while(fruitTable.size() > 2){
                fruitTable[fruits[leftPtr]]--;
                if(fruitTable[fruits[leftPtr]] == 0)
                    fruitTable.erase(fruits[leftPtr]);
                leftPtr++;
            }
            maxLen = max(maxLen, rightPtr - leftPtr + 1);
        }
        return maxLen;
    }
};