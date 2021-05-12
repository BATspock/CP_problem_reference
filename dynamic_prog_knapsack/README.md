# Knapsack problems

The term knapsack refers to problems where a set of objects is given, and subsets with some properties have to be found.

Given a list of weights [w1,w2,...,wn], determine all sums that can be constructed using the weights.


To solve the problem, we focus on subproblems where we only use the first k
weights to construct sums. Let possible(x,k) = true if we can construct a sum x
using the first k weights, and otherwise possible(x,k) = false. The values of the
function can be recursively calculated as follows:
possible(x,k) = possible(x-w(k),k-1) union possible(x,k-1)

The formula is based on the fact that we can either use or not use the weight wk
in the sum. If we use wk, the remaining task is to form the sum x-wk using the
first k-1 weights, and if we do not use wk, the remaining task is to form the sum
x using the first k-1 weights.
