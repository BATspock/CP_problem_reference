a = [-1,-1,-1, 0,0,0,1]
b = [-1, 0, 1,-1,0,1,0]
import math
def isRect(a, b) -> int :
    distance = dict()
    points = [[x,y] for x, y in zip(a,b)]
#     print(points)
    for i in range(len(points)):
        for j in range(i+1, len(points)):
#             print(points[i][0], points[i][1], points[j][0],  points[j][1])
            d = math.sqrt((points[i][0] - points[j][0])**2 + (points[i][1] - points[j][1])**2)
            if d in distance:
                distance[d].append([points[i], points[j]])
            else:
                distance[d] = list([[points[i], points[j]]])
    count =0 
    c = set()
    for d in distance:
        coord = distance[d]
        for i in range(len(coord)):
            for j in range(i+1, len(coord)):
                com_x = (coord[i][0][0] + coord[i][1][0] + coord[j][0][0] + coord[j][1][0]) /4.0
                com_y = (coord[i][0][1] + coord[i][1][1] + coord[j][0][1] + coord[j][1][1]) /4.0
                
                dd1=math.sqrt((com_x - coord[i][0][0])**2+(com_y-coord[i][0][1])**2)
                dd2=math.sqrt((com_x - coord[i][1][0])**2+(com_y-coord[i][1][1])**2)
                dd3=math.sqrt((com_x - coord[j][0][0])**2+(com_y-coord[j][0][1])**2)
                dd4=math.sqrt((com_x - coord[j][1][0])**2+(com_y-coord[j][1][1])**2)
                if (dd1==dd2 and dd1==dd3 and dd1==dd4):
                    temp = list()
                    temp.append([coord[i][0][0],coord[i][0][1]])
                    temp.append([coord[i][1][0],coord[i][1][1]])
                    temp.append([coord[j][0][0],coord[j][0][1]])
                    temp.append([coord[j][1][0], coord[j][1][1]])
#                     x1, x2, x3, x4 = tuple(temp[0]), tuple(temp[1]), tuple(temp[2]), tuple(temp[3])
#                     print(x1, x2, x3, x4)
                    temp = sorted(temp)
                    final_cord = tuple(tuple(i) for i in temp)
                    print(final_cord)
                    prev = len(c)
                    c.add(final_cord)
                    if len(c) > prev:
                        
                        print('$$$$$$')
                        count+=1
    print(count)

    
isRect(a,b)
