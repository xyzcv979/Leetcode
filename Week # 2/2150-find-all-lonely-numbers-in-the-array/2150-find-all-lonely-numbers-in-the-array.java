class Solution {
    public List<Integer> findLonely(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        List<Integer> lonelyNums = new ArrayList<>();
        for(int i : nums){
            map.put(i, map.getOrDefault(i,0) + 1);
        }
        for(int i : map.keySet()){
            if(!map.containsKey(i - 1) && !map.containsKey(i + 1) && map.get(i) == 1)
                lonelyNums.add(i);
        }
        return lonelyNums;
    }
}