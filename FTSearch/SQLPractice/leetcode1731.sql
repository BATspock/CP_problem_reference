select E1.employee_id, E1.name, count(E2.name) as reports_count, round(avg(E2.age)) as average_age
from Employees E1
join Employees E2
on E1.employee_id = E2.reports_to
group by E1.employee_id
having count(E2.name) >= 1
order by E1.employee_id;
