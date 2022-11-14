#return a numbers reprepresnation in base 4

import numpy as np
import math

def base4(n):
    return np.base_repr(n, base=4)


# def fucntion(num):
#     numbers = []
#     var =0
#     for i in range(1,num):
#         #if represntation of number in base 4 conatins only 0 and 1, print the number
#         if base4(i).count('2') == 0 and base4(i).count('3') == 0:
#             var+=1
#             numbers.append(i)
#     return var, numbers

# total, numbers = fucntion(10000)
#print(numbers)
#plot the numbers on the numbers line 
# import matplotlib.pyplot as plt

# plot_numbers = [math.log(x,4) for x in numbers]
# plt.plot(plot_numbers, np.zeros(len(numbers)), 'x')
# plt.show()


def final_function(num):
    #get powers of 4 less than the number

    powers = [4**x for x in range(0, int(math.log(num,4)))]

    #for the numbers in powers, check base 4 representation of the numbers until the number is greater than the number
    #keep track of the last number that satisfies the condition
    temp =1
    for i in powers:
        for j in range(i,i+temp):
            if base4(j).count('2') == 0 and base4(j).count('3') == 0 and j < num:
                print(j)
                temp = j

print(final_function(1000))