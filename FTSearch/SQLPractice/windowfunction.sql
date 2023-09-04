SELECT distinct dept.department_id, dept.department_name, avg(emp.salary) over (partition by dept.department_id ) as Average_salary
from employees emp
inner join departments dept
on emp.department_id = dept.department_id
order by dept.department_id
