// Reference https://leetcode.com/problems/pascals-triangle/discuss/38141/My-concise-solution-in-Java

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascalsTriangle = new ArrayList<>();
        List<Integer> currRow = new ArrayList<>();
        for(int row = 0; row < numRows; row++){
            currRow.add(0,1);
            for(int currRowIndex = 1; currRowIndex < row; currRowIndex++){
                currRow.set(currRowIndex, currRow.get(currRowIndex) + currRow.get(currRowIndex + 1));
            }
            pascalsTriangle.add(new ArrayList<>(currRow)); // create new object that is a copy of currRow, and add to triangle
        }
        return pascalsTriangle;
    }
}