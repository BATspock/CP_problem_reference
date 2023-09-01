Problem Statement:

Write a SQL query to find all the details of those employees who earn the third-highest salary.

Return all the columns from the employees table.
Follow-Up: Avoid using LIMIT keyword in the query.

-- select *
-- from employees 
-- where salary = (
--    select DISTINCT salary 
--    from employees
--    order by salary desc 
--    limit 1 OFFSET 2
-- )


WITH ranked_salaries AS (
  SELECT *, DENSE_RANK() OVER (ORDER BY salary DESC) salary_rank
  FROM employees  
)

SELECT * EXCEPT (salary_rank)
FROM ranked_salaries
WHERE salary_rank = 3
