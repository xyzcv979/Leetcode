class Solution {
    public int[] rearrangeArray(int[] nums) {
        ArrayList<Integer> posNums = new ArrayList<>();
        ArrayList<Integer> negNums = new ArrayList<>();
        int[] arrangedSigns = new int[nums.length];
        for(int i : nums){
            if(i < 0)
                negNums.add(i);
            else
                posNums.add(i);
        }
        boolean isPositive = true;
        int posIndex = 0;
        int negIndex = 0;
        for(int i = 0; i < arrangedSigns.length; i++){
            if(isPositive)
                arrangedSigns[i] = posNums.get(posIndex++);
            else
                arrangedSigns[i] = negNums.get(negIndex++);
            isPositive = !isPositive;
        }
        return arrangedSigns;
    }
}

// get positive nums
// get negative nums
// create final array