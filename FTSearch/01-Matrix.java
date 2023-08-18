
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;

        Queue<int[]> q = new ArrayDeque<>();
        int[][] directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for (int i =0;i<rows;i++){
            for (int j =0;j<cols;j++){
                if (mat[i][j] == 0){
                    q.add(new int[]{i, j});
                }
                else {
                    mat[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        // apply BFS
        while(!q.isEmpty()){
            int[] cur = q.poll();
            int row = cur[0];
            int col = cur[1];

            for(int[] dir: directions){
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >=0 && newRow < rows && newCol>=0 && newCol<cols && mat[newRow][newCol] > mat[row][col] + 1 ){
                    mat[newRow][newCol] = mat[row][col] + 1;
                    q.add(new int[]{newRow, newCol});
                }
            }
        }
        return mat;
    }
}
