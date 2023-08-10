
with cte1 as(
    select * 
    from Students 
    CROSS JOIN Subjects
),

cte2 as (
    select student_id, subject_name, count(subject_name) as attempts
    from Examinations
    group by student_id, subject_name
)

select cte1.student_id, cte1.student_name, cte1.subject_name, case
    when cte2.attempts is not null then cte2.attempts
    else 0
    end

    as attended_exams

from cte1
left join cte2 on
cte1.student_id = cte2.student_id 
and
cte1.subject_name = cte2.subject_name
order by cte1.student_id, cte1.subject_name
