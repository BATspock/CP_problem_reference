consider the following problem: We are given the prices of k
products over n days, and we want to buy each product exactly once. However,
we are allowed to buy at most one product in a day. 

Let price[x][d] denote the price of product x on day d. For example, in the
above scenario price[2][3] Æ 7. Then, let total(S,d) denote the minimum total
price for buying a subset S of products by day d. Using this function, the solution
to the problem is total({0...k¡1},n¡1).
First, total(;,d) Æ 0, because it does not cost anything to buy an empty set,
and total({x},0) Æ price[x][0], because there is one way to buy one product on
the first day.
