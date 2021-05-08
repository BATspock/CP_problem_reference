Given a set of coin values coins = {c1, c2,..., ck} and a target sum of money n, our task is to form the sum n using as few coins as possible.

# Recursive Formulation

The idea in dynamic programming is to formulate the problem recursively so
that the solution to the problem can be calculated from solutions to smaller
subproblems. In the coin problem, a natural recursive problem is as follows: what
is the smallest number of coins required to form a sum x?

# Memorization

The idea of dynamic programming is to use memoization to efficiently calculate
values of a recursive function. This means that the values of the function are
stored in an array after calculating them. For each parameter, the value of the
function is calculated recursively only once, and after this, the value can be
directly retrieved from the array.

# Counting the number of solutions

Let us now consider another version of the coin problem where our task is to
calculate the total number of ways to produce a sum x using the coins.


Often the number of solutions is so large that it is not required to calculate the
exact number but it is enough to give the answer modulo m where, for example,
m = 10^9+7. This can be done by changing the code so that all calculations are
done modulo m
