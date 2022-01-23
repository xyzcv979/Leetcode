class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix.length == 0)
            return new ArrayList<Integer>();
        
        int m = matrix.length, n = matrix[0].length;
        int rowBegin = 0, rowEnd = m - 1;
        int colBegin = 0, colEnd = n - 1;
        List<Integer> spiralList = new ArrayList<>();
        
        while(rowBegin <= rowEnd && colBegin <= colEnd){  
            // Traverse right
            for(int i = colBegin; i<= colEnd; i++){
                spiralList.add(matrix[rowBegin][i]);     
            }
            rowBegin++;
            
            // Traverse down
            for(int i = rowBegin; i<= rowEnd; i++){
                spiralList.add(matrix[i][colEnd]);
            }    
            colEnd--;
            
            // Condition for last element 
            if(rowBegin > rowEnd || colBegin > colEnd) break;
            
            // Traverse left
            for(int i = colEnd; i >= colBegin; i--){
                spiralList.add(matrix[rowEnd][i]);
            }
            rowEnd--;
            
            // Traverse Up
            for(int i = rowEnd; i >= rowBegin; i--){
                spiralList.add(matrix[i][colBegin]);
            }
            colBegin++;

        }
        return spiralList;
    }
}