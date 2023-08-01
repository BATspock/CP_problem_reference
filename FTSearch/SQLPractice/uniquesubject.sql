select T.teacher_id, count(DISTINCT T.subject_id) as cnt
from Teacher T
group by T.teacher_id
