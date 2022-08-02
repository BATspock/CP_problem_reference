import sys
# import numpy as np
# import pandas as pd
# from sklearn import ...

def create_data(info, org, tar):
    exchanges = {}
    rates = {}
    data = info.split(';')
    cur_data = list()
    
    for char in data:
        
        cur1, cur2, rate = char.split(',')
        if '\n' in rate:
            rate = rate.replace('\n', '') 
        rates[str([cur1, cur2])] = float(rate)
        try:
            exchanges[cur1].append(cur2)
        except KeyError:
            exchanges[cur1] = list()
            exchanges[cur1].append(cur2)      
    
    
    if '\n' in org:
            org = org.replace('\n', '') 
    if '\n' in tar:
            tar = tar.replace('\n', '') 
    
    return exchanges, rates, org, tar 

def check_reach(adj_list, org, tar):
    queue = list()
    for cur in adj_list[org]:
        queue.append(cur)
    while(not len(queue) == 0):
        if queue[0] == tar:
            return True
        else:
            next_cur = queue.pop(0)
            if (next_cur in adj_list):
                for c in adj_list[next_cur]:
                    queue.append(c)
    return False




def find_max_path(start, end, adj_list, wts):
    queue = list()
    cur = -1
    visited = set()
    for nodes in adj_list[start]:
        val= wts[str([start,nodes])]
        queue.append((val, nodes))
    
    while(len(queue)):
        r, dest = queue.pop()
        if (dest == end):
            cur = max(cur, r)
        else:
            if (dest in adj_list):
                for temp in adj_list[dest]:
                    if temp not in visited:
                        rat = wts[str([dest, temp])]
                        queue.append((rat*r, temp))
                    
            visited.add(dest)
    return cur


def search(adj_list, wt, org, tar):
    
    if (not check_reach(adj_list, org, tar)):
        print(-1.0)
        exit()
    else:
        #print('reachable')
        print(find_max_path(org, tar, adj_list, wt))
        exit()

            
flag =0;
for line in sys.stdin:
    
    if (flag == 0):
        info = line
        flag+=1
    elif (flag == 1):
        org = line
        flag+=1
    elif (flag == 2):
        tar= line
        break;
    
adj_list, wt, org, tar = create_data(info, org, tar)
#print(wt)
search(adj_list, wt, org, tar)
