class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> listOfList = new ArrayList<>();
        listOfList.add(new ArrayList<Integer>(Arrays.asList(1)));
        for(int i = 1; i < numRows; i++){
            List<Integer> currRow = new ArrayList<>();
            List<Integer> prevRow = listOfList.get(i - 1);
            currRow.add(1);
            for(int j = 1; j < i; j++){
                currRow.add(prevRow.get(j) + prevRow.get(j -1));
            }
            currRow.add(1);
            listOfList.add(currRow);
        }
        return listOfList;
    }
}