with cte1 as (
    SELECT jh.employee_id as emp_id,
            jh.job_id as job_id,
            j.job_title as job_title,
            j.min_salary as min_salary
    FROM job_history jh
    inner join jobs j
    on jh.job_id = j.job_id
    where j.min_salary >= 6000 
    and
    j.job_title like '%Sales%'
),

cte2 as (
    SELECT emp.employee_id as emp_id,
            dept.department_name as dept_name
    FROM employees emp
    inner join departments dept
    on dept.department_id = emp.department_id
)

SELECT cte2.emp_id as employee_id, 
        cte2.dept_name as department_name,
        cte1.job_id as job_id,
        cte1.job_title as job_title,
        cte1.min_salary as min_salary
        
FROM cte1
inner join cte2
on cte1.emp_id = cte2.emp_id
order by cte1.emp_id, cte1.min_salary
