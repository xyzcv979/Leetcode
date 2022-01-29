class Solution {
    public int countElements(int[] nums) {
        if(nums.length < 3)
            return 0;
        Arrays.sort(nums);
        int count = 0;
        int min = nums[0];
        int max = nums[nums.length - 1];
        for(int i : nums){
            if(i > min && i < max)
                count++;
        }
        return count;
    }
}