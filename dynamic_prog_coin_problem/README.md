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


