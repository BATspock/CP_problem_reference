consider the following problem: We are given the prices of k
products over n days, and we want to buy each product exactly once. However,
we are allowed to buy at most one product in a day. 

Let price[x][d] denote the price of product x on day d.Let total(S,d) denote the minimum total
price for buying a subset S of products by day d. Using this function, the solution
to the problem is total({0...k-1},n-1).
First, total(phi, d) = 0, because it does not cost anything to buy an empty set,
and total({x},0) = price[x][0], because there is one way to buy one product on
the first day.

Then, the following recurrence can be used:
total(S,d) = min(total(S,d-1),min xbelongsS(total(S \ x,d-1)+price[x][d]))

This means that we either do not buy any product on day d or buy a product x
that belongs to S. In the latter case, we remove x from S and add the price of x
to the total price.
