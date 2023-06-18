/*
Leetcode 841
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
*/
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        int[] visited = new int[n];
        Arrays.fill(visited,0);
        Stack<Integer> stack = new Stack<>();
        visited[0] = 1;

        for (int i =0;i<rooms.get(0).size();i++){

                stack.push(rooms.get(0).get(i));   
        }

        while(!stack.isEmpty()){
            int top = stack.pop();
            visited[top] = 1;

            for (int i =0;i<rooms.get(top).size();i++){
                if (visited[rooms.get(top).get(i)] == 0){
                    stack.push(rooms.get(top).get(i));
                }
            }
            
        }
        
        for (int x: visited){
            if (x == 0){
                return false;
            }
        }

        return true;


    }
}
