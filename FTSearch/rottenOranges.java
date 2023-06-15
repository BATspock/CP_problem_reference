class Solution {
    private class Coordinate{
        private int x;
        private int y;
        private int time;

        public Coordinate(int x, int y, int time){
            this.x = x;
            this.y = y;
            this.time = time;
        }

        public int getX(){
            return this.x;
        }
        public int getY(){
            return this.y;
        }

        public int getTime(){
            return this.time;
        }
    }

    private ArrayList<Coordinate> getStartingCoordinates(int[][] grid, int row, int col){
        ArrayList<Coordinate> CoordinateList = new ArrayList<>();

        for (int i = 0; i< row; i++){
            for (int j =0;j< col; j++){
                if (grid[i][j] == 2){
                    Coordinate coord = new Coordinate(i, j,0);
                    CoordinateList.add(coord);
                }
            }
        }
        return CoordinateList;
    }

    private boolean AllZeros(int grid[][], int row, int col){
        for (int i = 0; i< row; i++){
            for (int j = 0; j< col; j++){
                if (grid[i][j] != 0){
                    return false;
                }
            }
        }
        return true;
    }

    private int AllVisited(int grid[][], int row, int col){
        for (int i = 0; i< row; i++){
            for (int j = 0; j< col; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return 1;
    }

    public int orangesRotting(int[][] grid) {
        // int[] visited = new int[grid.length*grid[0].length];
        int row = grid.length;
        int col = grid[0].length;
        int time = 0;

        Queue<Coordinate> queue = new LinkedList<>();

        ArrayList<Coordinate> startingPoints= getStartingCoordinates(grid, row, col);

        if (startingPoints.size() == 0) {
            if (AllZeros(grid, row, col)){
                return 0;
            }
            return -1;
        }

        for (int i =0; i<startingPoints.size();i++){
            Coordinate coord = startingPoints.get(i);
            queue.add(coord);
        }

        while(!queue.isEmpty()){
            Coordinate curCoord = queue.poll();

            int x = curCoord.getX();
            int y = curCoord.getY();
            time = curCoord.getTime();
            
            //check top
            if (x-1 >= 0){
                if (grid[x-1][y]==1){
                    Coordinate newCoord = new Coordinate(x-1, y, time+1);
                    grid[x-1][y] = 2;
                    queue.add(newCoord);
                }
            }
            // check bottom
            if (x+1<row){
                if (grid[x+1][y] == 1){
                    Coordinate newCoord = new Coordinate(x+1, y, time+1);
                    grid[x+1][y] = 2;
                    queue.add(newCoord);
                }
            }
            // check left
            if (y-1>=0){
                if (grid[x][y-1] == 1){
                    Coordinate newCoord = new Coordinate(x, y-1, time+1);
                    grid[x][y-1] = 2;
                    queue.add(newCoord);
                }
            }
            // check right
            if (y+1<col){
                if (grid[x][y+1] == 1){
                    Coordinate newCoord = new Coordinate(x, y+1, time+1);
                    grid[x][y+1] = 2;
                    queue.add(newCoord);
                }
            }
        }

        return AllVisited(grid, row, col)==-1?-1:time;

    }
}
