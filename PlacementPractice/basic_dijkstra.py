# write dijkstra algorithm to reach from a source node to a destination node with minimum cost
# the graph is represented as a list of lists
# each list contains the node the neighbor is connected to and the cost of the edge

# implement dijkstra algorithm here using prriority queue

import queue

def get_shortest_time(startNode, endNode, paths):
    
    #create adjecency list from paths

    adj_list = {}
    for path in paths:
        if path[0] in adj_list:                                                       
            adj_list[path[0]].append([path[1], int(path[2])])
        else:
            adj_list[path[0]] = [[path[1], int(path[2])]]

    #create a priority queue
    #the priority queue will contain the node and the cost to reach that node
    #the priority queue will be sorted based on the cost to reach the node
    
    q = queue.PriorityQueue()

    #add the start node to the priority queue
    q.put([0, startNode])

    
    while(not q.empty()):
        print(q.queue)
        #get the node with the minimum cost to reach
        node = q.get()
        #if the node is the destination node, return the cost to reach the node
        #if the cost of node is infinity, return -1

        if node[0] == float('inf'):
            return -1

        if node[1] == endNode:
            return node[0]
        
        elif node[1] in adj_list:
            for neighbor in adj_list[node[1]]:
                q.put([node[0] + neighbor[1], neighbor[0]])
        
        #if the node is not the destination node, add the neighbors of the node to the priority queue
        else:
            #pop the node from the queue
            q.get()

            q.put([float('inf'), node[1]])

           
                

    return -1

if __name__ == '__main__':
    #paths = [["S1", "S2", "1"], ["S2", "S3", "1"], ["S3", "S4", "1"], ["S1", "S4", "2"]]

    paths_1 = [["S1", "S2", '1'], 
["S1", "S3", '12'],
["S2", "S3", '9'],
["S2", "S4", '3'],
["S3", "S5", '5'],
["S4", "S3", '4'],
["S4", "S5", '13'],
["S4", "S6", '15'],
["S5", "S6",'4']]
# ["S4", "S5", 15],
# ["S4", "S7", 1],
# ["S4", "S8", 5],
# ["S5", "S8", 12],
# ["S6", "S7", 1],
# ["S7", "S8", 3] ]

    # paths = [['A', 'B', '10'], ['A','E','3'],['E','B', '1'], ['B','C', '2'],
    # ['E','C', '8'], ['E','D','2'], ['C', 'D', '9']]

    paths_2 = [['A', 'B', '2'], ['A','C','3'],['A','D', '4'], ['C','D', '1']]


    print(get_shortest_time('S1', 'S6', paths_1))
    print(get_shortest_time('A', 'E', paths_2))
    
    