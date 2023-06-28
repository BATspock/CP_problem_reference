1075. Project Employees I


select P.project_id, ROUND(AVG(E.experience_years),2) as average_years
from Project P
inner join Employee E on P.employee_id = E.employee_id
group by P.project_id;
