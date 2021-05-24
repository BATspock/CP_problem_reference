# Counting Subgrids

Given an n x n grid whose each square is either black (1) or white (0), calculate the number of subgrids
whose all corners are black.

There is an O(n^3) time algorithm for solving the problem: go through all
O(n^2) pairs of rows and for each pair (a,b) calculate the number of columns that
contain a black square in both rows in O(n) time.
