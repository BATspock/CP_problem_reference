#write a function to blur a black and white image containing values from 0 to 255
# we also have a non negative integer radius
# a pixel (k,l) is a neighbor of (i,j) if and only if |k-i| <=radius and |l-j| <= radius
#for each pixel (i,j), the blurred value is value of the pixel (i,j) plus the mean of the negihbors pixels divide by 2

def blur_image(image, radius):
    #create a new image
    new_image = []
    #for each pixel in the image
    for i in range(len(image)):
        new_image.append([])
        #print(new_image)
        for j in range(len(image[i])):
            #get the neighbors
            neighbors = get_neighbors(image, i, j, radius)
            #compute the mean of the neighbors
            #print(neighbors)
            #if no neighbors, the blurred value is the value of the pixel
            if len(neighbors) == 0:
                new_image[i].append(image[i][j])
            else:
                #the blurred value is value of the pixel (i,j) plus the mean of the negihbors pixels divide by 2
                new_image[i].append(int((image[i][j] + sum(neighbors) / len(neighbors)) // 2))
           
    return new_image

def get_neighbors(image, i, j, radius):
    #create a list to store intensity values of the neighbors
    neighbors = []
    #for each pixel in the image ,check neighbors of (i,j)
    #a pixel (k,l) is a neighbor of (i,j) if and only if |k-i| <=radius and |l-j| <= radius
    #same (i,j) pixel cannot exist in the neighbors
    #start from extreme left of (i,j) and go to extreme right of (i,j)
    #start from extreme top of (i,j) and go to extreme bottom of (i,j)
    for k in range(i - radius, i + radius + 1):
        for l in range(j - radius, j + radius + 1):
            #check if the pixel is inside the image
            if k >= 0 and k < len(image) and l >= 0 and l < len(image[k]) and (k != i or l != j):
                #add the pixel to the neighbors
                neighbors.append(image[k][l])
    return neighbors
    
#test
image = [[9,6],[3,0]]
radius = 1

image1 = [[0,0,0],[0,255,0],[0,0,0]]
radius1 = 2

image2 = [[255]]
radius2 = 1
print(blur_image(image, radius))
print(blur_image(image1, radius1))
print(blur_image(image2, radius2))

