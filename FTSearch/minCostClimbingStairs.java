class Solution {
    public int minCostClimbingStairs(int[] cost) {

        if (cost.length == 2){
            return Math.min(cost[0], cost[1]);
        }

        int[] opt = new int[cost.length];

        opt[0] = 0;
        opt[1] = 0;
        opt[2] = Math.min(cost[0], cost[1]);
        
        for (int i =3; i < opt.length; i++){
            opt[i] = Math.min(opt[i-1] + cost[i-1], cost[i-2]+opt[i-2]);
        }

        return Math.min(opt[cost.length-1]+cost[cost.length-1], opt[cost.length-2]+cost[cost.length-2]);
    }
}
